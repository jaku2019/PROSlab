#ifndef _POLIBUDEX_H_
#define _POLIBUDEX_H_

void drawBoard();
int checkInput();
void toggleCell(int row, int col);
void toggleCellAndNeighbors(int w, int k);
void checkWin();

extern int board[9][9];
extern int inputRow;
extern int inputCol;
extern int movesCount;

#endif