#include <stdio.h>

void SelSort(int array[],int n);
int main()
{
	int array[100], n,i;
	printf("Masukan jumlah elemen : ");
	scanf("%d", &n);
	printf("Masukan %d buah bilangan\n", n);
	for(i = 0; i < n; i++)
		scanf("%d", &array[i]);
	SelSort(array,n);
	return 0;
}
void SelSort(int array[], int n)
{
	int i, j, position, swap;
	for(i = 0; i < (n - 1); i++)
	{
		position = 1;
		for(j = i + 1; j < n; j++)
		{
			if(array[position] > array[j])
			position = j;
		}
		if(position != i)
		{
			swap=array[i];
			array[i]=array[position];
			array[position]=swap;
		}
	}
	printf("Array yang telah diurutkan:\n");
	for(i = 0; i < n; i++)
	printf("%d\n", array[i]);
}