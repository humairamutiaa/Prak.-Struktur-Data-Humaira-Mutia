#include<stdio.h>
#include<stdlib.h>

struct node {
    int no_pol;
    struct node *next;
};

void display(struct node* head) {
    struct node *temp = head;
    printf("\n\nUrutan parkiran: -\n");
    while(temp != NULL) {
        printf("%d --->", temp->no_pol);
        temp = temp->next;
    }
}

void insertAtFront(struct node** headRef, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->no_pol = value;
    newNode->next = *headRef;
    *headRef = newNode;
}

int main() {
    struct node *head = NULL;
    struct node *avanza = NULL;
    struct node *hilux = NULL;
    struct node *kijangF1 = NULL;
    
    avanza = (struct node*)malloc(sizeof(struct node));
    hilux = (struct node*)malloc(sizeof(struct node));
    kijangF1 = (struct node*)malloc(sizeof(struct node));
    
    avanza->no_pol = 1234;
    hilux->no_pol = 2345;
    kijangF1->no_pol = 3456;
    
    /* Connect nodes */
    avanza->next = hilux;
    hilux->next = kijangF1;
    kijangF1->next = NULL;
    
    /* Save address of first node in head */
    head = avanza;
    insertAtFront(&head, 46543);
    display(head); 
    
    return 0;
}
