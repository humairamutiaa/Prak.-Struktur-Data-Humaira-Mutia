#include <stdio.h>
#include <string.h>

// Definisi struktur untuk data buku
struct Buku {
    char judul[50];
    int harga;
};

// Fungsi untuk mencetak data buku
void printBuku(struct Buku arr[], int n) {
    printf("Judul Buku\t\t\tHarga\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s\t\t%d\n", arr[i].judul, arr[i].harga);
    }
}

// Fungsi untuk melakukan Shell Sort pada array buku
void shellSort(struct Buku arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            struct Buku temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].harga > temp.harga; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    struct Buku buku[] = {
        {"Dear Nathan", 109000},
        {"Thank You Salma", 108000},
        {"Sekeping Hati", 117000},
        {"Geez dan Ann", 119000},
        {"Goodbye Daniel", 118000},
        {"Pulang Pergi", 97000},
        {"Matahari Minor", 106000},
        {"Laut Bercerita", 160000},
        {"Malam Terakhir", 103000},
        {"Tentang Kamu", 145000}
    };
    int n = sizeof(buku) / sizeof(buku[0]);

    printf("Data Buku Sebelum Diurutkan:\n");
    printBuku(buku, n);
    printf("\n");

    // Shell Sort
    shellSort(buku, n);

    printf("Data Buku Setelah Diurutkan dengan Shell Sort:\n");
    printBuku(buku, n);

    return 0;
}
