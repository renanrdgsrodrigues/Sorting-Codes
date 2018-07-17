/*	Author: Renan Rodrigues
*
*****	Bubble Sort. 	******
*    	Metodo de ordenacao que varre o vetor n vezes em busca de um elemento menor ou maior.
*    	(depende de como quer ser ordenado)
*
*	Este codigo faz a ordenacao crescente e decrescente (escolha do usuario)
*
*	Complexidade de tempo:
*		-Pior caso (vetor ordenado em ordem inversa da desejada): O(n^2), pois percorreo vetor N vezes trocando par por par.
*	 	-Melhor caso (vetor ja ordenado) O(n).
*		-Media: O(n^2).
*
*	Complexidade de memoria:
*		-vetor principal: O(n)
*		-memoria auxiliar: O(1)
*	
*	Esse algoritmo eh um ESTAVEL, ou seja, a ordem da insercao
*	eh preservada apos a ordenacao.
*	Ex: input : 2[a], 1, 5, 4, 3, 2[b]
*	    output: 1, 2[a], 2[b], 3, 4, 5	
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

//Funcao que implementa uma alocacao dinamica de memoria
int* allocVetor ();

//Funcao para receber a entrada de valores do usuario
void getInput (int*);

//Funcao que implementa o Bubble Sort Crescente
void increasingSort (int*);

//Funcao que implementa o Bubble Sort Decrescente
void decreasingSort (int*);

//Funcao para imprimir o vetor ordenado
void printSorted (int*);


int main(int argc, char** argv)
{
	int op;
	int *vetor = NULL;             
   
	vetor = allocVetor ();;           
	getInput (vetor);

	printf ("Digite\n1 : Ordenacao Crescente.\n2 : Ordenacao Decrescente.\n");
	scanf ("%d", &op);
	switch (op)
	{
		case 1: increasingSort (vetor);
			break;

		case 2: decreasingSort (vetor);
			break;	
	}

	printSorted (vetor);

	free(vetor);

	return 0;
}


int* allocVetor ()
{
	int* vetor = (int*)malloc(sizeof(int) * TAM);
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

	printf ("Entre com os %d valores a serem ordenados.\n", TAM);
	for (i = 0; i < TAM; i++)
		scanf ("%d", &vetor[i]);
}


void increasingSort (int* vetor)
{
	int i, j;
	int aux;

	printf ("Ordenacao crescente:\n");
	for (i = 0; i < TAM; i++)
	{
		for (j = i + 1; j < TAM; j++)
		{
			if (vetor[i] > vetor[j])
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
			//printf ("%d ", vetor[i]);	//Mostra o passo a passo
		}						//da
		//printf ("\n");			//ordenacao
	}					
}


void decreasingSort (int* vetor)
{
	int i, j;
	int aux;

	printf ("Ordenacao decrescente:\n");
	for(i = 0; i < TAM; i++){
        	for(j = i + 1; j < TAM; j++){
            		if(vetor[i] < vetor[j]){
                		aux = vetor[j];
                		vetor[j] = vetor[i];
                		vetor[i] = aux;
            		}
            		//printf("%d ", vetor[i]);  //Mostra o passo a passo
       		}	                                    //da
        	//printf("\n");                     //ordenacao
    	}
}


void printSorted (int* vetor)
{
	int i;

	for (i = 0; i < TAM; i++)
		printf ("%d ", vetor[i]);
	printf ("\n");
}


