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
	//print_vet(vet, n);
}



void ord(int* vet, int n){
	int i, j=n, valor, trocou=1;
	
	while(trocou){
		i=1;
		valor=*(vet);
		trocou=0;	
		puts("\n\n\n\n");
		for(i=1; i<j; i++){
			
			if(valor>vet[i]){
				vet[i-1]=vet[i];
				trocou=1;
				
			}
			
			else{
				vet[i-1]=valor;
				valor=vet[i];
			
			}
			
		}
		vet[i-1] = valor;
		print_vet(vet, n);if(trocou) puts("!!");
		
		valor=vet[i-1];;
		for(i=j-2; i>=0; i--){
			
			if(valor<vet[i]){
				vet[i+1]=vet[i];
				trocou=1;
				
			}
			
			else{
				vet[i+1]=valor;
				valor=vet[i];
			
			}
			
		}
		vet[i+1] = valor;
		print_vet(vet, n);if(trocou) puts("@");
		--j;
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















