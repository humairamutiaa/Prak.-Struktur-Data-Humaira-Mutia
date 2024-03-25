#include <stdio.h>
struct person
{
	int age;
	float weight;
};
int main()
{
	struct person *personPtr, person1;
	personPtr = &person1;
	printf("enter age: ");
	scanf("%d", &personPtr->age);
	printf("enter weight: ");
	scanf("%f", &personPtr->weight);
	printf("Display: \n");
	printf("Age: %d\n", personPtr->age);
	printf("Weight: %f", personPtr->weight);
	return 0;
}