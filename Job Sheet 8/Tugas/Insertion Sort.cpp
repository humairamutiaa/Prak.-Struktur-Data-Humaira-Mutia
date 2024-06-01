#include <stdio.h>
#include <string.h>

// Definisi struktur untuk data buku
struct Buku {
    char judul[50];
    int harga;
};

// Fungsi untuk Insertion Sort data buku berdasarkan harga
void insertionSort(struct Buku arr[], int n) {
    int i, j;
    struct Buku key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Pindahkan elemen yang lebih besar dari key ke posisi sebelumnya
        while (j >= 0 && arr[j].harga > key.harga) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Fungsi untuk mencetak data buku
void printBuku(struct Buku arr[], int n) {
    printf("Judul Buku\t\t\tHarga\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t\t%d\n", arr[i].judul, arr[i].harga);
    }
}

int main() {
    struct Buku buku[] = {
        {"Dear Nathan", 120000},
        {"Thank You Salma", 118000},
        {"Sekeping Hati", 100000},
        {"Geez dan Ann",  109000},
        {"Goodbye Daniel", 108000},
        {"Pulang Pergi", 127000},
        {"Matahari Minor", 106000},
        {"Laut Bercerita", 120000},
        {"Malam Terakhir", 103000},
        {"Tentang Kamu",   145000}
    };
    int n = sizeof(buku) / sizeof(buku[0]);

    printf("Data Buku Sebelum Diurutkan:\n");
    printBuku(buku,    n);
    printf("\n");

    // Insertion Sort
    printf("Data Buku Setelah Diurutkan dengan Insertion Sort:\n");
    insertionSort(buku,    n);
    printBuku(buku, n);

    return 0;
}
