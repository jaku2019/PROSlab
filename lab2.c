#include <stdio.h>
//#include "/home/mion/s/65/jtatarsk/Documents/PROS/lib/polibudex.h"
#include "polibudex.h"

int main(void){
    int board[9][9]={0};
    int inputRow;
    int inputCol;
    int movesCount = 0;
    do{
    drawBoard(board);    
        // wybor wiersza i kolumny ze sprawdzeniem poprawnosci
    if (!checkInput(&movesCount, &inputRow, &inputCol)) continue;          // zły zakres pomiń ruch
        // zmiana wybranego znaku i jego sasiadow na przeciwne
    toggleCellAndNeighbors(board, inputRow - 1, inputCol - 1);
        movesCount++;
    checkWin(board, &movesCount);
    }
    while(movesCount >= 0);
    drawBoard(board);
    printf("Liczba ruchow: %d\n", movesCount);
    printf("GRATULACJE - WYGRANA!!!\n");
    return 0;
};