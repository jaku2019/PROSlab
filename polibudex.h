#ifndef _POLIBUDEX_H_
#define _POLIBUDEX_H_

typedef struct {
    int state; // 0 to domyslnie o, 1 to X
    int changes; // liczba zmian stanu
} cell;

void drawBoard(cell board[9][9], FILE *logFile, char argumentX, char argumentO);
int checkInput(int *movesCount, int *inputRow, int *inputCol, FILE *logFile, cell board[9][9]);
void toggleCell(cell board[9][9], int row, int col);
void toggleCellAndNeighbors(cell board[9][9], int w, int k);
void checkWin(cell board[9][9], int *movesCount);
void gameOver(FILE *logFile);
void gameOverCell(FILE *logFile);
void winnerMessage(int *movesCount, FILE *logFile);
void startLogFile(FILE **logFile);
void checkArguments(int argc, char *argv[]);
void useArguments(int argc, char *argv[], char *symbolX, char *symbolO);
void countChanges(cell board[9][9], FILE *logFile);

#endif
