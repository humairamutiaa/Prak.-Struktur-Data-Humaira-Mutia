//created by fhandy nofalino akhsan 23343065

#include <stdio.h>

int main(){
	int n;
	
	
	printf("masukkan banyak bilangan : ");scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("masukkan angka ke %d : ", i+1);
		scanf("%d", &angka[i]);
	}
	
	for(int i=0; i<n; i++){
		printf("angka ke %d : %d\n", i+1, angka[i]);
	}
	
	getchar();
	return 0;
} 