#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
	int key;
	struct node* left;
	struct node* right;
};

struct node* initializare(struct node* rad)
{
	rad = NULL;
	return rad;
}

int maxim(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int randoms(int lower, int upper)
{
	int valoare;

	valoare = (rand() % (upper - lower + 1)) + lower;
	
	return valoare;
}

struct node* Adaugare(struct node* rad, int nod)
{
	if (rad == NULL)
	{
		if ((rad = (struct node*)malloc(sizeof(struct node))) == NULL)
		{
			perror("Eroare la alocarea de memorie.\n");
			exit(EXIT_FAILURE);
		}
		rad->key = nod;
		rad->left = NULL;
		rad->right = NULL;
	}
	else
	{
		if (nod < rad->key)
		{
			rad->left = Adaugare(rad->left, nod);
		}
		else if (nod > rad->key)
		{
			rad->right = Adaugare(rad->right, nod);
		}
		else
			printf("Nodul %d exista deja in arbore.\n\n", nod);
	}
	return rad;
}

int inaltime(struct node* rad)
{
	int h1, h2;
	if (rad == NULL)
	{
		return 0;
	}
	else
	{
		h1 = inaltime(rad->left);
		h2 = inaltime(rad->right);
		if (h1 > h2)
			return h1 + 1;
		else
			return h2 + 1;
	}
}

void postordine(struct node* rad)
{
	if (rad != NULL)
	{
		postordine(rad->left);
		postordine(rad->right);
		printf("%d ", rad->key);
	}
}

void preordine(struct node* rad)
{
	if (rad != NULL)
	{
		printf("%d ", rad->key);
		preordine(rad->left);
		preordine(rad->right);
	}
}

void inordine(struct node* rad)
{
	if (rad != NULL)
	{
		inordine(rad->left);
		printf("%d ", rad->key);
		inordine(rad->right);
	}
}


void parcurgere_nivel(struct node* rad, int x)
{
	if (rad  != NULL)
	{
		if (x == 1)
			printf("%d ", rad->key);
		else
			if (x > 1)
			{
				parcurgere_nivel(rad->left, x - 1);
				parcurgere_nivel(rad->right, x - 1);
			}
	}
}

void nivel(struct node* rad)
{
	int i = inaltime(rad);
	for (int j = 1; j <= i; j++)
	{
		printf("\n");
		parcurgere_nivel(rad, j);
	}
}



int main()
{
	enum { ies, init, cit, pre, in, pos, niv }opt;
	struct node* rad = NULL;
	int nr, x, rnd;
	do
	{
		printf("1. Initializare arbore.\n");
		printf("2. Generare noduri.\n");
		printf("3. Afisare preordine.\n");
		printf("4. Afisare inordine.\n");
		printf("5. Afisare postordine.\n");
		printf("6. Afisare parcurgere pe nivel.\n");
		printf("0. Iesire.\n\n");
		printf("Optiunea dvs:");
		scanf("%d", &opt);
		printf("\n");
		switch (opt)
		{
		case ies:
			break;
		case init:
			rad = initializare(rad);
			printf("Arborele a fost initializat.\n\n");
			break;
		case cit:
			printf("Introduceti numarul de elemente ale arborelui:");
			scanf("%d", &nr);
			printf("Numerele generate sunt: ");
				while (nr!=0)
				{
					
					rnd = randoms(0, 50);
					printf("%d ", rnd);
					rad = Adaugare(rad, rnd);
					nr--;
				}
				printf("\n");
			printf("\n");
			break;
		case pre:
			printf("Arborele parcurs in preordine: ");
			preordine(rad);
			printf("\n\n");
			break;
		case in:
			printf("Arborele parcurs in inordine: ");
			inordine(rad);
			printf("\n\n");
			break;
		case pos:
			printf("Arborele parcurs in postordine: ");
			postordine(rad);
			printf("\n\n");
			break;
		case niv:
			printf("Parcurgerea pe nivel a arborelui: ");
			nivel(rad);
			printf("\n\n");
			break;
		default:
			break;
		}
	} while (opt != 0);

	return 0;
}
