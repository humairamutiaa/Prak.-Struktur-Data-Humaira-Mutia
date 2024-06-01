#include <stdio.h>

void ShellSort(int a[], int n)
{
	int i, j, increment, temp;
	for(increment = n/2; increment > 0; increment /= 2)
	{
		for(i = increment; i < n; i++)
		{
			temp = a[i];
			for(j = i; j >= increment; j -= increment)
			{
				if(temp < a[j - increment])
					a[j] = a[j - increment];
				else
					break;
			}
			a[j] = temp;
		}
	}
}
int main()
{
	int i, n, a[10];
	printf("Masukan jumlah elemen : ");
	scanf("%d",&n);
	printf("Masukan %d bilangan : \n",n);
	for(i = 0; i < n; i++) 
	{
		scanf("%d",&a[i]);
	}
	ShellSort(a,n);
	printf("Elemen yang telah diurutkan adalah:\n");
	for(i = 0; i < n; i++)
	printf("%d\n",a[i]);
	printf("\n");
	return 0;
}