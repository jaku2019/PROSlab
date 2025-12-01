#include <stdio.h>
//#include "/home/mion/s/65/jtatarsk/Documents/PROS/lib/polibudex.h"
#include "polibudex.h"

int main(int argc, char *argv[]){
    
    //nie przyjmuj więcej niż 2 argumenty
    if (argc > 3) {
        printf("Za duzo argumentow! Podaj dokladnie 2 znaki jako argumenty.\n");
        return 1;
    }

    char symbolX = 'X';
    char symbolO = 'O';

    // nadpisanie domyślnych znaków jeśli podano argumenty
    if (argc > 1) {
        symbolX = argv[1][0];
    }
    if (argc > 2) {
        symbolO = argv[2][0];
    }

    int board[9][9]={0};
    int inputRow;
    int inputCol;
    int movesCount = 0;
    FILE *logFile;
    logFile = fopen("polibudex_log.txt", "w");
    do{
    drawBoard(board, logFile, symbolX, symbolO);    
        // wybor wiersza i kolumny ze sprawdzeniem poprawnosci
    if (!checkInput(&movesCount, &inputRow, &inputCol, logFile)) continue;          // zły zakres pomiń ruch
        // zmiana wybranego znaku i jego sasiadow na przeciwne
    toggleCellAndNeighbors(board, inputRow - 1, inputCol - 1);
        movesCount++;
    checkWin(board, &movesCount);
    }
    while(movesCount >= 0);
    if (movesCount == -1) {
        drawBoard(board, logFile, symbolX, symbolO);
        printf("Liczba ruchow: %d\n", movesCount);
        fprintf(logFile, "Liczba ruchow: %d\n", movesCount);
        printf("GRATULACJE - WYGRANA!!!\n");
        fprintf(logFile, "GRATULACJE - WYGRANA!!!\n");
        fclose(logFile);
        return 0;
    }
    else if (movesCount == -2)
    {
        printf("Przekroczono maks. liczbe ruchow. KONIEC GRY!\n");
        fprintf(logFile, "Przekroczono maks. liczbe ruchow. KONIEC GRY!\n");
        fclose(logFile);
        return 0;
    }
    
};