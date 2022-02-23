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
	int i, aux, menor, ref=0, flag=0;
	
	while(ref+1!=n){
		menor=ref;
		
		for(i=ref; i<=n; i++){
			if(*(vet+i)<*(vet+menor)){
				menor=i;
				flag=1;
			}
		}
		if(flag){
			aux=*(vet+ref);
			*(vet+ref)=*(vet+menor);
			*(vet+menor)=aux;
			flag=0;
		}
		
		ref++;
		
		
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















