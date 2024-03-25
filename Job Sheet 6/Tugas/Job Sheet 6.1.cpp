/* Nama : Humaira Mutia
   NIM  : 23343069 */
   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure untuk data mahasiswa
struct Mahasiswa {
    char nim[15];
    char nama[100];
    float nilai;
};

// Mendefinisikan tipe data stack
#define MAX_SIZE 100
struct Stack {
    int top;
    struct Mahasiswa data[MAX_SIZE];
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

// Menambahkan data mahasiswa ke stack (push)
void push(struct Stack *s, struct Mahasiswa mhs) {
    if (isFull(s)) {
        printf("Stack penuh. Tidak bisa menambah data.\n");
        return;
    }
    s->top++;
    s->data[s->top] = mhs;
}

// Mengambil data mahasiswa dari stack (pop)
struct Mahasiswa pop(struct Stack *s) {
    struct Mahasiswa temp;
    if (isEmpty(s)) {
        printf("Stack kosong. Tidak ada data yang bisa diambil.\n");
        temp.nilai = -1; // Menandakan bahwa tidak ada data yang di-pop
        return temp;
    }
    temp = s->data[s->top];
    s->top--;
    return temp;
}

// Menampilkan seluruh data mahasiswa dalam stack
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong. Tidak ada data yang ditampilkan.\n");
        return;
    }
    printf("\nData Mahasiswa dalam Stack:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("NIM: %s\n", s->data[i].nim);
        printf("Nama: %s\n", s->data[i].nama);
        printf("Nilai: %.2f\n", s->data[i].nilai);
        printf("--------------------------------\n");
    }
}

// Fungsi untuk membandingkan dua data mahasiswa (digunakan dalam sorting)
int compareMahasiswa(const void *a, const void *b) {
    float nilai_a = ((struct Mahasiswa *)a)->nilai;
    float nilai_b = ((struct Mahasiswa *)b)->nilai;
    return nilai_b - nilai_a; // Mengurutkan dari nilai tertinggi ke terendah
}

// Fungsi untuk melakukan sorting terhadap data mahasiswa dalam stack
void sortStack(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong. Tidak ada data yang bisa diurutkan.\n");
        return;
    }
    qsort(s->data, s->top + 1, sizeof(struct Mahasiswa), compareMahasiswa);
}

int main() {
    struct Stack stack;
    initStack(&stack);

    int choice;
    struct Mahasiswa mhs;
    char temp[100];

    do {
        printf("\n===== Menu Stack Mahasiswa =====\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Hapus Data Mahasiswa\n");
        printf("3. Tampilkan Data Mahasiswa\n");
        printf("4. Urutkan Data Mahasiswa (berdasarkan nilai)\n");
        printf("5. Keluar\n");
        printf("Pilih menu (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nTambah Data Mahasiswa:\n");
                printf("NIM: ");
                scanf("%s", mhs.nim);
                printf("Nama: ");
                scanf("%s", temp); // Sementara menggunakan temp agar bisa membaca spasi pada nama
                strcpy(mhs.nama, temp);
                printf("Nilai: ");
                scanf("%f", &mhs.nilai);
                push(&stack, mhs);
                printf("Data mahasiswa berhasil ditambahkan ke dalam stack.\n");
                break;
            case 2:
                printf("\nHapus Data Mahasiswa:\n");
                mhs = pop(&stack);
                if (mhs.nilai != -1) {
                    printf("Data mahasiswa dengan NIM %s telah dihapus dari stack.\n", mhs.nim);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                sortStack(&stack);
                printf("\nData mahasiswa telah diurutkan berdasarkan nilai (dari tertinggi ke terendah).\n");
                break;
            case 5:
                printf("\nTerima kasih telah menggunakan program.\n");
                break;
            default:
                printf("\nPilihan tidak valid. Masukkan angka antara 1 hingga 5.\n");
        }
    } while (choice != 5);

    return 0;
}
