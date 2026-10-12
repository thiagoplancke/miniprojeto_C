#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char nome[20];
	char especie[20];
	int idade;
	int adotado; //1 Sim / 0 não
} Pet;

void adicionarAnimal(Pet**, int*, int*);
void consultarAnimal(Pet*, int);
void alterarInfo(Pet*, int);
void gerarRelatorio(Pet*r,int);



int main(){
	int op;
	int qtd = 0;
	int tam = 1;
	Pet *lista;
	
	lista = (Pet *) malloc(tam* sizeof(Pet));
	if (lista == NULL) {
	    printf("\nErro: Não foi possível alocar memória inicial!\n");
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
            case 2:
            	consultarAnimal(lista, qtd);
            	break;
            
            case 3:
            	alterarInfo(lista,qtd);
            	break;
            	
            case 4:
            	gerarRelatorio(lista,qtd);
            	break;
            	
            	
            	

            case 5:
                free(lista);
                printf("\n Encerrando o programa... Ate logo!\n");
                return 0; 
            default:
                printf("\n Opcao invalida! Tente novamente.\n");
                break;
        }
		
		
	}
	
	
}


void adicionarAnimal(Pet **vetor ,int *qtd, int *tamanho){
	if(*qtd == *tamanho){
		(*tamanho) *= 2;
		
		Pet *temp = (Pet *) realloc(*vetor, (*tamanho) * sizeof(Pet));
		if (temp == NULL) {
            printf("\nErro ao realocar memória! Não foi possível adicionar mais pets.\n");
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


void consultarAnimal(Pet *vetor, int qtd){
	int op2;
	printf("\n Voce quer consultar animais por ID ou especie?\n\n ID digite 1 \n Especie digite 2 \n\n");
	scanf("%i",&op2);
	switch(op2){
		case 1:
			{
				
				int id;
	    		printf("\n Digite o ID do animal: ");
				scanf("%i",&id);
				for(int i = 0;i<qtd;i++){
					if(vetor[i].id == id){
						printf("\n ID: %i \n Nome: %s \n Especie: %s \n Idade: %i \n Adotado: %i",vetor[i].id,vetor[i].nome,vetor[i].especie,vetor[i].idade,vetor[i].adotado );
						break;
				}			
			}
			break;	
			}
			
		
		case 2:
			{
				
				char esp[20];
				printf("\n Digite a especie de animal que deseja consultar: ");
				scanf("%s", esp);
				for(int i = 0;i<qtd;i++){
					if (strcmp(vetor[i].especie, esp) == 0) {
						printf("\n____________________\n ID: %i \n Nome: %s \n Especie: %s \n Idade: %i \n Adotado: %i",vetor[i].id,vetor[i].nome,vetor[i].especie,vetor[i].idade,vetor[i].adotado );
	
						}
				}
				break;	
			}
			
			
	
		default:
			printf("\n Digite um numero valido!");
			break;		
	}
	
	
}

void alterarInfo(Pet *vetor, int qtd){
	int id;
	printf("\n Digite o ID do animal que voce deseja alterar: ");
	scanf("%i",&id);
	for(int i = 0;i<qtd;i++){
		if(vetor[i].id == id){
			int op3;
			printf("\n 1.alterar condicao para adotado \n 2.alterar idade");
			scanf("%i",&op3);
			switch(op3){
				case 1:
					vetor[i].adotado = 1;
					break;
				case 2:
					int idade;
					printf("\nDigite a nova idade do animal: ");
					scanf("%i",&idade);
					vetor[i].idade = idade;
					break;
				default:
					printf("\nDigite um numero valido!");
					break;	
			}
			break;
			}
			
		
	}			
}

void gerarRelatorio(Pet *vetor, int qtd){
	int total = 0;
	
	for(int i = 0; i < qtd; i++){
		if(vetor[i].adotado == 1){
			
			printf("\n____________________\n ID: %i \n Nome: %s \n Especie: %s \n Idade: %i \n Adotado: %i",vetor[i].id,vetor[i].nome,vetor[i].especie,vetor[i].idade,vetor[i].adotado );

			total ++;
		}
	}
	
	printf("\nTotal de adotados: %i",total);
	
	
}

	



	
	
