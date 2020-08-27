//
//  Header.h
//  priority_queue
//
//  Created by Manikya Bardhan on 17/09/19.
//  Copyright © 2019 Manikya Bardhan. All rights reserved.
//

#ifndef Header_h
#define Header_h


#endif /* Header_h */

/*                    queue.h                    */
#include <stdio.h>
#include <stdlib.h>
typedef struct QNode
{
    int key;
    int priority;
    struct QNode* next;
}NODE;

// A utility function to create a new linked list node.
NODE* newNode(int, int);
//returns value at head
int peek(NODE **);

void push(NODE **, int, int);
// Function to remove a key from given queue q
void pop(NODE **);
//func to check if list is empty
int isEmpty(NODE **);

void free_mem(NODE *);

void show_queue(NODE **);
