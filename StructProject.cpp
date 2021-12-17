#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Respository
{
	char name[20];
	int age;
};

int sortByAge(const void* a, const void* b)
{
	struct Respository* respository_1 = (struct Respository*)a;
	struct Respository* respository_2 = (struct Respository*)b;

	return (respository_1->age > respository_2->age);
}

int main(int argc, char* argv[])
{
	int numberOfPeople = 0;

	while (numberOfPeople <= 0)
	{
		printf("How many people do you want to enroll? ");
		scanf("%d", &numberOfPeople);
	}

	printf("\n");

	struct Respository* respository = (struct Respository*)malloc(sizeof(struct Respository) * numberOfPeople);

	int i;
	for (i = 0; i < numberOfPeople; i++)
	{
		printf("Write the person's name of %d. : ", i + 1);
		scanf("%s", &respository[i].name);
		printf("Write the person's age of %d. ", i + 1);
		scanf("%d", &respository[i].age);
		printf("\n");
	}

	qsort(respository, numberOfPeople, sizeof(struct Respository), sortByAge);

	int yas = 0;
	for (i = 0; i < numberOfPeople; i++)
	{
		if (yas == respository[i].age)
		{
			printf(", ");
			printf("%s", respository[i].name);
		}
		else
		{
			yas = respository[i].age;
			printf("\n");
			printf("%d year olds: ", respository[i].age);
			printf("%s", respository[i].name);
		}
	}

	printf("\n");

	system("pause");

	return 0;
}
