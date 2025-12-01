#ifndef _POLIBUDEX_H_
#define _POLIBUDEX_H_

void drawBoard(int (*board)[9], FILE *logFile);
int checkInput(int *movesCount, int *inputRow, int *inputCol, FILE *logFile);
void toggleCell(int (*board)[9], int row, int col);
void toggleCellAndNeighbors(int (*board)[9], int w, int k);
void checkWin(int (*board)[9], int *movesCount);

extern int board[9][9];
extern int inputRow;
extern int inputCol;
extern int movesCount;

#endif