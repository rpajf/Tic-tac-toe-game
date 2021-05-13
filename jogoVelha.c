//jogo da velha modo easy
#include <stdio.h>
#include <stdlib.h>

void movimento_jogador(char **Board)
{
  int x, y;

  printf("Digite X E Y, as coordenadas da sua jogada como X: ");
  scanf("%d%*c%d", &x, &y);
  printf("\n");

  printf("%d, %d\n", x, y);
  printf("\n");

  x--;
  y--;

  if (Board[x][y] != ' ')
  {
    printf("Jogada inválida, tente denovo\n");
    movimento_jogador(Board);
  }
  else
    Board[x][y] = 'X';
}

//computador joga, facil
void computer_move_easy(char **Board)
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
      if (Board[i][j] == ' ')
        break;
    if (Board[i][j] == ' ')
      break;
  }

  if (i * j == 9)
  {
    printf("empate\n");
    exit(0);
  }
  else
    Board[i][j] = 'O';
}

//tabuleiro
char **createboard()
{
  char **BOARD = calloc(3, sizeof(char *));
  for (int i = 0; i < 3; ++i)
  {
    BOARD[i] = calloc(3, sizeof(char));
  }

  for (int j = 0; j < 3; ++j)
  {
    for (int k = 0; k < 3; ++k)
    {
      BOARD[j][k] = ' ';
    }
  }

  return BOARD;
}

void print_board(char **Board)
{
  int i;

  for (i = 0; i < 3; i++)
  {
    printf(" %c | %c | %c ", Board[i][0],
           Board[i][1], Board[i][2]);
    if (i != 2)
      printf("\n---|---|---\n");
  }
  printf("\n");
}

char percorrer_board(char **Board)
{
  int i;

  for (i = 0; i < 3; i++) /* percorre linhas */
    if (Board[i][0] == Board[i][1] &&
        Board[i][0] == Board[i][2])
      return Board[i][0];

  for (i = 0; i < 3; i++) /* percorre colunas */
    if (Board[0][i] == Board[1][i] &&
        Board[0][i] == Board[2][i])
      return Board[0][i];

  /* percorre diagonais */
  if (Board[0][0] == Board[1][1] &&
      Board[1][1] == Board[2][2])
    return Board[0][0];

  if (Board[0][2] == Board[1][1] &&
      Board[1][1] == Board[2][0])
    return Board[0][2];

  return ' ';
}
int main()
{
  char done;

  char **Board = createboard();
  printf("JOGO DA VELHA, MODO FÁCIL MUITO FÁCIL....\n");

  done = ' ';

  printf("-------------------\n");
  do
  {
    print_board(Board);
    movimento_jogador(Board);
    done = percorrer_board(Board);
    if (done != ' ')
      break; //vitoria
    computer_move_easy(Board);
    done = percorrer_board(Board); //checa se há vitoria
  } while (done == ' ');

  if (done == 'X')

    printf("voce ganhou!\n");

  else
    printf("perdeu\n");
  print_board(Board); //mostra posiçoes finais do jogo
  return 0;
}