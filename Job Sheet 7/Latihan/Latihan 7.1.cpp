#include<stdio.h>
#define ukuran 5  // Correctly defining the size of the queue

void enQueue(int);
void deQueue();
void tampilkan();

int items[ukuran], depan = -1, belakang = -1;

// Function to add an item to the queue
void enQueue(int value) {
    if (belakang == ukuran - 1)
        printf("\nQueue telah penuh!");
    else {
        if (depan == -1)
            depan = 0;
        belakang++;
        items[belakang] = value;  // Correctly assigning value to the queue
        printf("\nNilai ditambahkan -> %d", value);  // Correctly displaying the added value
    }
}

// Function to remove an item from the queue
void deQueue() {
    if (depan == -1)
        printf("\nQueue kosong!!");
    else {
        printf("\nNilai dihapus adalah : %d", items[depan]);  // Correctly displaying the removed value
        depan++;
        if (depan > belakang)
            depan = belakang = -1;  // Resetting the queue if it becomes empty
    }
}

// Function to display the queue
void tampilkan() {
    if (belakang == -1)
        printf("\nQueue kosong!!!");
    else {
        int i;  // Correctly declaring the loop variable
        printf("\nElemen pada Queue adalah:\n");
        for (i = depan; i <= belakang; i++)
            printf("%d\t", items[i]);  // Correctly displaying items of the queue
    }
}

int main() {
    // Demonstrating the operations on the queue
    enQueue(1);
    enQueue(2);
    enQueue(3);
    tampilkan();
    deQueue();
    tampilkan();
    return 0;
}