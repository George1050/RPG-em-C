#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "heroi.h"
#include "dungeon.h"


void tela(){

	
}
//ATRIBUI OS PONTOS DE HABILIDADE

void load(){
	for(int i = 0; i<5;i++){
		printf("Load.");
		system("cls");
		printf("Load..");
		system("cls");
		printf("Load...");
		system("cls");
	}
}
int main(){
	int escolha = 0;
	do{
		printf("\n\t\tLABIRINTIA\n========================================\n");
		printf(" 1.Iniciar \t2.Sobre \t3.Sair\n>>");
		scanf("%d",&escolha);
		setbuf(stdin,NULL);
		if(escolha == 1){
			cadHeroi();
			printf("Se inicia a sua jornada %s",nome);
			system("pause");
			do{
				if(andar <= 3){
					load();
					andar = lab();0
				}else{
					printf("\tObrigado por Jogar!!!\n");
					escolha = 3;
				}
			}while(andar != 4);
		}else if(escolha == 2){
			system("cls");
			printf("\nEste jogo foi criado por George Ravelly da Silva Ribeiro!!!\n");
			system("pause");
			system("cls");
		}else if(escolha == 3){
			printf("\tObrigado pela sua atencao!!!\n");
		}else{
			printf("Opcao Invalida");
		}
	}while(escolha!=3);
	return 0;
}
