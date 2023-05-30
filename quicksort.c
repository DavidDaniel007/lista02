#include <stdio.h>
#include <stdlib.h>
//vai realizar a troca entre o pivo esquerdo e o direito do array
void swap(int vetor[], int l, int r)
{
	int aux = vetor[l];
	vetor[l] = vetor[r];
	vetor[r] = aux;
}
//função que passará de casa em casa chamando a função "swap"
int particiona(int vetor[], int inicio, int fim)
{
	int pivo, indice, l;
	
	pivo = vetor[fim];
	indice = inicio;
	
	for(l = inicio; l < fim; l++)
	{
		if(vetor[l] <= pivo)
		{
			swap(vetor, l, indice);
			indice++;
		}
	}
	
	swap(vetor, indice, fim);
	
	return indice;
}
//função quicksort que vai realizar a recursão
void quickSort(int vetor[], int inicio, int fim)
{
	if(inicio < fim)
	{
		int indice = particiona(vetor, inicio, fim);
		
		quickSort(vetor, inicio, indice - 1);
		quickSort(vetor, indice + 1, fim);
	}
}

int main()
{
	int vetor[] = {10,57,4,89,100,-12,-27,12,34,58,26,2,1}; //aqui são inseridos os valores do array
	int vetorSize = sizeof(vetor) / sizeof(int);
	int l;
	 
	quickSort(vetor, 0, vetorSize - 1);
	//responsável por passar a array printando os valores na tela
	for(l = 0; l < vetorSize; l++)
		printf("%d ", vetor[l]);
	
	return 0; 
}