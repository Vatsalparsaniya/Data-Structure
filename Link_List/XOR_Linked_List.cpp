#include<bits/stdc++.h>
#include <inttypes.h>
using namespace std;

class node
{
    public:

        int data;
        node* xpn; // xor of previous and next node address.
};

node* XPN (node* prev, node* next)
{
    return (node*) ((uintptr_t) prev ^ (uintptr_t) next);
}

void insert (node** head, int data)
{
    node* new_node = new node();
    
    new_node->data = data;
    new_node->xpn = XPN(*head, NULL);

    if (!(*head == NULL))
    {
        (*head)->xpn = XPN(new_node, XPN((*head)->xpn, NULL));
    }

    *head = new_node;
}

void print (node* head)
{
    node* curr_addr = head;
    node* prev_addr = NULL;
    node* next_addr;

    while (curr_addr != NULL)
    {
        cout << curr_addr->data << " ";
        next_addr = XPN(prev_addr, curr_addr->xpn);
        prev_addr = curr_addr;
        curr_addr = next_addr;
    }
}

/*
int main()
{
    node* head = NULL;
    
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    print (head);
    return 0;
}
*/