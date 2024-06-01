#include <stdio.h>
#include <stdlib.h>

// Structure of the node
struct Node {
    int data;
    struct Node *next; // Pointer to next node
    struct Node *prev; // Pointer to previous node
};

void push(struct Node **head_ref, int new_data) {
    // Allocate node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    // Put in the data
    new_node->data = new_data;
    // Make next of new node as head and previous as NULL
    new_node->next = *head_ref;
    new_node->prev = NULL;
    // Change prev of head node to new node
    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;
    // Move the head to point to the new node
    *head_ref = new_node;
}

void append(struct Node **head_ref, int new_data) {
    // Allocate node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref; // Used in step 5
    // Put in the data
    new_node->data = new_data;
    // This new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;
    // If the Linked List is empty, then make the new node as head
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    // Else traverse till the last node
    while (last->next != NULL)
        last = last->next;
    // Change the next of last node
    last->next = new_node;
    // Make last node as previous of new node
    new_node->prev = last;
}

void printList(struct Node *node) {
    struct Node *last = NULL;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

int main() {
    // Start with the empty list
    struct Node *head = NULL;
    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);
    // Insert 7 at the beginning. So linked list becomes 7->6->NULL
    push(&head, 7);
    // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
    push(&head, 1);
    // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
    append(&head, 4);
    printf("Created DLL is: ");
    printList(head);
    getchar();
    return 0;
}