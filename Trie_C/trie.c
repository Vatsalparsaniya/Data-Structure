#include "trie.h"

struct trie_node * init_trie_node() {
    int i;
    struct trie_node * trie = (struct trie_node *)malloc(sizeof(struct trie_node));

    if (trie == NULL) {
        perror("Unable to allocate memory\n");
        exit(-1);
    }

    trie->data = 0;

    for (i = 0; i < ALPHABET_LEN; i++) {
        trie->next[i] = NULL;
    }

    return trie;
};

void destroy_trie(struct trie_node * trie) {
    int i;

    if (trie == NULL) {
        return;
    }

    for (i = 0; i < ALPHABET_LEN; i++) {
        if (trie->next[i] != NULL) {
            destroy_trie(trie->next[i]);
        }
    }

    free(trie);
}

int get_trie_index(char c) {
    return (c - 'a');
}


void insert_trie(struct trie_node * trie, char * str) {
    if (trie == NULL) {
        return;
    }

    int i;
    int len = strlen(str);
    struct trie_node * node = trie;

    for (i = 0; i < len - 1; i++) {
        if (node->next[get_trie_index(str[i])] == NULL) {
            node->next[get_trie_index(str[i])] = init_trie_node();
        }

        node = node->next[get_trie_index(str[i])];
    }

    if (node->next[get_trie_index(str[len - 1])] == NULL) {
        node->next[get_trie_index(str[len - 1])] = init_trie_node();
    }

    node->next[get_trie_index(str[len - 1])]->data++;
}

void print_trie(struct trie_node * trie) {
    int i;

    if (trie == NULL) {
        return;
    }

    printf("%d\n", trie->data);

    for (i = 0; i < 2 * ALPHABET_LEN; i++) {
        if (trie->next[i] != NULL) {
            printf("%d: ", i + 'a');
            print_trie(trie->next[i]);
        }
    }
}

int get_count(struct trie_node * trie, char * str) {
    int i;
    int len = strlen(str);
    struct trie_node * node = trie;

    for (i = 0; i < len; i++) {
        if (node->next[get_trie_index(str[i])] == NULL) {
            return 0;
        }

        node = node->next[get_trie_index(str[i])];
    }

    return node->data;
}

