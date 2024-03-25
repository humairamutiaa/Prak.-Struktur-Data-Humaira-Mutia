#include <stdio.h>

struct Mahasiwa {
	char nama[50];
	char jurusan[50];
	int nialai;
};
typedef struct Mahasiswa data;
int main(void)
{
	data mhs01;
	
	strcpy(mhs01.nama, "_______________");
	strcpy(mhs01.jurusan, "_______________");
	mhs01.nilai = 100;
	
	printf("%s adalah mahasiswa jurusan %s ", mhs.nama, mhs01.jurusan);
	printf("memperoleh nilai UAS %i \n", mhs01.nilai);
	
	return 0;
 } 