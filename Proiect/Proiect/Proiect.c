#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int nivel_max = 0;

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

void echilibrat(struct node* rad, int* ok)
{
	int x;
	if (rad != NULL)
	{
		echilibrat(rad->left, &(*ok));
		echilibrat(rad->right, &(*ok));
		x = inaltime(rad->left) - inaltime(rad->right);
		if (x >= 1 || x <= -1)
			(*ok)++;
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
		postordine(rad->left);
		postordine(rad->right);
	}
}

void inordine(struct node* rad)
{
	if (rad != NULL)
	{
		postordine(rad->left);
		printf("%d ", rad->key);
		postordine(rad->right);
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
	FILE* f;
	int nr, x;
	do
	{
		printf("1. Initializare arbore.\n");
		printf("2. Citire noduri.\n");
		printf("3. Afisare preordine.\n");
		printf("4. Afisare inordine.\n");
		printf("5. Afisare postordine.\n");
		printf("6. Afisare parcurgere pe nivel\n");
		printf("0. Iesire.\n");
		printf("Optiunea dvs:");
		scanf("%d", &opt);
		switch (opt)
		{
		case ies:
			break;
		case init:
			rad = initializare(rad);
			break;
		case cit:
			if ((f = fopen("intrare1.txt", "r")) == NULL)
			{
				printf("Eroare la deschiderea fisierului de intrare\n");
				exit(EXIT_FAILURE);
			}
			else
			{
				while (!feof(f))
				{
					fscanf(f, "%d", &nr);
					rad = Adaugare(rad, nr);
				}
			}
			break;
		case pre:
			printf("Arborele parcurs in preordine:");
			preordine(rad);
			printf("\n");
			break;
		case in:
			printf("Arborele parcurs in inordine:");
			inordine(rad);
			printf("\n");
			break;
		case pos:
			printf("Arborele parcurs in postordine:");
			postordine(rad);
			printf("\n");
			break;
		case niv:
			printf("Parcurgerea pe nivel a arborelui:");
			nivel(rad);
			printf("\n");
			break;
		default:
			break;
		}
	} while (opt != 0);

	return 0;
}
