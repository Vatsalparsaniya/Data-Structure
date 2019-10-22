#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
static char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}
int main(int argc, char const* argv[]) {
    if(argc!=2) {
        printf("Usage: %s number_of_elements\n", argv[0]);
        return 0;
    }
    srand(time(NULL));
    int n = atoi(argv[1]);
    int str_len = 10;
    char** arr = malloc(n*sizeof(char*));
    for(int i = 0;i<n;i++) {
        arr[i] = malloc(str_len*sizeof(char));
    	arr[i] = rand_string(arr[i], str_len);
	}
    HashTable* h = hash_create();
    for(int i = 0;i<n;i++) {
        hash_insert(h, arr[i], rand()%100);
    }
    for(int i = 0;i<n;i++)
       printf("%d\n", *hash_lookup(h, arr[i]));

    for(int i = 0;i<n;i++) {
        free(arr[i]);
    }
    free(arr);
    hash_destroy(h);
    return 0;
}
