/*Nama : Humaira Mutia
  NIM  : 23343069*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5 // Jumlah item maksimum yang dapat disimpan

int stack[MAX]; // Deklarasi array untuk stack
int top = -1;   // Inisialisasi top dengan nilai -1

void push() {
    int val;
    if (top == MAX - 1) {
        printf("\nStack penuh!!");
    } else {
        printf("\nMasukan item yang ingin ditambahkan: ");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack kosong!!");
    } else {
        printf("\nItem yang dihapus adalah %d", stack[top]);
        top = top - 1;
    }
}

void display() {
    if (top == -1) {
        printf("\nStack kosong!!");
    } else {
        printf("\nIsi stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) { // Infinite loop, akan berakhir ketika pilihan adalah 4
        printf("\n*** Menu Stack ***");
        printf("\n\n1.Push\n2.Pop\n3.Tampilkan\n4.Keluar");
        printf("\n\nMasukan pilihanmu (1-4): ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nPilihan tidak valid. Masukkan angka antara 1 hingga 4.");
        }
    }
    return 0;
}
