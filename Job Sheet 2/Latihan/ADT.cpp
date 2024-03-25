#include <stdio.h>
#include <conio.h>

typedef int angka;
typedef char huruf;

int main(){
	angka umur;
	huruf h;
	huruf nama[10];
	
	printf("masukkan umur anda : "); scanf("%d",&umur);
	printf("umur anda adalah %d", umur);
	printf("\nmasukkan huruf : "); h=getche();
	printf("\nhuruf anda %c",h);
	printf("\nmasukkan nama : "); scanf("%s",nama);
	printf("nama anda %s",nama);
	getch ();
}