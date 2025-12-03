#include <stdio.h>
//#include "/home/mion/s/65/jtatarsk/Documents/PROS/lib/polibudex.h"
#include "polibudex.h"

int main(int argc, char *argv[]){
    
    char symbolX = 'X';
    char symbolO = 'o';
    //nie przyjmuj więcej niż 2 argumenty
    checkArguments(argc, argv);
    // nadpisanie domyślnych znaków jeśli podano argumenty
    useArguments(argc, argv, &symbolX, &symbolO);

    cell board[9][9]={0};
    int inputRow;
    int inputCol;
    int movesCount = 0;

    FILE *logFile;
    startLogFile(&logFile);

    do{
        drawBoard(board, logFile, symbolX, symbolO);    
        // wybor wiersza i kolumny ze sprawdzeniem poprawnosci
        if (!checkInput(&movesCount, &inputRow, &inputCol, logFile, board)) continue;          // zły zakres - pomiń ruch
        // zmiana wybranego znaku i jego sasiadow na przeciwne
        toggleCellAndNeighbors(board, inputRow - 1, inputCol - 1);
        movesCount++;
        checkWin(board, &movesCount);
    }
    while(movesCount >= 0);
    if (movesCount == -1){
        drawBoard(board, logFile, symbolX, symbolO);
        winnerMessage(&movesCount, logFile);
        return 0;
    }
    else if (movesCount == -2){
        gameOver(logFile);
        return 0;
    }
    else if (movesCount == -3){
        gameOverCell(logFile);
        return 0;
    }    
};