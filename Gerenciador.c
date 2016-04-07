#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CLEAR "CLS" //Se for no Windows = "CLS", Se for no Linux = "clear"

//ESCOPO FUNÇÕES

int configuracoesIniciais (void);
int cadastrarJogador (void);
int configurarBlinds (void);
int configurarValores (void);
void revisao (void);

//ESTRUTURAS GLOBAIS

struct participantes
{
	char nome[100];
	int quantidadeFichas;
	float valorGasto;
} jogadores[10];

//VARIÁVEIS GLOBAIS

int numeroParticipantes=0;
float valorBuyIn=0;
float valorReBuy=0;
int fichasIniciais=0;
int tempoNivel=0;

//FUNÇÃO PRINCIPAL
void main (void) {
    int tempo = 10;
	configuracoesIniciais();
    while (tempo) {
        system(CLEAR);
        printf("Torneio configurador com sucesso!\nBoa Sorte a todos os Jogadores!\n");
        printf("Iniciando em %d...", tempo--);
        sleep (1);
    }
}

int configuracoesIniciais (void) {
	for (;;) {	//LOOP INFINITO PARA QUE O USUÁRIO POSSA CADASTRAR NA ORDEM QUE LHE CONVÉM
		int opcao = 0;	//VARIÁVEL DE CONTROLE DE OPÇÃO
		do {
			system(CLEAR);
			printf("1- Cadastrar Jogador\n");
			printf("2- Configurar Blinds\n");
			printf("3- Configurar Valores Buy-In / Rebuy\n");
			printf("4- Revisar e iniciar Torneio\n");
			scanf ("%d", &opcao);
		} while ((opcao > 4) || (opcao <= 0));
		switch (opcao) {
			case 1:
				if (cadastrarJogador() == 1) {
					printf("Jogador Cadastrado com Sucesso!\n");
                    sleep (2);
					numeroParticipantes++;
				}
				break;
			case 2:
				if (configurarBlinds() == 1) {
					printf("Blinds Configurados com Sucesso!\n");
					sleep (2);
				}
				break;
			case 3:
				if (configurarValores() == 1) {
					printf("Valores Buy-In / Rebuy Configurados com Sucesso!\n");
					sleep (2);
				}
				break;
			case 4:
				revisao();
				return 1;
		}
	}
}


//FAZ CADASTRO DE UM NOVO JOGADOR NA ESTRUTURA
int cadastrarJogador (void) {
	system (CLEAR);
	printf("Nome: ");
	scanf (" %[^\n]s", jogadores[numeroParticipantes].nome);
	jogadores[numeroParticipantes].valorGasto = valorBuyIn;
	jogadores[numeroParticipantes].quantidadeFichas = fichasIniciais;
	return 1;
}

int configurarBlinds (void) {
	system (CLEAR);
	printf("Tempo (minutos) em cada nivel: ");
	scanf ("%d", &tempoNivel);
	return 1;
}

//CONFIGURA VALORES E APLICA OS VALORES INICIAIS EM TODOS OS JOGADORES JÁ CADASTRADOS NA ESTRUTURA
int configurarValores (void) {
	int i = 0;
    system (CLEAR);
	printf("Valor para Buy-In: ");
	scanf ("%f", &valorBuyIn);
	printf("Valor para Re-Buy: ");
	scanf ("%f", &valorReBuy);
	printf("Quantidade de Fichas iniciais / Rebuy: ");
	scanf ("%d", &fichasIniciais);

	for (i = 0; i < numeroParticipantes; i++) {
		jogadores[i].valorGasto = valorBuyIn;
		jogadores[i].quantidadeFichas = fichasIniciais;
	}
	return 1;
}

void revisao (void) {
	int i = 0;
	int comando = 0;
	system (CLEAR);
	printf("Jogadores Cadastrados:\n");
	printf("%2s | %-30s | Valor Gasto\n", "", "Nome");
	for (i = 0; i < numeroParticipantes; i++) {
		printf("%2d | %-30s | R$%.2f\n", i+1, jogadores[i].nome, jogadores[i].valorGasto);
	}
	printf("\nValor Buy-In: R$%.2f\n", valorBuyIn);
	printf("Valor Re-Buy: R$%.2f\n", valorReBuy);
	printf("Fichas Iniciais para cada jogador: %d\n", fichasIniciais);
	printf("Tempo em cada nivel: %d minutos\n", tempoNivel);

	printf("\n\n1- Confirmar\n");
	printf("2- Voltar para Configuracoes\n");

	scanf ("%d", &comando);

	if (comando == 1) {
        return;
	}
	if (comando == 2) {
        configuracoesIniciais();
	}
}