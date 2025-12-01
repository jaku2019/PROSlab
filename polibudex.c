#include <stdio.h>
#include "polibudex.h"
#define MAX_MOVES 5

void drawBoard(int board[9][9]){
    // lp. kolumn i ramka
    printf("  ");
    for(int n=0; n<9; n++){
        printf("%d ", n+1);
    };
    printf("\n....................\n");

    // wypisanie zawartosci macierzy i lp. wierszy
    for(int m=0; m<9; m++){
        printf("%d.", m + 1);
        for(int n=0; n<9; n++){
            if(board[m][n] == 0){
            printf("o.");
            }
            else{
            printf("X.");
            }
        };
    printf("\n....................\n");
    }
};
//pryjęcie nr. wiersza i kolumny, przerwanie gdy spoza zakresu
int checkInput(int *movesCount, int *inputRow, int *inputCol){
    int tmpInputRow, tmpInputCol;

    // max liczba ruchów, przekroczenie kończy grę
    static int remainingMoves = MAX_MOVES;
    if (remainingMoves <= 0){
        *movesCount = -2;
        return 0;
    }
    printf("Pozostalo ruchow: %d\n", remainingMoves--);
    printf("Liczba ruchow: %d\n", *movesCount);

    printf("Podaj nr wiersza (1-9): ");
    scanf("%d", &tmpInputRow);
    if (tmpInputRow < 1 || tmpInputRow > 9) {
        printf("Podano bledny nr wiersza! Sprobuj ponownie.\n");
        return 0;
    }

    printf("Podaj nr kolumny (1-9): ");
    scanf("%d", &tmpInputCol);
    if (tmpInputCol < 1 || tmpInputCol > 9) {
        printf("Podano bledny nr kolumny! Sprobuj ponownie.\n");
        return 0;
    }

    *inputRow  = tmpInputRow;
    *inputCol = tmpInputCol;

    printf("\nWybrano wiersz %d i kolumne %d\n\n", tmpInputRow, tmpInputCol);
    return 1;
};
//zamiana znaku w macierzLiczb na przeciwny
void toggleCell(int board[9][9], int row, int col){
    if (board[row][col] == 0){
        board[row][col] = 1;
    }
    else{
        board[row][col] = 0;
    }
};
// zamiana znaku i jego sasiadów w macierzLiczb
void toggleCellAndNeighbors(int board[9][9], int w, int k){
    toggleCell(board, w, k);
    if(w >= 0 && w < 8){
        toggleCell(board, w + 1, k);
    };
    if(w <= 8 && w > 0){
        toggleCell(board, w - 1, k);
    };
    if(k >= 0 && k < 8){
        toggleCell(board, w, k + 1);
    };
    if(k <= 8 && k > 0){
        toggleCell(board, w, k - 1);
    };
};
// liczy sume elementow macierzLiczb, gdy same x-y ustawia licznik na -1
void checkWin(int board[9][9], int *movesCount){
    int suma = 0;
    for(int m=0; m<9; m++){
        for(int n=0; n<9; n++){
            suma += board[m][n];
        };
    };
    if(suma == 81){
        *movesCount = -1;
    };
}