/*Nama : Humaira Mutia
  NIM : 23343069*/

#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menghitung dan menampilkan deret Fibonacci
void displayFibonacci(int n) {
    int *fibonacci = (int *)malloc(n * sizeof(int));

    // Pengecekan alokasi memori
    if (fibonacci == NULL) {
        printf("Alokasi memori gagal\n");
        exit(1);
    }

    // Inisialisasi dua elemen pertama dari deret Fibonacci
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    // Menghitung dan menyimpan deret Fibonacci
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    // Menampilkan deret Fibonacci
    printf("Deret Fibonacci pertama %d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");

    // Membebaskan memori yang dialokasikan
    free(fibonacci);
}

int main() {
    int n;

    // Meminta pengguna untuk memasukkan nilai n
    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    // Memastikan n tidak negatif
    if (n <= 0) {
        printf("Nilai n harus lebih besar dari 0.\n");
        return 1;
    }

    // Menampilkan deret Fibonacci
    displayFibonacci(n);

    return 0;
}
