#define NULL 0

// # =============== < Variáveis globais. > #
int vitoriasJD = 0, vitoriasPC = 0;
int empates = 0, totalJogos = 0;
int dificuldade;
int primeiraJogada = 1, start = 1;
int moeda = 0;
// # =============== #










// # =============== < "Boot" do jogo. > #
int main(void)
{
	system("title Jogo do Galo");
	int tecla;
	DIF:
		printf("# =============== < Dificuldade > #\n");
		printf("1. Facil\n");
		printf("2. Medio\n");
		printf("3. Dificil\n");
		printf("# =============== #\n");
		printf("Escolha: "); tecla = getche();
		
		if (tecla == '1' || tecla == '2' || tecla == '3')
		{
			dificuldade = tecla;
			jogo();
		}
		else
		{
			system("cls");
			tecla = 0;
			goto DIF;
		}
}
// # =============== #





// # =============== < Pausa. > #
void pausa()
{
	printf("\n\n\nClica em qualquer tecla para continuar...");
	getch();
}
// # =============== #





// # =============== < Jogo. > #
int jogo(void)
{
	system("cls");
	
	// # =============== < Calcular primeiro jogador (jogador / computador). > #
	if (start == 1)
	{
		
		while (moeda == 0)
		{
			srand(time(NULL));
			moeda = rand() % 2;
		}
		
		if (moeda == 1)
		{
			printf("» Primeiro a jogar: Jogador\n\n\n");
		}
		else
		{
			printf("» Primeiro a jogar: Computador\n\n\n");
		}
		
		pausa();
		start = 0;
	}
	// # =============== #
	
	// # =============== < Inicialização da partida. > #
	char e1, e2, e3, e4, e5, e6, e7, e8, e9;
	char tecla;
	int ai, aiPlay, aiPJ;
	int slotsLivres;
	e1 = '1';
	e2 = '2';
	e3 = '3';
	e4 = '4';
	e5 = '5';
	e6 = '6';
	e7 = '7';
	e8 = '8';
	e9 = '9';
	slotsLivres = 9;
	system("cls");
	printf("%c | %c | %c\n", e1, e2, e3);
	printf("----------\n");
	printf("%c | %c | %c\n", e4, e5, e6);
	printf("----------\n");
	printf("%c | %c | %c\n", e7, e8, e9);
	// # =============== #
		
	// # =============== < Codigo principal. > #
	MAIN:
		system("cls");
		printf("%c | %c | %c\n", e1, e2, e3);
		printf("----------\n");
		printf("%c | %c | %c\n", e4, e5, e6);
		printf("----------\n");
		printf("%c | %c | %c\n", e7, e8, e9);
		// # =============== < Verifica se é o jogador o primeiro a jogar. Também recebe a jogada do jogador. > #
		if (moeda == 1)
		{
			printf("\n\nSlot: "); tecla = getch();
			if (tecla == '1' && e1 != 'X' && e1 != 'O')
			{
				e1 = 'X';
				slotsLivres --;
			}
			else if (tecla == '2' && e2 != 'X' && e2 != 'O')
			{
				e2 = 'X';
				slotsLivres --;
			}
			else if (tecla == '3' && e3 != 'X' && e3 != 'O')
			{
				e3 = 'X';
				slotsLivres --;
			}
			else if (tecla == '4' && e4 != 'X' && e4 != 'O')
			{
				e4 = 'X';
				slotsLivres --;
			}
			else if (tecla == '5' && e5 != 'X' && e5 != 'O')
			{
				e5 = 'X';
				slotsLivres --;
			}
			else if (tecla == '6' && e6 != 'X' && e6 != 'O')
			{
				e6 = 'X';
				slotsLivres --;
			}
			else if (tecla == '7' && e7 != 'X' && e7 != 'O')
			{
				e7 = 'X';
				slotsLivres --;
			}
			else if (tecla == '8' && e8 != 'X' && e8 != 'O')
			{
				e8 = 'X';
				slotsLivres --;
			}
			else if (tecla == '9' && e9 != 'X' && e9 != 'O')
			{
				e9 = 'X';
				slotsLivres --;
			}
			else
			{
				goto MAIN;
			}
		}
		// # =============== #
		
		system("cls");
		printf("%c | %c | %c\n", e1, e2, e3);
		printf("----------\n");
		printf("%c | %c | %c\n", e4, e5, e6);
		printf("----------\n");
		printf("%c | %c | %c\n", e7, e8, e9);
		
		// # =============== < Verifica se o jogador ganhou. > #
		if (e1 == 'X' && e2 == 'X' && e3 == 'X' || e4 == 'X' && e5 == 'X' && e6 == 'X' || e7 == 'X' && e8 == 'X' && e9 == 'X' || e1 == 'X' && e4 == 'X' && e7 == 'X' || e2 == 'X' && e5 == 'X' && e8 == 'X' || e3 == 'X' && e6 == 'X' && e9 == 'X' || e1 == 'X' && e5 == 'X' && e9 == 'X' || e3 == 'X' && e5 == 'X' && e7 == 'X')
		{
			vitoriasJD ++;
			totalJogos ++;
			end('2', vitoriasJD, empates, vitoriasPC, totalJogos);
		}
		// # =============== #
		
		// # =============== < Verifica se há empate. > #
		if (slotsLivres != 0)
		{
			ai = 1;
		}
			else
		{
			empates ++;
			totalJogos ++;
			end('1', vitoriasJD, empates, vitoriasPC, totalJogos);
		}
		// # =============== #
		
		// # =============== < Faz com que a A.I. bloqueie uma potencial jogada do jogador caso ele jogue no slot 5 (meio). > #
		if (ai == 1 && dificuldade == 3 && primeiraJogada == 1)
		{
			if (e5 == '5')
			{
				e5 = 'O';
				ai = 0;
				slotsLivres --;
			}
			else if (e5 == 'X')
			{
				primeiraJogada = 0;
				srand(time(NULL));
				AIPJ:
					aiPJ = 0;
					aiPJ = rand()%4;
					if (aiPJ == 1)
					{
						e1 = 'O';
						ai = 0;
						slotsLivres --;
					}
					else if (aiPJ == 2)
					{
						e3 = 'O';
						ai = 0;
						slotsLivres --;
					}
					else if (aiPJ == 3)
					{
						e7 = 'O';
						ai = 0;
						slotsLivres --;
					}
					else if (aiPJ == 4)
					{
						e9 = 'O';
						ai = 0;
						slotsLivres --;
					}
					else
					{
						goto AIPJ;
					}
					
			}
		}
		
		// # =============== < Faz com que a A.I. ganhe o jogo caso haja chance de fazer três em linha. > #
		if (ai == 1 && dificuldade == 2 || ai == 1 && dificuldade == 3)
		{
			if (e1 == '1' && e2 == 'O' && e3 == 'O' || e1 == '1' && e4 == 'O' && e7 == 'O' || e1 == '1' && e5 == 'O' && e9 == 'O')
			{
				e1 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e2 == '2' && e1 == 'O' && e3 == 'O' || e2 == '2' && e5 == 'O' && e8 == 'O')
			{
				e2 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e3 == '3' && e1 == 'O' && e2 == 'O' || e3 == '3' && e5 == 'O' && e7 == 'O' || e3 == '3' && e6 == 'O' && e9 == 'O')
			{
				e3 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e4 == '4' && e1 == 'O' && e7 == 'O' || e4 == '4' && e5 == 'O' && e6 == 'O')
			{
				e4 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e5 == '5' && e1 == 'O' && e9 == 'O' || e5 == '5' && e3 == 'O' && e7 == 'O' || e5 == '5' && e4 == 'O' && e6 == 'O' || e5 == '5' && e2 == 'O' && e8 == 'O')
			{
				e5 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e6 == '6' && e4 == 'O' && e5 == 'O' || e6 == '6' && e3 == 'O' && e9 == 'O')
			{
				e6 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e7 == '7' && e1 == 'O' && e4 == 'O' || e7 == '7' && e3 == 'O' && e5 == 'O' || e7 == '7' && e8 == 'O' && e9 == 'O')
			{
				e7 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e8 == '8' && e2 == 'O' && e5 == 'O' || e8 == '8' && e7 == 'O' && e9 == 'O')
			{
				e8 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e9 == '9' && e1 == 'O' && e5 == 'O' || e9 == '9' && e3 == 'O' && e6 == 'O' || e9 == '9' && e7 == 'O' && e8 == 'O')
			{
				e9 = 'O';
				slotsLivres --;
				ai = 0;
			}
		}
		// # =============== #
		
		// # =============== < Faz com que a A.I. não deixe o jogador ganhar, bloqueando a jogada. > #
		if (ai == 1 && dificuldade == 2 || ai == 1 && dificuldade == 3)
		{
			if (e1 == '1' && e2 == 'X' && e3 == 'X' || e1 == '1' && e4 == 'X' && e7 == 'X' || e1 == '1' && e5 == 'X' && e9 == 'X')
			{
				e1 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e2 == '2' && e1 == 'X' && e3 == 'X' || e2 == '2' && e5 == 'X' && e8 == 'X')
			{
				e2 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e3 == '3' && e1 == 'X' && e2 == 'X' || e3 == '3' && e5 == 'X' && e7 == 'X' || e3 == '3' && e6 == 'X' && e9 == 'X')
			{
				e3 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e4 == '4' && e1 == 'X' && e7 == 'X' || e4 == '4' && e5 == 'X' && e6 == 'X')
			{
				e4 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e5 == '5' && e1 == 'X' && e9 == 'X' || e5 == '5' && e3 == 'X' && e7 == 'X' || e5 == '5' && e4 == 'X' && e6 == 'X' || e5 == '5' && e2 == 'X' && e8 == 'X')
			{
				e5 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e6 == '6' && e4 == 'X' && e5 == 'X' || e6 == '6' && e3 == 'X' && e9 == 'X')
			{
				e6 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e7 == '7' && e1 == 'X' && e4 == 'X' || e7 == '7' && e3 == 'X' && e5 == 'X' || e7 == '7' && e8 == 'X' && e9 == 'X')
			{
				e7 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e8 == '8' && e2 == 'X' && e5 == 'X' || e8 == '8' && e7 == 'X' && e9 == 'X')
			{
				e8 = 'O';
				slotsLivres --;
				ai = 0;
			}
			else if (e9 == '9' && e1 == 'X' && e5 == 'X' || e9 == '9' && e3 == 'X' && e6 == 'X' || e9 == '9' && e7 == 'X' && e8 == 'X')
			{
				e9 = 'O';
				slotsLivres --;
				ai = 0;
			}
		}
		// # =============== #
		
		// # =============== < Faz com que a A.I. tranque o jogador, e, eventualmente ganhe o jogo. > #
		if (ai == 1 && dificuldade == '2' || ai == 1 && dificuldade == '3')
		{
			if (e3 == 'O' && e5 == 'O' && e2 == '2')
			{
				e2 = 'O';
				ai = 0;
				slotsLivres --;
			}
			else if (e1 == 'O' && e5 == 'O' && e4 == '4')
			{
				e4 = 'O';
				ai = 0;
				slotsLivres --;
			}
			else if (e7 == 'O' && e5 == 'O' && e8 == '8')
			{
				e8 = 'O';
				ai = 0;
				slotsLivres --;
			}
			else if (e9 == 'O' && e5 == 'O' && e6 == '6')
			{
				e6 = 'O';
				ai = 0;
				slotsLivres --;
			}
			else if (e1 == 'O' && e3 == 'O' && e2 == 'X' && e5 == '5' && e3 == '3' || e1 == 'O' && e3 == 'O' && e2 == 'X' && e5 == '5' && e9 == '9')
			{
				e5 = 'O';
				ai = 0;
				slotsLivres --;
			}
			else if (e3 == 'O' && e9 == 'O' && e6 == 'X' && e5 == '5' && e1 == '1' || e3 == 'O' && e9 == 'O' && e6 == 'X' && e5 == '5' && e7 == '7')
			{
				e5 = 'O';
				ai = 0;
				slotsLivres --;
			}
			else if (e9 == 'O' && e7 == 'O' && e8 == 'X' && e5 == '5' && e1 == '1' || e9 == 'O' && e7 == 'O' && e8 == 'X' && e5 == '5' && e3 == '3')
			{
				e5 = 'O';
				ai = 0;
				slotsLivres --;
			}
			else if (e7 == 'O' && e1 == 'O' && e4 == 'X' && e5 == '5' && e3 == '3' || e7 == 'O' && e1 == 'O' && e4 == 'X' && e5 == '5' && e9 == '9')
			{
				e5 = 'O';
				ai = 0;
				slotsLivres --;
			}
		}
		// # =============== #
		
		// # =============== < Gera um número aleatório que vai fazer com que a A.I. jogue numa posição ao calhas. > #
		if (ai == 1)
		{
			ai = 0;
			RAND:
				srand(time(NULL));
				aiPlay = rand()%9;
				if (aiPlay == 1)
				{
					if (e1 == 'X' || e1 == 'O')
					{
						goto RAND;
					}
					else
					{
						e1 = 'O';
						slotsLivres --;
					}
				}
				else if (aiPlay == 2)
				{
					if (e2 == 'X' || e2 == 'O')
					{
						goto RAND;
					}
					else
					{
						e2 = 'O';
						slotsLivres --;
					}
				}
				else if (aiPlay == 3)
				{
					if (e3 == 'X' || e3 == 'O')
					{
						goto RAND;
					}
					else
					{
						e3 = 'O';
						slotsLivres --;
					}
				}
				else if (aiPlay == 4)
				{
					if (e4 == 'X' || e4 == 'O')
					{
						goto RAND;
					}
					else
					{
						e4 = 'O';
						slotsLivres --;
					}
				}
				else if (aiPlay == 5)
				{
					if (e5 == 'X' || e5 == 'O')
					{
						goto RAND;
					}
					else
					{
						e5 = 'O';
						slotsLivres --;
					}
				}
				else if (aiPlay == 6)
				{
					if (e6 == 'X' || e6 == 'O')
					{
						goto RAND;
					}
					else
					{
						e6 = 'O';
						slotsLivres --;
					}
				}
				else if (aiPlay == 7)
				{
					if (e7 == 'X' || e7 == 'O')
					{
						goto RAND;
					}
					else
					{
						e7 = 'O';
						slotsLivres --;
					}
				}
				else if (aiPlay == 8)
				{
					if (e8 == 'X' || e8 == 'O')
					{
						goto RAND;
					}
					else
					{
						e8 = 'O';
						slotsLivres --;
					}
				}
				else if (aiPlay == 9)
				{
					if (e9 == 'X' || e9 == 'O')
					{
						goto RAND;
					}
					else
					{
						e9 = 'O';
						slotsLivres --;
					}
				}
				else
				{
					goto RAND;
				}
		}
		// # =============== #
		
		system("cls");
		printf("%c | %c | %c\n", e1, e2, e3);
		printf("----------\n");
		printf("%c | %c | %c\n", e4, e5, e6);
		printf("----------\n");
		printf("%c | %c | %c\n", e7, e8, e9);
		
		// # =============== < Muda a moeda para 1, para que o jogador possa jogar caso não tenha sido o primeiro a jogar. > #
		moeda = 1;
		// # =============== #
			
		// # =============== < Verifica se o jogador ganhou. > #
		if (e1 == 'X' && e2 == 'X' && e3 == 'X' || e4 == 'X' && e5 == 'X' && e6 == 'X' || e7 == 'X' && e8 == 'X' && e9 == 'X' || e1 == 'X' && e4 == 'X' && e7 == 'X' || e2 == 'X' && e5 == 'X' && e8 == 'X' || e3 == 'X' && e6 == 'X' && e9 == 'X' || e1 == 'X' && e5 == 'X' && e9 == 'X' || e3 == 'X' && e5 == 'X' && e7 == 'X')
		{
			vitoriasJD ++;
			totalJogos ++;
			end('2', vitoriasJD, empates, vitoriasPC, totalJogos);
		}
		// # =============== #
		
		// # =============== < Verifica se o computador ganhou. > #
		if (e1 == 'O' && e2 == 'O' && e3 == 'O' || e4 == 'O' && e5 == 'O' && e6 == 'O' || e7 == 'O' && e8 == 'O' && e9 == 'O' || e1 == 'O' && e4 == 'O' && e7 == 'O' || e2 == 'O' && e5 == 'O' && e8 == 'O' || e3 == 'O' && e6 == 'O' && e9 == 'O' || e1 == 'O' && e5 == 'O' && e9 == 'O' || e3 == 'O' && e5 == 'O' && e7 == 'O')
		{
			vitoriasPC ++;
			totalJogos ++;
			end('3', vitoriasJD, empates, vitoriasPC, totalJogos);
		}
		// # =============== #
		
		// # =============== < Verifica se ainda há slots livres. Se não, acaba o jogo. > #
		else if (slotsLivres == 0)
		{
			empates ++;
			totalJogos ++;
			end('1', vitoriasJD, empates, vitoriasPC, totalJogos);
		}
		// # =============== #
			
		goto MAIN;
}
// # =============== #





