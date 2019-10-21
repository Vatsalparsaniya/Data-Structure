/*
    input: a unsorted array
    output: a sorted array using Counting Sort algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void countingSort(int *vet,int *org, int tam){
    int i, j, k;
    int baldes[MAX];

    //Cria um vetor zerado com todos os indices de dados possíveis
    for(i = 0 ; i < MAX ; i++)
        baldes[i] = 0;

    //Marca as ocorrência dos dados a serem ordenados no vetor dos indices
    for(i = 0 ; i< tam ; i++)
        baldes[vet[i]]++;

    //Faz a distribuição de quantidade ao longo de todo o vetor.
    for(i = 1 ; i < MAX ; i++){
        baldes[i] = baldes[i] + baldes[i-1];
    }

    //Preenche o vetor de saída com as ocorrência presentes no vetor de indice.
    for(i = (tam-1) ; i >=0 ; i--){
        org[baldes[vet[i]]] = vet[i];
        baldes[vet[i]]--;
    }
}

int main(){
    int *vet, *org;
    int i, tam;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tam);
    

    vet = (int*)malloc(tam*sizeof(int));
    org = (int*)malloc(tam*sizeof(int));

    printf("Entre com os valores dos elementos\n");
    for(i = 0 ; i < tam ; i++){
        printf("Elemento %d: ",i+1);
        scanf("%d", &vet[i]);
    }

    printf("Seu vetor desordenado\n");
    for(i = 0 ; i < tam ; i++){
        printf("%d\t", vet[i]);
    }

    countingSort(vet, org,tam);

    printf("\nSeu vetor Ordenado\n");
    for(i = 1 ; i < tam+1 ; i++){
        printf("%d\t", org[i]);
    }
    return 0;
}