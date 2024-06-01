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

// Fungsi untuk Selection Sort data guru berdasarkan nilai kedisiplinan
void selectionSort(struct Guru arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        // Temukan elemen terkecil dalam array yang belum diurutkan
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j].kedisiplinan < arr[min_idx].kedisiplinan) {
                min_idx = j;
            }
        }
        // Tukar elemen terkecil dengan elemen pertama dari bagian yang belum diurutkan
        swap(&arr[min_idx], &arr[i]);
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

    // Selection Sort
    printf("Data Guru Setelah Diurutkan dengan Selection Sort:\n");
    selectionSort(guru, n);
    printGuru(guru, n);

    return 0;
}