// # =============== < Ecrã de fim de partida. > #
int end(int razao, int vitoriasJD, int empates, int vitoriasPC, int totalJogos)
{
	int ratJD, ratPC;
	
	ratJD = 0;
	ratPC = 0;
	
	system("cls");
	char tecla;
	
	// # =============== < Mostra a razão pelo qual a partida acabou. > #
	if (razao == '1')
	{
		printf("Ja nao ha mais slots livres.\nEmpate!");
	}
	else if (razao == '2')
	{
		printf("O jogador sai vencedor!");
	}
	else if (razao == '3')
	{
		printf("Computador ganha!");
	}
	// # =============== #
	
	// # =============== < Calcula a percentagem de vitória. > #
	if (vitoriasJD != 0 || vitoriasPC != 0)
	{
		ratJD = (vitoriasJD * 100) / (totalJogos - empates);
		ratPC = (vitoriasPC * 100) / (totalJogos - empates);
	}
	// # =============== #
	
	// # =============== < Mostra os resultados. > #
	printf("\n\n# =============== < Scores > #\n");
	printf("Jogador:\n >>>>> Vitorias: %i.  |||  %i%%\n", vitoriasJD, ratJD);
	printf("Computador:\n >>>>> Vitorias: %i.  |||  %i%%\n", vitoriasPC, ratPC);
	printf("\n----------\n");
	printf("Empates: %i.\n", empates);
	printf("Jogos: %i.\n", totalJogos);
	printf("# =============== #\n");
	// # =============== #
	
	// # =============== < Pergunta ao jogador se quer jogar denovo. > #
	printf("\n\nJogar de novo? (y/n)"); tecla = getch();
	if (tecla == 'y' || tecla == 'Y')
	{
		primeiraJogada = 1;
		jogo();
	}
	else if (tecla == 'n' || tecla == 'N')
	{
		exit(0);
	}
	else
	{
		end(razao, vitoriasJD, empates, vitoriasPC, totalJogos);
	}
	// # =============== #
}
// # =============== #
