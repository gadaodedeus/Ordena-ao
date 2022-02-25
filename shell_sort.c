#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void gerarVetor(int*, int);
void print_vet(int*, int);
void ord(int*, int);

int main(){
	int n, *vet;
	puts("\n\n\tqnt d elem: ");
	scanf("%d", &n);
	vet=malloc(n*sizeof(int));
	
	gerarVetor(vet, n);
	
	//print_vet(vet, n);
	
	ord(vet,n);
	//print_vet(vet, n);
	puts("ord");
}



void ord(int* vet, int n){
	int i, j, k, l, valor;
	k = 1;
	while (k < n/2)
		k = 3*k + 1; // calcula passo inicial
	while (k != 1)
		{ k = k/3;
		for (l=0; l<k; l++){ // insertion ajustado para passo k
	
			for (i=l+k; i<n; i=i+k){
				valor = vet[i];
				j = i;
				while (j-k>=0 && vet[j-k] > valor){ 
					vet[j] = vet[j-k];
					j=j-k;
				}
				vet[j] = valor;
			}
		}
	
	}
	return;
}








void print_vet(int* vet, int n){
	int i=0;
	puts("\n\n");
	for(i=0; i<n; i++)
		printf("\t[%d]", *(vet+i));
	return;
}

void gerarVetor(int *vet, int n){
	int i=0;
	srand(time(NULL));
	for (i = 0;i < n;i++) 
    	vet[i] = rand() % (n * 10);    
}















