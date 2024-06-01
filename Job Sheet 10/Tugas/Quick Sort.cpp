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

// Fungsi partisi untuk Quick Sort
int partition(struct Guru arr[], int low, int high) {
    int pivot = arr[high].kedisiplinan;
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j].kedisiplinan <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fungsi untuk mengimplementasikan Quick Sort
void quickSort(struct Guru arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk mencetak data guru
void printGuru(struct Guru arr[], int n) {
    printf("Nama Guru\tKedisiplinan\n");
    printf("-----------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s\t%d\n", arr[i].nama, arr[i].kedisiplinan);
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

    // Quick Sort
    printf("Data Guru Setelah Diurutkan dengan Quick Sort:\n");
    quickSort(guru, 0, n - 1);
    printGuru(guru, n);

    return 0;
}
