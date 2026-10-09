#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id;
	char nome[20];
	char especie[20];
	int idade;
	int adotado; //1 Sim / 0 não
} Pet;

void adicionarAnimal(Pet, int);

int main(){
	
	
	
}
void adicionarAnimal(Pet *vetor ,int qtd){
	printf(" \n Digite o ID: ");
    scanf("%d", &vetor->id);

    printf(" \n Digite o nome do animal: ");
    scanf("%s", vetor->nome); 

    printf(" \n Digite a especie do animal (Ex: Gato/Cao): ");
    scanf("%s", vetor->especie);

    printf(" \n Digite a Idade do animal: ");
    scanf("%d", &vetor->idade);

    vetor->adotado = 0;
}	
	
