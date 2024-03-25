/*Nama: Humaira Mutia
  NIM : 23343069*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fungsi untuk memeriksa apakah sebuah bilangan prima atau bukan
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Fungsi untuk menampilkan bilangan prima pertama sampai ke-n
void displayPrimes(int n, int m) {
    int *primes = (int *)malloc(m * sizeof(int));

    if (primes == NULL) {
        printf("Alokasi memori gagal\n");
        exit(1);
    }

    int count = 0; // Jumlah bilangan prima yang sudah ditemukan

    for (int num = 2; count < n; num++) {
        if (isPrime(num)) {
            if (count >= m) {
                // Menambah ukuran alokasi memori menggunakan realloc jika dibutuhkan
                m *= 2;
                primes = (int *)realloc(primes, m * sizeof(int));
                if (primes == NULL) {
                    printf("Alokasi memori gagal\n");
                    exit(1);
                }
            }
            primes[count++] = num; // Menyimpan bilangan prima dalam array
        }
    }

    // Menampilkan bilangan prima
    printf("Bilangan prima pertama %d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Membebaskan memori yang dialokasikan
    free(primes);
}

int main() {
    int n, m;

    // Meminta pengguna untuk memasukkan nilai n dan m
    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    printf("Masukkan ukuran awal alokasi memori (m): ");
    scanf("%d", &m);

    // Memastikan n dan m tidak negatif
    if (n <= 0 || m <= 0) {
        printf("Nilai n dan m harus lebih besar dari 0.\n");
        return 1;
    }

    // Menampilkan bilangan prima
    displayPrimes(n, m);

    return 0;
}

