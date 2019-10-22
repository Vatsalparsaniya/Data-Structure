#include "hashtable.h"

struct pair {
    char * key;
    int    value;
};
struct bucket {
    struct pair** array;
    int           capacity;
    int           size;
};

struct hash_table {
    struct bucket** buckets;
    int size;
};

struct hash_table* hash_create(void) {
    struct hash_table* h = malloc(sizeof(struct hash_table));
    h->size = 8;
    h->buckets = malloc(sizeof(struct bucket*)*h->size);
    for(int i = 0;i < h->size;i++) {
        h->buckets[i] = malloc(sizeof(struct bucket));
        h->buckets[i]->capacity = BUCKET_SIZE;
        h->buckets[i]->size = 0;
        h->buckets[i]->array = malloc(sizeof(struct pair*)*h->buckets[i]->capacity);
    }

    return h;
}
void hash_destroy(struct hash_table *tab) {
    for(int i = 0;i < tab->size;i++) {
        for(int j = 0;j < tab->buckets[i]->size;j++) {
            free(tab->buckets[i]->array[j]->key);
            free(tab->buckets[i]->array[j]);
        }
        free(tab->buckets[i]->array);
        free(tab->buckets[i]);
    }
    free(tab->buckets);
    free(tab);
}

static int hash(const char* value) {
    int c = 0, hash = 1;
    while(value[c] != 0) {
        hash += value[c];
        hash *= value[c];
        c++;
    }
    if(hash < 0)
        hash *= -1;

    return hash;
}
static struct pair* new_pair(const char* key, int value) {
    struct pair* p = malloc(sizeof(struct pair));
    p->key = malloc((strlen(key)+1)*sizeof(char));
    strncpy(p->key, key, strlen(key)+1);
    p->value = value;
    return p;
}

static int bucket_insert(struct bucket* bucket, struct pair* pair) {
    if(bucket->size + 1 > bucket->capacity) {
        bucket->capacity *= 2;
        bucket->array = realloc(bucket->array, bucket->capacity*sizeof(struct pair*));
        if(bucket->array == NULL) 
            return 0;
    }
    for(int i = 0;i < bucket->size;i++) {
        if(strcmp(bucket->array[i]->key, pair->key) == 0) {
            bucket->array[i]->value = pair->value;
            return 1;
        }
    }
    bucket->array[bucket->size++] = pair;
    return 1;
}

void hash_insert(struct hash_table *tab, const char* key, int value) {
    int index = hash(key) % tab->size;
    struct bucket* b = tab->buckets[index];
    struct pair* p = new_pair(key, value);
    int status = bucket_insert(b, p);
    if(!status)
        return; //Handle this?

}
int* hash_lookup(struct hash_table *tab, const char* key) {
    int index = hash(key) % tab->size;
    struct bucket* b = tab->buckets[index];
    for(int i = 0;i < b->size;i++) {
        if(strcmp(b->array[i]->key, key) == 0) {
            struct pair* temp = b->array[i];
            b->array[i] = b->array[0];
            b->array[0] = temp;
            return &(b->array[0]->value);
        }
    }
    return NULL;
}
size_t hash_as_array(HashTable *tab, char ***keys, int **values) {
    int n = 0;
    for(int i = 0;i<tab->size;i++)
        n += tab->buckets[i]->size;
    *values = malloc(n*sizeof(int*));
    *keys = malloc(n*sizeof(char**));
    
    int ind = 0;
    for (int i = 0; i < tab->size; ++i) {
        struct bucket* bucket = tab->buckets[i];
        for(int j = 0; j < bucket->size;j++) {
            (*keys)[ind] = bucket->array[j]->key;
            (*values)[ind] = bucket->array[j]->value;
            ind++;
        }
    }
    return n;
}
