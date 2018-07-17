#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int* allocVetor ();

void getInput ();

void Bubble(int*, int);

void printSorted (int*);


int main(int argc, char *argv[])
{
	int *vetor = NULL;

    	vetor = allocVetor ();

	getInput (vetor);

    	Bubble(vetor, TAM);

	printSorted (vetor);

    	free(vetor);

    	return 0;
}


int* allocVetor ()
{
	int* vetor = NULL;

	vetor = (int*)malloc(sizeof(int) * TAM);
	if (vetor == NULL)
	{
		printf ("Erro ao alocar o vetor.\n");
		exit (1);
	}

	return vetor;
}


void getInput (int* vetor)
{
	int i;
	
	printf ("Entre com os %d valores a serem ordenados:\n", TAM);
	for (i = 0; i < TAM; i++)
		scanf ("%d", &vetor[i]);
}


void Bubble(int *vetor, int size)
{
    	int i;
    	int aux;

    	if(size > 0){
       		for(i = 0; i < TAM; i++){
          		if(vetor[i] > vetor[i + 1]){          //vetor[i] < vetor[i + 1]       para ordenar decrescentemente
   	         		aux = vetor[i + 1];
        	    		vetor[i + 1] = vetor[i];
            			vetor[i] = aux;
          		}
        	}
        	Bubble(vetor, size - 1);
    	}
}

void printSorted (int* vetor)
{
	int i;

    	printf("Ordenacao crescente:\n");
    	for(i = 0; i < TAM; i++)
        	printf("%d ", vetor[i]);
	printf ("\n");
}
