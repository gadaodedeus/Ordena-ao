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
	
	print_vet(vet, n);
	
	ord(vet,n);
	print_vet(vet, n);
}



void ord(int* vet, int n){
	int i, j, valor;
	
	for(i=1; i<n; i++){
		valor=*(vet+i);
		j=i;
		while(j>0 && *(vet+(j-1))>valor){
			*(vet+j)=*(vet+(j-1));
			j--;
		}
		*(vet+j)=valor;
		//print_vet(vet, n);
	}
	
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















