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

// Fungsi untuk menggabungkan dua subarray
void merge(struct Buku arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Buat subarray sementara
    struct Buku L[n1], R[n2];

    // Salin data ke subarray sementara
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Gabungkan subarray sementara kembali ke arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].harga <= R[j].harga) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin elemen yang tersisa dari L[], jika ada
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin elemen yang tersisa dari R[], jika ada
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi untuk mengurutkan array menggunakan merge sort
void mergeSort(struct Buku arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Urutkan bagian pertama dan kedua
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Gabungkan bagian yang sudah diurutkan
        merge(arr, l, m, r);
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

    // Merge Sort
    mergeSort(buku, 0, n - 1);

    printf("Data Buku Setelah Diurutkan dengan Merge Sort:\n");
    printBuku(buku, n);

    return 0;
}
