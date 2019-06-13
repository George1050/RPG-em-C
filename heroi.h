	/////////////////////////
	//ATRIBUTO DOS MONSTROS//
	/////////////////////////
struct monstro{
	int mHp;
	char tipo[20];
	int mAtq;
	int mVlc;
	int mDef;
	
}Mon;

//FLAG DA BATALHA
int vd = 0;

void cadMon(int andar){
	if(andar == 1 || andar == 2){
		Mon.mHp = 25; sprintf(Mon.tipo,"Goblin");
		Mon.mAtq = 4; Mon.mDef = 3; Mon.mVlc = 5;
	}else{
		Mon.mHp = 50; sprintf(Mon.tipo,"Orc - Boss");
		Mon.mAtq = 15; Mon.mDef = 16; Mon.mVlc = 3;
	}
	
}
	//////////////////////
	//INVENTARIO//////////
	//////////////////////
	//ATRIBUTOS DO HEROI//
	//////////////////////
	int andar = 1;
	char nome[20];
	int iHp = 20;
	int iAtq;
	int iDef;
	int iVlc;
	int pocao;
	int classe;

//Atributos das classes
void classePer(){
	
	if(classe==1){
		printf("O Guerreiro tem muita vida porem atrai monstros!!!\n"
		"Chances mais altas de chegar ao fim do labirinto!!!\n");
	}else if(classe == 2){
		printf("O Mago tem pouca vida e sorte media, porem com muita sabedoria!!!"
		"\nChances mais altas de nao cair em Amadilhas!!!\n");
	}else if(classe == 3){
		printf("O Ladrao tem vida media, baixa sabedoria porem com muita sorte!!!\n"
		"Altas chances de encontrar nem monstros nem armadilhas!!!");
	}
}

//Cadastra o heroi
int cadHeroi(){
	char esc;	
	printf("Cadastre seu personagem: \nNome: ");
	gets(nome);
	printf("Escolha a Classe: \n1.Guerreiro, 2.Mago e 3.Ladrao\n>>");
	scanf("%d",&classe);
	setbuf(stdin,NULL);
	classePer(classe);
	system("pause");
	system("cls");
	do{
		printf("\nDistribua os pontos de habilidade: OBS: 5p\nAtaque: %d\nDefesa: %d\nVelocidade: %d\n>>",iAtq, iDef, iVlc);
		scanf("%d %d %d",&iAtq, &iDef, &iVlc);
		setbuf(stdin,NULL);
		printf("\nDeseja redistribuir os pontos, y/n? ");
		scanf("%c",&esc);
		setbuf(stdin,NULL);
		printf("\nAtaque: %d\nDefesa: %d\nVelocidade: %d\n",iAtq, iDef, iVlc);
	}while(esc != 'n');
	printf("Enfim se inicia sua Aventura pelo Labirinto\n");
}

//Escolha do Jogador
int iteracao(int acao){
	//ATACAR
	int cont = 0;
	char sup;
	if(acao == 1){
		if(cont == 5){
			printf("Seu golpe pesado carregou deseja usar y\n: ");
			scanf("%c",&sup);
			setbuf(stdin,NULL);
			if(sup == 'y'){
				Mon.mHp -= iAtq*2;
				printf("Golpe Critico, - %d",iAtq*2);
			}
			cont = 0;
		}
		//Se Def < Atq,o resultado da subitração vai ser retirado do Hp do monstro
		else if(Mon.mDef - iAtq < 0){
			Mon.mHp += Mon.mDef - iAtq;
			printf("==========================\n"
				   "=Voce causou dano de : %d=\n"
				   "==========================\n",Mon.mDef-iAtq);
			cont++;
		}
		//Se Def > Atq, subitrair -1 do Hp do monstro
		else if(Mon.mDef - iAtq > 0){
			Mon.mHp--;
			Mon.mDef--;
			printf("==========================\n"
				   "=Voce causou dano de : -1=\n"
				   "==========================\n");
			cont++;
		}
		//Não ouve dano algum
		else if(Mon.mDef - iAtq == 0){
			cont++;
			printf("================\n"
				   "=Ataque fraco!!=\n"
				   "================\n");
		}
	}
	//Defender um Ataque
	else if(acao == 2){
		if(iDef - Mon.mAtq < 0){
			iHp += iDef - Mon.mAtq;
			printf("=============================\n"
				   "=Voce recebeu o dano de : %d=\n"
				   "=============================\n",iDef - Mon.mAtq);
		}
		else if(iDef - Mon.mAtq > 0){
			iHp--;
			iDef--;
			printf("=============================\n"
				   "=Voce recebeu o dano de : -1=\n"
				   "=============================\n");
		}
		else if(iDef - Mon.mAtq == 0){
			printf("================\n"
				   "=Defesa fraca!!=\n"
				   "================\n");
		}
	}
	//Usar poção
	else if(acao == 3){
		iHp += pocao;
		pocao--;
	}
	//Ação para fugir
	else if(acao == 4){
		//funcSorte();
		int sfuga = rand()%10;
		if(sfuga<=4){
			vd = 4;
		}
	}
}

//Cenario de Batalha
void batalha(){

	system("cls");
	int tempo = 100;
	int acao;
	cadMon(andar);
	printf("\nVoce foi Atacado por um %s\n",Mon.tipo);
	do{
		//Verifica se a velocidade do monstro é maior
		if(tempo/iVlc >= tempo/Mon.mVlc){
			acao = 2;
			iteracao(acao);
		}
		//senao for o heroi ataca primeiro
		printf("\n\nStatus:\n%s, HP: %d, Atq: %d, Def: %d, Vlc: %d\n",nome,iHp,iAtq,iDef,iVlc);
		printf("Monstro:\n%s, HP: %d, Atq: %d, Def: %d, Vlc: %d\n",Mon.tipo,Mon.mHp,Mon.mAtq,Mon.mDef,Mon.mVlc);
		printf("Inventario de Pocoes >> %d\n",pocao);
		printf("\n1.Atque\n2.Defender\n3.Fugir\n4.Pocao\n>>");
		scanf("%d",&acao);
		system("CLS");
		iteracao(acao);
		if(Mon.mHp <= 0){
			printf("\nVoce derrotou o %s\n",Mon.tipo);
			vd = 1;
		}if(iHp <= 0){
			printf("\nVoce Morreu\n");
			vd = 1;
		}if(vd == 4){
			printf("Fuga com sucesso!!!");
		}
	}while(vd == 0);	
}
