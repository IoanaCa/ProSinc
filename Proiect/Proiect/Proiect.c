#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *left;
	struct node *right;
};

struct node *initializare(struct node *rad)
{
	rad = NULL;
	return rad;
}

struct node *Adaugare(struct node *rad, int nod)
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

void echilibrat(struct node *rad, int *ok)
{
	int x;
	if (rad != NULL)
	{
		echilibrat(rad->left, &(*ok));
		echilibrat(rad->right, &(*ok));
		x = inalt(rad->left) - inalt(rad->right);
		if (x >= 1 || x <= -1)
			(*ok)++;
	}
}

void postordine(struct node *rad)
{
	if (rad != NULL)
	{
		postordine(rad->left);
		postordine(rad->right);
		printf("%d ", rad->key);
	}
}

void preordine(struct node *rad)
{
	if (rad != NULL)
	{
		printf("%d ", rad->key);
		postordine(rad->left);
		postordine(rad->right);
	}
}

void inordine(struct node *rad)
{
	if (rad != NULL)
	{
		postordine(rad->left);
		printf("%d ", rad->key);
		postordine(rad->right);
	}
}

int main()
{
	enum { ies, init, cit, pre, in, pos }opt;
	struct node *rad = NULL;
	FILE *f;
	do
	{
		printf("1. Initializare arbore.\n");
		printf("2. Citire noduri.\n");
		printf("3. Afisare preordine.\n");
		printf("4. Afisare postordine.\n");
		printf("5. Afisare postordine.\n");
		printf("0. Iesire.\n");
		switch (opt)
		{
		case ies:
			break;
		case init:
			break;
		case cit:
			break;
		case pre:
			break;
		case in:
			break;
		case pos:
			break;
		default:
			break;
		}
	} while (opt != 0);
	return 0;
}