#include <time.h>

#define CHAO 0
#define PAREDE 1
#define PERSONAGEM 5
#define BAU 2
#define MONSTRO 3
#define SAIDA 4

#define TAM 10

#define ACIMA 119
#define ABAIXO 115
#define DIREITA 100
#define ESQUERDA 97

int tecla, linha = 1, coluna = 1;

int labirinto[TAM][TAM*2] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,1,8,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,
	1,0,1,0,0,0,1,0,1,0,1,1,0,1,1,1,1,1,0,1,
	1,0,1,0,1,1,0,0,1,9,1,0,1,1,9,0,1,1,0,1,
	1,0,0,0,1,0,0,1,0,1,1,0,0,0,1,0,1,0,0,1,
	1,1,1,0,1,1,0,1,0,1,0,0,1,0,0,0,0,0,1,1,
	1,9,0,0,1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,1,
	1,1,1,1,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,
	1,8,0,0,0,1,8,1,0,0,0,1,0,1,1,0,1,1,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,1,
};

int dungeon_1[TAM*2+1][TAM*2+1] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
    1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
    1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1,
    1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 8, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
    1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
    1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1,
    1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,
    1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
    1, 9, 0, 0, 0, 0, 1, 8, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1,
};

int boss[TAM][TAM] = {};

int aleLab[TAM*2+1][TAM*2+1];


void gera_mapa(){
	srand(time(NULL));
	int linha, coluna;
	if(andar == 1){
		linha  = TAM-1;
		coluna = (TAM*2)-1;
	}else if(andar == 2){
		linha  = (TAM*2)-1;
		coluna = (TAM*2)-1;
	}
	int mon = 1;
	for(int i = 1; i < linha; i++){
		for(int j = 1; j < coluna; j++){
			if(aleLab[i][j] == 0){
				aleLab[i][j] = rand()%8+2;
			}if(aleLab[i][j] == 2){
				mon++;
				if(mon>15)
					aleLab[i][j] = 0;
			}
		}
	}
}

void mostraMapa(int andar){
	int lin, col;
	if(andar == 1){
		lin  = TAM;
		col  = (TAM*2);
	}else if(andar == 2){
		lin  = (TAM*2)+1;
		col  = (TAM*2)+1;
	}
	printf("\nStatus:\n%s, HP: %d, Atq: %d, Def: %d, Vlc: %d\n",nome,iHp,iAtq,iDef,iVlc);
	printf("Inventario :\nPocoes >> %d\n",pocao);
	//PRIMEIRO ANDAR
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col; j++){
			if ((i == linha) && (j == coluna)) {
                printf("&");
                continue;
            }if(aleLab[i][j] != PAREDE && aleLab[i][j] != BAU){
				printf(".");
			}if(aleLab[i][j] == PAREDE){
				printf("%c",178);
			}if(aleLab[i][j] == BAU){
				printf("?");
			}
		}
		printf("\n");
	}
	
}
//Quando encontra um bau, sorteia o resultado.
void bonus(){
	srand(time(NULL));
    int numero_sortido1 = rand()%10;
	printf("Voce optou por abrir o bau.\nSera rolado um dado de sorte para saber o que voce encontrou.\n");
	
	if(numero_sortido1>=6){
	  printf("Voce caiu em uma Armadilha -2 de hp\n");
	  iHp-=2;
	}
	else if(numero_sortido1<=5){
	  printf("Voce encontrou uma pocao de restaurar H.P.");
	  pocao++;
	}
}

int lab(){
	char flag ='n';
	///////////////////////
	//Escolha dos andares//
	///////////////////////
	if(andar == 1){
		for(int i = 0; i < TAM*2+1; i++){
			for(int j = 0; j < TAM*2+1; j++){
				aleLab[i][j] = labirinto[i][j];
			}
		}
	}else if(andar == 2){
		for(int i = 0; i < TAM*2+1; i++){
			for(int j = 0; j < TAM*2+1; j++){
				aleLab[i][j] = dungeon_1[i][j];
			}
		}
	}else if(andar == 3){
		for(int i = 0; i < TAM*2+1; i++){
			for(int j = 0; j < TAM*2+1; j++){
				aleLab[i][j] = boss[i][j];
			}
		}
	}
	
	//Laço de movimentação
	do{
		gera_mapa();
		mostraMapa(andar);
		do{
			tecla=getch();
			if(tecla == ACIMA){
				linha-=1;
				if(aleLab[linha][coluna] == 1){
					linha++;
				}
				system("cls");
				mostraMapa(andar);
			}
			if(tecla == DIREITA){
				
				coluna+=1;
				if(aleLab[linha][coluna] == 1){
					coluna--;
				}
				system("cls");
				mostraMapa(andar);
			}if(tecla == ABAIXO){
				linha+=1;
				if(aleLab[linha][coluna] == 1){
					linha--;
				}
				system("cls");
				mostraMapa(andar);
			}if(tecla == ESQUERDA){
				coluna-=1;
				if(aleLab[linha][coluna] == 1){
					coluna++;
				}
				system("cls");
				mostraMapa(andar);
			}
			if(aleLab[linha][coluna] == MONSTRO){
				batalha();	
				aleLab[linha][coluna] = 0;
				system("cls");
				mostraMapa(andar);
			}if(aleLab[linha][coluna] == BAU){
				char esc;
				system("cls");
				setbuf(stdin,NULL);
				printf("\tVoce encontrou um Bau!!!\nDeseja abrir y/n? ");
				scanf("%c",&esc);
				if(esc == 'y'){
					bonus();
					aleLab[linha][coluna] = 0;
					system("pause");
					system("cls");
					mostraMapa(andar);
				}else{
					system("cls");
					mostraMapa(andar);
				}
			}
			if(iHp < 1){
				printf("Voce Morreu!!!");
				andar--;
				break;
			}
		}while(aleLab[linha][coluna] != 10);
		printf("Deseja continuar y/n: ");
		andar++;
		setbuf(stdin, NULL);
		scanf("%c",&flag);
	}while(flag != 'y');
	linha = 1, coluna = 1;
	system("cls");
	return andar;
}
