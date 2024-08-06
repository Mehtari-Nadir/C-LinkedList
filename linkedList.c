#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node;

node *init_list(node *head)
{
    head = NULL;
    return head;
}

void printList(node *head)
{
    if (head == NULL)
    {
        printf("The list is empty!!!\n");
        exit;
    }

    node *tmp = head;
    while (tmp != NULL)
    {
        printf("value : %d\n", tmp->value);
        tmp = tmp->next;
    }
}

node *add_start(node *head, int value)
{
    node *newHead = malloc(sizeof(node));
    newHead->value = value;
    newHead->next = head;
    return newHead;
}

node *add_last(node *head, int value)
{
    node *newHead = malloc(sizeof(node));
    newHead->value = value;
    newHead->next = NULL;

    if (head == NULL)
    {
        return newHead;
    }

    
}

int main(void)
{
    node *head = init_list(head);

    // head = add_start(head, 34);
    // head = add_start(head, 105);
    // head = add_start(head, 2);
    // head = add_start(head, 67);

    printList(head);
}