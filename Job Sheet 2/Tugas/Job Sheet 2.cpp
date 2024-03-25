/* Nama   : Humaira Mutia
   NIM    : 23343069
   Matkul : Praktikum Struktur Data */


#include <stdio.h>
#include <string.h>

// Definisi struktur data untuk mahasiswa
struct Mahasiswa {
    char NIM[20];
    char Nama[50];
    char TanggalLahir[20];
    float IPK;
};

// Fungsi untuk input data mahasiswa
void inputData(struct Mahasiswa *mhs) {

    printf("Masukkan Nama          : ");
    getchar(); // Mengonsumsi karakter newline (\n) dari input sebelumnya
    fgets(mhs->Nama, sizeof(mhs->Nama), stdin);
    mhs->Nama[strlen(mhs->Nama) - 1] = '\0'; // Mengganti newline (\n) di akhir string dengan null terminator
    
    printf("Masukkan NIM           : ");
    scanf("%s", mhs->NIM);

    printf("Masukkan Tanggal Lahir : ");
    scanf("%s", mhs->TanggalLahir);
    
    printf("Masukkan IPK           : ");
    scanf("%f", &(mhs->IPK));
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(struct Mahasiswa mhs) {
    printf("\nData Mahasiswa:\n");
    printf("NIM: %s\n", mhs.NIM);
    printf("Nama: %s\n", mhs.Nama);
    printf("Tanggal Lahir: %s\n", mhs.TanggalLahir);
    printf("IPK: %.2f\n", mhs.IPK);
}

int main() {
    struct Mahasiswa mhs;

    // Input data mahasiswa
    inputData(&mhs);

    // Tampilkan data mahasiswa
    tampilkanData(mhs);

    return 0;
}
