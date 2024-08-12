#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node node;

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

node *insertAtHead(node *head, int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

node *insertAtEnd(node *head, int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newNode;
    return head;
}

node *insertAtPosition(node *head, int value, int position)
{
    node *newNode = malloc(sizeof(node));
    newNode->value = value;

    if (position == 0 || head == NULL)
    {
        newNode->next = head;
        return newNode;
    }

    node *tmp = head;
    node *ptmp = NULL;

    while (tmp != NULL)
    {
        if (position == 0)
        {
            newNode->next = tmp;
            ptmp->next = newNode;
            return head;
        }
        position--;
        ptmp = tmp;
        tmp = tmp->next;
    }
    newNode->next = NULL;
    ptmp->next = newNode;
    return head;
}

node *deleteTail(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    node *tmp = head;
    node *ptmp;
    while (tmp->next != NULL)
    {
        ptmp = tmp;
        tmp = tmp->next;
    }
    ptmp->next = NULL;
    free(tmp);
    return head;
}

node *deleteHead(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *tmp = head->next;
    free(head);
    return tmp;
}

node *deleteAtPosition(node *head, int position)
{

    if (head == NULL || head->next == NULL)
    {
        free(head);
        return NULL;
    }

    if (position == 0)
    {
        return deleteHead(head);
    }

    node *tmp = head;
    node *ptmp = NULL;
    while (tmp->next != NULL)
    {
        if (position == 0)
        {
            ptmp->next = tmp->next;
            free(tmp);
            return head;
        }
        position--;
        ptmp = tmp;
        tmp = tmp->next;
    }
    ptmp->next = NULL;
    free(tmp);
    return head;
}

int sizeOfList(node *head, node *tmp)
{
    if (tmp == NULL)
    {
        return 0;
    }
    return 1 + sizeOfList(head, tmp->next);
}

int occurrencesElement(node *tmp, int element)
{
    if (tmp == NULL)
    {
        return 0;
    }

    if (tmp->value == element)
    {
        return 1 + occurrencesElement(tmp->next, element);
    }

    return occurrencesElement(tmp->next, element);
}

node *elementOf(node *tmp, int position)
{
    if (position == 0 || tmp == NULL)
    {
        return tmp;
    }

    return elementOf(tmp->next, --position);
}

node *findElement(node *tmp, int value)
{
    if (tmp == NULL || value == tmp->value)
    {
        return tmp;
    }
    return findElement(tmp->next, value);
}

int main(void)
{
    node *head = init_list(head);

    head = insertAtEnd(head, 34);
    head = insertAtEnd(head, 105);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 67);

    // head = insertAtHead(head, 34);
    // head = insertAtHead(head, 105);
    // head = insertAtHead(head, 2);
    // head = insertAtHead(head, 67);

    // head = deleteHead(head);
    // head = deleteTail(head);

    // head = insertAtPosition(head, 100, 5);
    // head = deleteAtPosition(head, 2);

    // int size = sizeOfList(head, head);
    // printf("the size : %d\n", size);

    // int element = 2;
    // int result = occurrencesElement(head, head, element);
    // printf("the occurrences of %d : %d\n", element, result);

    // int position = 0;
    // node *element = elementOf(head, position);
    // if (element != NULL)
    // {
    //     printf("Element of position %d = %d\n", position, element->value);
    // }
    // else
    // {
    //     printf("Element of position %d not exist!!\n", position);
    // }

    // int value = 0;
    // node *element = findElement(head, value);
    // if (element == NULL)
    // {
    //     printf("there is not node with value : %d in the list!!\n", value);
    // }

    printList(head);
}