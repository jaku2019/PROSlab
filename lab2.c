#include <stdio.h>
//#include "/home/mion/s/65/jtatarsk/Documents/PROS/lib/polibudex.h"
#include "polibudex.h"

int main(void){
    do{
    drawBoard();    
        // wybor wiersza i kolumny ze sprawdzeniem poprawnosci
    if (!checkInput()) continue;          // zły zakres pomiń ruch
        // zmiana wybranego znaku i jego sasiadow na przeciwne
    toggleCellAndNeighbors(inputRow - 1, inputCol - 1);
        movesCount++;
    checkWin();
    }
    while(movesCount >= 0);
    drawBoard();
    printf("Liczba ruchow: %d\n", movesCount);
    printf("GRATULACJE - WYGRANA!!!\n");
    return 0;
};