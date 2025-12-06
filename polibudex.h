#ifndef _POLIBUDEX_H_
#define _POLIBUDEX_H_

typedef struct {
    int state; // 0 to domyslnie o, 1 to X
    int changes; // liczba zmian stanu
} cell;

void createBoard(cell ***board, int rows, int cols);
void freeBoard(cell ***board, int rows);
void drawBoard(cell ***board, FILE *logFile, char argumentX, char argumentO, int rows, int cols);
int checkInput(int *movesCount, int *inputRow, int *inputCol, FILE *logFile, cell ***board, int rows, int cols);
void toggleCell(cell ***board, int row, int col);
void toggleCellAndNeighbors(cell ***board, int w, int k, int rows, int cols);
void checkWin(cell ***board, int *movesCount, int rows, int cols);
void gameOver(FILE *logFile);
void gameOverCell(FILE *logFile);
void winnerMessage(int *movesCount, FILE *logFile);
void startLogFile(FILE **logFile);
void checkArguments(int argc, char *argv[]);
void useArguments(int argc, char *argv[], char *symbolX, char *symbolO);
void countChanges(cell ***board, FILE *logFile, int rows, int cols);

#endif
