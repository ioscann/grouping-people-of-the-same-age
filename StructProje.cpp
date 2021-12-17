#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Depo
{
	char ad[20];
	int yas;
};

int yasaGoreSirala(const void* a, const void* b)
{
	struct Depo* depo_1 = (struct Depo*)a;
	struct Depo* depo_2 = (struct Depo*)b;

	return (depo_1->yas > depo_2->yas);
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Turkish");
	int kisiSayisi = 0;

	while (kisiSayisi <= 0)
	{
		printf("Kaç kişi kayıt etmek istiyorsunuz? ");
		scanf("%d", &kisiSayisi);
	}

	printf("\n");

	struct Depo* depo = (struct Depo*)malloc(sizeof(struct Depo) * kisiSayisi);

	int i;
	for (i = 0; i < kisiSayisi; i++)
	{
		printf("%d. kişinin adını giriniz: ", i + 1);
		scanf("%s", &depo[i].ad);
		printf("%d. kişinin yaşını giriniz: ", i + 1);
		scanf("%d", &depo[i].yas);
		printf("\n");
	}

	qsort(depo, kisiSayisi, sizeof(struct Depo), yasaGoreSirala);

	int yas = 0;
	for (i = 0; i < kisiSayisi; i++)
	{
		if (yas == depo[i].yas)
		{
			printf(", ");
			printf("%s", depo[i].ad);
		}
		else
		{
			yas = depo[i].yas;
			printf("\n");
			printf("%d yaşındakiler: ", depo[i].yas);
			printf("%s", depo[i].ad);
		}
	}

	return 0;


	system("pause");
}
