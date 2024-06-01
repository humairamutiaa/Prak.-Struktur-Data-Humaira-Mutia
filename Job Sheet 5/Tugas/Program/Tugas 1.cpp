#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur node untuk data buku
struct Node {
    char judul[100];
    char pengarang[100];
    int tahun;
    struct Node* next;
    struct Node* prev;
};

// Fungsi untuk menambahkan buku di depan linked list
void push(struct Node** head_ref, char* judul, char* pengarang, int tahun) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->judul, judul);
    strcpy(new_node->pengarang, pengarang);
    new_node->tahun = tahun;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

// Fungsi untuk menambahkan buku di akhir linked list
void append(struct Node** head_ref, char* judul, char* pengarang, int tahun) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    strcpy(new_node->judul, judul);
    strcpy(new_node->pengarang, pengarang);
    new_node->tahun = tahun;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

// Fungsi untuk menghapus buku berdasarkan judul
void deleteNode(struct Node** head_ref, char* judul) {
    struct Node* temp = *head_ref;
    while (temp != NULL && strcmp(temp->judul, judul) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Buku tidak ditemukan: %s\n", judul);
        return;
    }
    if (*head_ref == temp)
        *head_ref = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
    printf("Buku dihapus: %s\n", judul);
}

// Fungsi untuk mencetak data buku dalam linked list
void printList(struct Node* node) {
    struct Node* last;
    printf("\nTraversal maju:\n");
    while (node != NULL) {
        printf("Judul: %s, Pengarang: %s, Tahun: %d\n", node->judul, node->pengarang, node->tahun);
        last = node;
        node = node->next;
    }
    printf("\nTraversal mundur:\n");
    while (last != NULL) {
        printf("Judul: %s, Pengarang: %s, Tahun: %d\n", last->judul, last->pengarang, last->tahun);
        last = last->prev;
    }
}

int main() {
    struct Node* head = NULL;
    int choice;
    char judul[100];
    char pengarang[100];
    int tahun;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah buku di depan\n");
        printf("2. Tambah buku di akhir\n");
        printf("3. Hapus buku\n");
        printf("4. Cetak daftar buku\n");
        printf("5. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan judul buku: ");
                scanf(" %[^\n]s", judul);
                printf("Masukkan nama pengarang: ");
                scanf(" %[^\n]s", pengarang);
                printf("Masukkan tahun terbit: ");
                scanf("%d", &tahun);
                push(&head, judul, pengarang, tahun);
                break;
            case 2:
                printf("Masukkan judul buku: ");
                scanf(" %[^\n]s", judul);
                printf("Masukkan nama pengarang: ");
                scanf(" %[^\n]s", pengarang);
                printf("Masukkan tahun terbit: ");
                scanf("%d", &tahun);
                append(&head, judul, pengarang, tahun);
                break;
            case 3:
                printf("Masukkan judul buku yang akan dihapus: ");
                scanf(" %[^\n]s", judul);
                deleteNode(&head, judul);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    }
    return 0;
}
