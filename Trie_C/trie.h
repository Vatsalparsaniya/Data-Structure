#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ALPHABET_LEN 26

struct trie_node {
    int data;
    struct trie_node * next[ALPHABET_LEN];
};

struct trie_node * init_trie_node();

void destroy_trie(struct trie_node * trie);

int get_trie_index(char c);

void insert_trie(struct trie_node * trie, char * str);

int get_count(struct trie_node * trie, char * str);

void print_trie(struct trie_node * trie);
