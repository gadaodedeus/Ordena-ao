
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void gerarVetor(int*, int);
void print_vet(int*, int);
void ord(int, int, int*, int*);

int n;

int main(){
	int *vet, *vetaux;
	puts("\n\n\tqnt d elem: ");
	scanf("%d", &n);
	
	vet=(int*)malloc(n*sizeof(int));
	vetaux=(int*)malloc(n*sizeof(int));
	
	gerarVetor(vet, n);
	
	print_vet(vet, n);
	
	ord(0,n-1, vet, vetaux);
	print_vet(vet, n);
	//puts("ord");
}



void ord(int i, int j, int* a, int* aux){
	int k, mid, ptr_esq, ptr_dir;
	if (j <= i)
		return; 
	mid = (i + j) / 2;
	ord(i, mid, a, aux); 
	ord(mid + 1, j, a, aux);
	ptr_esq = i; ptr_dir = mid + 1; k = i;

	while (ptr_esq <= mid && ptr_dir <= j)
		{ if (a[ptr_esq] < a[ptr_dir]) // menor valor no vetor anterior
			{ aux[k] = a[ptr_esq]; ptr_esq++; }
		else // caso contrario no vetor posterior
			{ aux[k] = a[ptr_dir]; ptr_dir++; }
		k++;
	}
	if (ptr_esq > mid) // se terminou vetor anterior
		{ while (ptr_dir <= j)
			{ aux[k] = a[ptr_dir]; ptr_dir++; k++; }
	}
	else // ou se terminou vetor posterior
		{ while (ptr_esq <= mid)
			{ aux[k] = a[ptr_esq]; ptr_esq++; k++; }
	}
	for (k = i; k <= j; k++)
		a[k] = aux[k];	
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

