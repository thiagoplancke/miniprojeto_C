#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id;
	char nome[20];
	char especie[20];
	int idade;
	int adotado; //1 Sim / 0 não
} Pet;

void adicionarAnimal(Pet*, int*);

int main(){
	
	
	
}
void adicionarAnimal(Pet **vetor ,int *qtd, int *tamanho){
	if(*qtd == *tamanho){
		(*tamanho) *= 2;
		
		Pet *temp = (Pet *) realloc(*vetor, (*tamanho) * sizeof(Pet));
		if (temp == NULL) {
            printf("Erro ao realocar memória! Não foi possível adicionar mais pets.\n");
            *tamanho /= 2; 
            return;
        }

        *vetor = temp;
        printf("\n[AVISO]: Capacidade atingida! Vetor expandido para %d posições.\n", *tamanho);
    
	}
	
	printf(" \n Digite o ID: ");
    scanf("%d", &(*vetor)[*qtd].id);

    printf(" \n Digite o nome do animal: ");
    scanf("%s", (*vetor)[*qtd].nome); 

    printf(" \n Digite a especie do animal (Ex: Gato/Cao): ");
    scanf("%s", (*vetor)[*qtd].especie);

    printf(" \n Digite a Idade do animal: ");
    scanf("%d", &(*vetor)[*qtd].idade);

    (*vetor)[*qtd].adotado = 0;
    
    (*qtd) ++;
}	
	
