//
//  utils_pqueue.c
//  priority_queue
//
//  Created by Manikya Bardhan on 17/09/19.
//  Copyright © 2019 Manikya Bardhan. All rights reserved.
//

#include <stdio.h>
#include "Header.h"

NODE *newNode(int val, int priority){
    NODE *tmp = malloc(sizeof(NODE));
    tmp->key = val;
    tmp->priority = priority;
    tmp->next = NULL;
    return tmp;
}

int isEmpty(NODE** head){
    return (*head) == NULL;
}

int peek(NODE **head){
    return (*head)->key;
}

void pop(NODE **head){
    NODE *tmp = *head;
    *head = tmp->next;
    free(tmp);
}

void push(NODE **head, int val, int priority){
    if(*head == NULL){
        *head = newNode(val, priority);
    }
    else{
        NODE *curr;
        NODE *prev;
        NODE *node = newNode(val, priority);
        for(curr = *head, prev = curr; curr; prev = curr, curr = curr->next  ){
            if (curr->priority > node->priority){
                prev->next = node;
                node->next = curr;
            }
        }
    }
}

void show_queue(NODE **head){
    NODE *tmp = *head;
    for(; tmp; tmp = tmp->next){
        printf("%d", tmp->key);
    }
}
