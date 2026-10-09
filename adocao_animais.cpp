#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id;
	char nome[20];
	char especie[20];
	int idade;
	int adotado; //1 Sim / 0 não
} Pet;

void adicionarAnimal(Pet**, int*, int*);

int main(){
	int op;
	int qtd = 0;
	int tam = 1;
	Pet *lista;
	
	lista = (Pet *) malloc(tam* sizeof(Pet));
	if (lista == NULL) {
	    printf("Erro: Não foi possível alocar memória inicial!\n");
	    return 1;
	}
	
	while(1){
		printf("\n--- MENU DE PETS ---\n");
        printf("1. Adicionar Pet\n");
        printf("2. Consultar Pet\n");
        printf("3. Alterar Idade ou condicao\n");
        printf("4. Relatorio\n");
        printf("5. Sair\n");
        printf("Digite o numero de uma opcao: ");
				
		scanf("%i",&op);
		
		switch (op) {
            case 1:
        
                adicionarAnimal(&lista, &qtd, &tam);
                break;
            case 5:
                free(lista);
                printf("Encerrando o programa... Ate logo!\n");
                return 0; 
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
		
		
	}
	
	
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
	
