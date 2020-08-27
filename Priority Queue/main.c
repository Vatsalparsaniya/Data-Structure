//
//  main.c
//  priority_queue
//
//  Created by Manikya Bardhan on 17/09/19.
//  Copyright © 2019 Manikya Bardhan. All rights reserved.
//

/*                    queue_main.c                    */

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

static NODE **head;
// Driver Program to test queue functions
int main(int argc, char **argv)
{
    char choice;
    int value, priority;
    head = malloc(sizeof(NODE **));
    
    while (1)
    {
        printf ("\nKey in your choice i - insert d - delete s - show q - quit :");
        scanf (" %c", &choice);
        if (choice == 'q')
            break;
        switch (choice)
        {
            case 'i':    // Insert a node
                printf ("Key in the value:");
                scanf (" %d", &value);
                printf ("Key in the priority:");
                scanf (" %d", &priority);
                push(head, value, priority);
                break;
                
            case 'd':  // Dequeue a node
                pop(head);
                break;
                
            case 's':  // Show the contents of all the nodes in the queue
                show_queue(head);
                break;
                
            default:
                break;
        }
    }
    
    return 0;
} 
