#include <stdio.h>
#include <string.h>

// Definisi struktur untuk data guru
struct Guru {
    char nama[50];
    int kedisiplinan;
};

// Fungsi untuk menukar dua data guru
void swap(struct Guru *a, struct Guru *b) {
    struct Guru temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk Bubble Sort data guru berdasarkan nilai kedisiplinan
void bubbleSort(struct Guru arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].kedisiplinan > arr[j+1].kedisiplinan) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Fungsi untuk mencetak data guru
void printGuru(struct Guru arr[], int n) {
    printf("Nama Guru\tKedisiplinan\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\n", arr[i].nama, arr[i].kedisiplinan);
    }
}

int main() {
    struct Guru guru[] = {
        {"Maira", 90},
        {"Fia", 87},
        {"Sukma", 88},
        {"Linni", 91},
        {"Avista", 89}
    };
    int n = sizeof(guru) / sizeof(guru[0]);

    printf("Data Guru Sebelum Diurutkan:\n");
    printGuru(guru, n);
    printf("\n");

    // Bubble Sort
    printf("Data Guru Setelah Diurutkan dengan Bubble Sort:\n");
    bubbleSort(guru, n);
    printGuru(guru, n);

    return 0;
}
