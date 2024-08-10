# Linked List Implementation in C

This repository contains a simple implementation of a singly linked list in C. A linked list is a linear data structure where elements are stored in nodes, and each node points to the next node in the sequence. This particular implementation provides basic functionalities such as initialization, insertion at various positions, and printing the list.

## Features

- **Initialization**: Create an empty linked list.
- **Insertion**:
  - At the head of the list.
  - At the end of the list.
  - At a specific position in the list.
- **Printing**: Display the elements of the list.

## Functions

### `node *init_list(node *head)`

Initializes an empty linked list by setting the head to `NULL`.

### `void printList(node *head)`

Prints the values of all nodes in the linked list. If the list is empty, it displays a message indicating so.

### `node *insertAtHead(node *head, int value)`

Inserts a new node with the given value at the head of the linked list.

### `node *insertAtEnd(node *head, int value)`

Inserts a new node with the given value at the end of the linked list.

### `node *insertAtPosition(node *head, int value, int position)`

Inserts a new node with the given value at the specified position in the linked list.

## How to Compile

To compile the program, use the following command:

```bash
gcc -o linkedList linkedList.c
