/* Nama : Humaira Mutia
   NIM : 23343069 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi tipe data stack
#define MAX_SIZE 100
struct Stack {
    int top;
    char data[MAX_SIZE];
};

// Inisialisasi stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Cek apakah stack kosong
int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

// Cek apakah stack penuh
int isFull(struct Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Push karakter ke dalam stack
void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack penuh. Tidak bisa menambah data.\n");
        return;
    }
    s->top++;
    s->data[s->top] = c;
}

// Pop karakter dari stack
char pop(struct Stack *s) {
    char temp;
    if (isEmpty(s)) {
        printf("Stack kosong. Tidak ada data yang bisa diambil.\n");
        return '\0';
    }
    temp = s->data[s->top];
    s->top--;
    return temp;
}

// Balik kata menggunakan stack
void balikKata(char *kata) {
    struct Stack stack;
    initStack(&stack);

    // Push setiap karakter dari kata ke dalam stack
    for (int i = 0; i < strlen(kata); i++) {
        push(&stack, kata[i]);
    }

    // Pop setiap karakter dari stack dan cetak, sehingga membentuk kata terbalik
    printf("Kata terbalik: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");
}

int main() {
    int choice;
    char kata[100];

    do {
        printf("\n===== Menu Pembalik Kata =====\n");
        printf("1. Input Kata\n");
        printf("2. Balik Kata\n");
        printf("3. Exit\n");
        printf("Pilih menu (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMasukkan kata: ");
                scanf("%s", kata);
                break;
            case 2:
                if (strlen(kata) == 0) {
                    printf("Belum ada kata yang dimasukkan.\n");
                } else {
                    balikKata(kata);
                }
                break;
            case 3:
                printf("\nTerima kasih telah menggunakan program.\n");
                break;
            default:
                printf("\nPilihan tidak valid. Masukkan angka antara 1 hingga 3.\n");
        }
    } while (choice != 3);

    return 0;
}
