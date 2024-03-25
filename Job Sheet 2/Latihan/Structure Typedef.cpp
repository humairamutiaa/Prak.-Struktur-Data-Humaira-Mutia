//created by fhandy nofalino akhsan 23343065

#include <stdio.h>

typedef struct Masiswa {
	char nama[50];
	char jurusan[50];
	int nilai;
}data;

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