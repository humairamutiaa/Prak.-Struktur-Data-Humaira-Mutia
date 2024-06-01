#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur node untuk data mobil
struct Node {
    char noPlat[20];
    char merkMobil[50];
    char namaPemilik[100];
    struct Node* next;
    struct Node* prev;
};

// Fungsi untuk menambahkan mobil di depan linked list
void push(struct Node** head_ref, char* noPlat, char* merkMobil, char* namaPemilik) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->noPlat, noPlat);
    strcpy(new_node->merkMobil, merkMobil);
    strcpy(new_node->namaPemilik, namaPemilik);
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

// Fungsi untuk menambahkan mobil di akhir linked list
void append(struct Node** head_ref, char* noPlat, char* merkMobil, char* namaPemilik) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    strcpy(new_node->noPlat, noPlat);
    strcpy(new_node->merkMobil, merkMobil);
    strcpy(new_node->namaPemilik, namaPemilik);
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

// Fungsi untuk menghapus mobil berdasarkan nomor plat
void deleteNode(struct Node** head_ref, char* noPlat) {
    struct Node* temp = *head_ref;
    while (temp != NULL && strcmp(temp->noPlat, noPlat) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Mobil tidak ditemukan: %s\n", noPlat);
        return;
    }
    if (*head_ref == temp)
        *head_ref = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
    printf("Mobil dihapus: %s\n", noPlat);
}

// Fungsi untuk mencetak data mobil dalam linked list
void printList(struct Node* node) {
    struct Node* last;
    printf("\nTraversal maju:\n");
    while (node != NULL) {
        printf("No Plat: %s, Merk Mobil: %s, Nama Pemilik: %s\n", node->noPlat, node->merkMobil, node->namaPemilik);
        last = node;
        node = node->next;
    }
    printf("\nTraversal mundur:\n");
    while (last != NULL) {
        printf("No Plat: %s, Merk Mobil: %s, Nama Pemilik: %s\n", last->noPlat, last->merkMobil, last->namaPemilik);
        last = last->prev;
    }
}

int main() {
    struct Node* head = NULL;
    int choice;
    char noPlat[20];
    char merkMobil[50];
    char namaPemilik[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah mobil di depan\n");
        printf("2. Tambah mobil di akhir\n");
        printf("3. Hapus mobil\n");
        printf("4. Cetak daftar mobil\n");
        printf("5. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan nomor plat: ");
                scanf(" %[^\n]s", noPlat);
                printf("Masukkan merk mobil: ");
                scanf(" %[^\n]s", merkMobil);
                printf("Masukkan nama pemilik: ");
                scanf(" %[^\n]s", namaPemilik);
                push(&head, noPlat, merkMobil, namaPemilik);
                break;
            case 2:
                printf("Masukkan nomor plat: ");
                scanf(" %[^\n]s", noPlat);
                printf("Masukkan merk mobil: ");
                scanf(" %[^\n]s", merkMobil);
                printf("Masukkan nama pemilik: ");
                scanf(" %[^\n]s", namaPemilik);
                append(&head, noPlat, merkMobil, namaPemilik);
                break;
            case 3:
                printf("Masukkan nomor plat yang akan dihapus: ");
                scanf(" %[^\n]s", noPlat);
                deleteNode(&head, noPlat);
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
