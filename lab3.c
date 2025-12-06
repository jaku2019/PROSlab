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
    
    const int ROWS = 5, COLS = 5;
    cell **board;

    int inputRow;
    int inputCol;
    int movesCount = 0;

    FILE *logFile;
    startLogFile(&logFile);
    
    createBoard(&board, ROWS, COLS);
    
    do{
        drawBoard(board, ROWS, COLS, logFile, symbolX, symbolO);    
        // wybor wiersza i kolumny ze sprawdzeniem poprawnosci
        if (!checkInput(&movesCount, &inputRow, &inputCol, logFile, board, ROWS, COLS)) continue;          // zły zakres - pomiń ruch
        // zmiana wybranego znaku i jego sasiadow na przeciwne
        toggleCellAndNeighbors(board, ROWS, COLS, inputRow - 1, inputCol - 1);
        movesCount++;
        checkWin(board, ROWS, COLS, &movesCount);
    }
    while(movesCount >= 0);
    if (movesCount == -1){
        drawBoard(board, ROWS, COLS, logFile, symbolX, symbolO);
        winnerMessage(&movesCount, logFile);
        freeBoard(board, ROWS);
        return 0;
    }
    else if (movesCount == -2){
        gameOver(logFile);
        freeBoard(board, ROWS);
        return 0;
    }
    else if (movesCount == -3){
        gameOverCell(logFile);
        freeBoard(board, ROWS);
        return 0;
    }    
};