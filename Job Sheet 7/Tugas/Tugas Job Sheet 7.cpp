#include <stdio.h>
#include <stdlib.h>

// Definisi struktur untuk Graf
struct Graf {
    int jumlahSimpul;
    int** daftarAdj;
    int* dikunjungi;
};

// Fungsi untuk membuat graf baru
struct Graf* buatGraf(int jumlahSimpul) {
    struct Graf* graf = (struct Graf*)malloc(sizeof(struct Graf));
    graf->jumlahSimpul = jumlahSimpul;
    
    graf->daftarAdj = (int**)malloc(jumlahSimpul * sizeof(int*));
    for (int i = 0; i < jumlahSimpul; i++) {
        graf->daftarAdj[i] = (int*)malloc(jumlahSimpul * sizeof(int));
        for (int j = 0; j < jumlahSimpul; j++) {
            graf->daftarAdj[i][j] = 0;
        }
    }

    graf->dikunjungi = (int*)malloc(jumlahSimpul * sizeof(int));
    for (int i = 0; i < jumlahSimpul; i++) {
        graf->dikunjungi[i] = 0;
    }

    return graf;
}

// Fungsi untuk menambahkan sisi pada graf
void tambahSisi(struct Graf* graf, int asal, int tujuan) {
    graf->daftarAdj[asal][tujuan] = 1;
    graf->daftarAdj[tujuan][asal] = 1; // Jika graf tidak berarah
}

// Fungsi untuk melakukan Breadth-First Search (BFS)
void BFS(struct Graf* graf, int simpulAwal) {
    int* antrian = (int*)malloc(graf->jumlahSimpul * sizeof(int));
    int depan = 0;
    int belakang = 0;

    graf->dikunjungi[simpulAwal] = 1;
    antrian[belakang++] = simpulAwal;

    while (depan < belakang) {
        int simpulSaatIni = antrian[depan++];
        printf("Dikunjungi %d\n", simpulSaatIni);

        for (int i = 0; i < graf->jumlahSimpul; i++) {
            if (graf->daftarAdj[simpulSaatIni][i] == 1 && graf->dikunjungi[i] == 0) {
                graf->dikunjungi[i] = 1;
                antrian[belakang++] = i;
            }
        }
    }

    free(antrian);
}

int main() {
    int jumlahSimpul = 6;
    struct Graf* graf = buatGraf(jumlahSimpul);

    tambahSisi(graf, 0, 1);
    tambahSisi(graf, 0, 2);
    tambahSisi(graf, 1, 2);
    tambahSisi(graf, 1, 3);
    tambahSisi(graf, 2, 4);
    tambahSisi(graf, 3, 4);
    tambahSisi(graf, 3, 5);
    tambahSisi(graf, 4, 5);

    printf("Pencarian Breadth-First Search dimulai dari simpul 0:\n");
    BFS(graf, 0);

    for (int i = 0; i < jumlahSimpul; i++) {
        free(graf->daftarAdj[i]);
    }
    free(graf->daftarAdj);
    free(graf->dikunjungi);
    free(graf);

    return 0;
}
