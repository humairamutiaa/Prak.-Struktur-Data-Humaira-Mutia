//pointer1.C
//prohgram untuk mengintroduksi konsep pointer
#include <stdio.h>
#include <conio.h>

int main()
{
	int usia1 = 50;
	int usia2 = 18;
	//menciptakan sebuah pointer
	int *ptr;
	//menugaskan pointer tersebut kepada usia1
	ptr = &usia1; // & adalah operator alamat
	
	printf("\nUsia saya (usia1): %d", usia1); //menampilkan 50
	printf("\nUsia saya (*ptr): %d", *ptr); //menampilkan 50
	//*ptr merupakan nilai yang disimpan ptr, yaitu 50
	printf("\n (&usia1) %x (ptr) %x", &usia1, ptr);
	//ptr adalah alamat dari usia1 jadi merupakan &usia 1. keduanya sama
	//sekarang anda akan menugaskannya kepada usia 2
	ptr = &usia2;
	
	printf("\nusia anda (*ptr): %d", *ptr); //menampilkan 18
	//*ptr merupakan nilai yang disimpan ptr, yaitu 18
	
	printf("\n(&usia2) %x (ptr) %x", & usia2, ptr);
	//ptr adalah alamat dari usia2 jadi merupakan &usia2. keduanya sama
	
	//menampilkan alamat dari variabel ptr. anda tidak memerlukan 
	//alamat ini
	printf("\n(&ptr) %x", & ptr);
	
	getch();
}//akhir maun