/*Nama : Humaira Mutia
  NIM  : 23343069*/

#include <stdio.h>
#define MAXSIZE 8

int stack[MAXSIZE];
int top = -1;

int isempty() {
    if(top == -1)
        return 1;
    else
        return 0;
}

int peek() {
    return stack[top];
}

int pop() {
    int data;
    if(!isempty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("Tidak dapat mengambil data, Stack kosong.\n");
        return -1;
    }
}

void push(int data) {
    if(top < MAXSIZE - 1) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Tidak dapat menambah data, Stack penuh.\n");
    }
}

int main() {
    // Menambahkan item ke stack
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);
    printf("Elemen teratas pada Stack adalah: %d\n", peek());
    printf("Semua elemennya adalah: ");
    // Print stack data
    while(!isempty()) {
        int data = pop();
        printf("%d ", data);
    }
    printf("\n");
    return 0;
}
