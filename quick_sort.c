
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void gerarVetor(int*, int);
void print_vet(int*, int);
void ord(int*, int, int);
void troca(int*, int*);
int mediana3(int*, int, int, int);

int n;

int main(){
	int *vet;
	puts("\n\n\tqnt d elem: ");
	scanf("%d", &n);
	vet=malloc(n*sizeof(int));
	
	gerarVetor(vet, n);
	
	print_vet(vet, n);
	
	ord(vet, 0, n-1);
	print_vet(vet, n);
	//puts("ord");
}



void ord(int *vet, int lo, int hi){
	int pivo, i, bigger;
	
	if (lo < hi){ 
		pivo = mediana3(vet, lo, (lo+hi)/2, hi);
		troca(&vet[pivo], &vet[hi]); 
		bigger = lo; 
		//print_vet(vet, n);
		for (i=bigger; i < hi; i++){ 
			if (vet[i] < vet[hi]){ 
				troca(&vet[i], &vet[bigger]);
				bigger++;
			}
		}
		
		troca(&vet[bigger], &vet[hi]);
		
	
		ord(vet, lo, bigger-1); // recurs~ao parte inferior
		ord(vet, bigger+1, hi); // recurs~ao parte superior
	}
}

void troca(int* num1, int* num2){
	if(num1==num2)
		return;
	int aux;
	aux=*num1;
	*num1=*num2;
	*num2=aux;
	return;
}

int mediana3(int *vet, int lo, int med, int hi){
	if((vet[lo]>=vet[med] && vet[med]>=vet[hi]) || (vet[hi]>=vet[med] && vet[med]>=vet[lo]))
		return med;
	
	if((vet[med]>=vet[lo] && vet[lo]>=vet[hi]) || (vet[hi]>=vet[lo] && vet[lo]>=vet[med]))
		return lo;
		
	if((vet[med]>=vet[hi] && vet[hi]>=vet[lo]) || (vet[lo]>=vet[hi] && vet[hi]>=vet[med]))
		return hi;
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






