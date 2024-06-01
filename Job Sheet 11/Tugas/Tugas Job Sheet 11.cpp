#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk data mahasiswa
struct Mahasiswa {
    int NIM;
    char nama[50];
    char TTL[50];
    float IPK;
};

// Fungsi untuk mencetak data mahasiswa
void printMahasiswa(struct Mahasiswa mhs) {
    printf("NIM: %d\n", mhs.NIM);
    printf("Nama: %s\n", mhs.nama);
    printf("TTL: %s\n", mhs.TTL);
    printf("IPK: %.2f\n", mhs.IPK);
}

// Fungsi untuk Sequential Search
int sequentialSearch(struct Mahasiswa arr[], int n, int NIM) {
    for (int i = 0; i < n; i++) {
        if (arr[i].NIM == NIM) {
            return i;
        }
    }
    return -1;
}

// Fungsi untuk Binary Search
int binarySearch(struct Mahasiswa arr[], int left, int right, int NIM) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].NIM == NIM) {
            return mid;
        }
        if (arr[mid].NIM < NIM) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Fungsi untuk menukar dua data mahasiswa
void swap(struct Mahasiswa *a, struct Mahasiswa *b) {
    struct Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mengurutkan data mahasiswa berdasarkan NIM menggunakan Bubble Sort
void bubbleSort(struct Mahasiswa arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].NIM > arr[j+1].NIM) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int n, nimToSearch, choice;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    struct Mahasiswa *mahasiswa = (struct Mahasiswa *)malloc(n * sizeof(struct Mahasiswa));

    // Input data mahasiswa
    for (int i = 0; i < n; i++) {
        printf("Masukkan NIM: ");
        scanf("%d", &mahasiswa[i].NIM);
        printf("Masukkan Nama: ");
        scanf(" %[^\n]%*c", mahasiswa[i].nama);
        printf("Masukkan TTL: ");
        scanf(" %[^\n]%*c", mahasiswa[i].TTL);
        printf("Masukkan IPK: ");
        scanf("%f", &mahasiswa[i].IPK);
    }

    printf("\nData mahasiswa telah diinput.\n");

    // Pilih metode pencarian
    printf("Pilih metode pencarian:\n1. Sequential Search\n2. Binary Search\n");
    scanf("%d", &choice);

    printf("Masukkan NIM yang ingin dicari: ");
    scanf("%d", &nimToSearch);

    if (choice == 1) {
        printf("Pencarian Data Mahasiswa dengan Sequential Search:\n");
        int seqIndex = sequentialSearch(mahasiswa, n, nimToSearch);
        if (seqIndex != -1) {
            printMahasiswa(mahasiswa[seqIndex]);
        } else {
            printf("Data mahasiswa dengan NIM %d tidak ditemukan.\n", nimToSearch);
        }
    } else if (choice == 2) {
        // Urutkan data mahasiswa untuk Binary Search
        bubbleSort(mahasiswa, n);

        printf("Pencarian Data Mahasiswa dengan Binary Search:\n");
        int binIndex = binarySearch(mahasiswa, 0, n - 1, nimToSearch);
        if (binIndex != -1) {
            printMahasiswa(mahasiswa[binIndex]);
        } else {
            printf("Data mahasiswa dengan NIM %d tidak ditemukan.\n", nimToSearch);
        }
    } else {
        printf("Pilihan tidak valid.\n");
    }

    free(mahasiswa);
    return 0;
}
