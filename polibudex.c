#include <stdio.h>
#include "polibudex.h"
#define MAX_MOVES 5
#define MAX_CELL_CHANGES 3


// tworzenie tablicy
void createBoard(cell ***board, int rows, int cols){
    *board = (cell**) calloc(rows, sizeof(cell*));
    for(int i=0; i<rows; i++){
        (*board)[i] = (cell*) calloc(cols, sizeof(cell));
    }
}

// czyszczenie pamięci tablicy
void freeBoard(cell **board, int rows){
    for(int i=0; i<rows; i++){
        free(board[i]);
    }
    free(board);
}

void drawBoard(cell **board, int rows, int cols, FILE *logFile, char argumentX, char argumentO){
    // lp. kolumn i ramka
    printf("  ");
    fprintf(logFile, "  ");
    for(int n=0; n<cols; n++){
        printf("%d ", n+1);
        fprintf(logFile, "%d ", n+1);
    };
    printf("\n....................\n");
    fprintf(logFile, "\n....................\n");

    // wypisanie zawartosci macierzy i lp. wierszy
    for(int m=0; m<rows; m++){
        printf("%d.", m + 1);
        fprintf(logFile, "%d.", m + 1);
        for(int n=0; n<cols; n++){
            if(board[m][n].state == 0){
            printf("%c.", argumentO);
            fprintf(logFile, "%c.", argumentO);
            }
            else{
            printf("%c.", argumentX);
            fprintf(logFile, "%c.", argumentX);
            }
        };
    printf("\n....................\n");
    fprintf(logFile, "\n....................\n");
    }
};
//pryjęcie nr. wiersza i kolumny, przerwanie gdy spoza zakresu
int checkInput(int *movesCount, int *inputRow, int *inputCol, FILE *logFile, cell **board, int rows, int cols){
    int tmpInputRow, tmpInputCol;

    // max liczba ruchów, przekroczenie kończy grę
    static int remainingMoves = MAX_MOVES;
    if (remainingMoves <= 0){
        *movesCount = -2;
        return 0;
    }

    countChanges(board, rows, cols, logFile);
    // sprawdzenie czy któraś komórka nie przekroczyła max liczby zmian
    for(int m=0; m<rows; m++){
        for(int n=0; n<cols; n++){
            if(board[m][n].changes > MAX_CELL_CHANGES){
                *movesCount = -3;
                return 0;
            }
        }
    };
    printf("Pozostalo ruchow: %d\n", remainingMoves);
    fprintf(logFile, "Pozostalo ruchow: %d\n", remainingMoves);
    remainingMoves--;
    printf("Liczba ruchow: %d\n", *movesCount);
    fprintf(logFile, "Liczba ruchow: %d\n", *movesCount);


    printf("Podaj nr wiersza (1-9): ");
    fprintf(logFile, "Podaj nr wiersza (1-9): ");
    scanf("%d", &tmpInputRow);
    fscanf(logFile, "%d", &tmpInputRow);
    if (tmpInputRow < 1 || tmpInputRow > rows) {
        printf("Podano bledny nr wiersza! Sprobuj ponownie.\n");
        fprintf(logFile, "Podano bledny nr wiersza! Sprobuj ponownie.\n");
        return 0;
    }

    printf("Podaj nr kolumny (1-9): ");
    fprintf(logFile, "Podaj nr kolumny (1-9): ");
    scanf("%d", &tmpInputCol);
    fscanf(logFile, "%d", &tmpInputCol);
    if (tmpInputCol < 1 || tmpInputCol > cols) {
        printf("Podano bledny nr kolumny! Sprobuj ponownie.\n");
        fprintf(logFile, "Podano bledny nr kolumny! Sprobuj ponownie.\n");
        return 0;
    }

    *inputRow  = tmpInputRow;
    *inputCol = tmpInputCol;

    printf("\nWybrano wiersz %d i kolumne %d\n\n", tmpInputRow, tmpInputCol);
    fprintf(logFile, "\nWybrano wiersz %d i kolumne %d\n\n", tmpInputRow, tmpInputCol);
    return 1;
};
//zamiana znaku w macierzLiczb na przeciwny
void toggleCell(cell **board, int rows, int cols, int row, int col){
    if (board[row][col].state == 0){
        board[row][col].state = 1;
    }
    else{
        board[row][col].state = 0;
    }
    board[row][col].changes++;
};
// zamiana znaku i jego sasiadów w macierzLiczb
void toggleCellAndNeighbors(cell **board, int rows, int cols, int w, int k){
    toggleCell(board, rows, cols, w, k);
    if(w >= 0 && w < rows-1){
        toggleCell(board, rows, cols, w + 1, k);
    };
    if(w <= rows-1 && w > 0){
        toggleCell(board, rows, cols, w - 1, k);
    };
    if(k >= 0 && k < cols-1){
        toggleCell(board, rows, cols, w, k + 1);
    };
    if(k <= cols-1 && k > 0){
        toggleCell(board, rows, cols, w, k - 1);
    };
};
// liczy sume elementow macierzLiczb, gdy same x-y ustawia licznik na -1
void checkWin(cell **board, int rows, int cols, int *movesCount){
    int suma = 0;
    for(int m=0; m<rows; m++){
        for(int n=0; n<cols; n++){
            suma += board[m][n].state;
        };
    };
    if(suma == rows*cols){
        *movesCount = -1;
    };
}

// wypisanie komunikatu o przegranej i zamknięcie pliku
void gameOver(FILE *logFile){
    printf("Przekroczono maks. liczbe ruchow. KONIEC GRY!\n");
    fprintf(logFile, "Przekroczono maks. liczbe ruchow. KONIEC GRY!\n");
    fclose(logFile);
}

// wypisanie komunikatu o przegranej i zamknięcie pliku
void gameOverCell(FILE *logFile){
    printf("Przekroczono maks. liczbe zmian komorki. KONIEC GRY!\n");
    fprintf(logFile, "Przekroczono maks. liczbe zmian komorki (%d). KONIEC GRY!\n");
    fclose(logFile);
}

// wypisanie komunikatu o wygranej i zamknięcie pliku
void winnerMessage(int *movesCount, FILE *logFile){
    printf("Liczba ruchow: %d\n", *movesCount);
    fprintf(logFile, "Liczba ruchow: %d\n", *movesCount);
    printf("GRATULACJE - WYGRANA!!!\n");
    fprintf(logFile, "GRATULACJE - WYGRANA!!!\n");
    fclose(logFile);
}

// otwarcie pliku logu
void startLogFile(FILE **logFile){
    *logFile = fopen("polibudex_log.txt", "w");
} 

// sprawdzenie liczby argumentów
void checkArguments(int argc, char *argv[]){
    if (argc > 3){
        printf("Za duzo argumentow! Podaj dokladnie 2 znaki jako argumenty.\n");
        return;
    }
}

//nadpisanie domyślnych znaków jeśli podano argumenty
void useArguments(int argc, char *argv[], char *symbolX, char *symbolO){
    //nadpisanie domyślnych znaków jeśli podano argumenty
    if (argc > 1){
        *symbolX = argv[1][0];
    }
    if (argc > 2){
        *symbolO = argv[2][0];
    }
}
// zliczenie i wypisanie komórki zmienianej najwięcej razy
void countChanges(cell  **board, int rows, int cols, FILE *logFile){
    int maxChanges = board[0][0].changes;
    int maxRow = 0;
    int maxCol = 0;
    for(int m=0; m<rows; m++){
        for(int n=0; n<cols; n++){
            if(board[m][n].changes > maxChanges){
                maxChanges = board[m][n].changes;
                maxRow = m;
                maxCol = n;
            }
        }
    };
    printf("Komorka (%d, %d) byla zmieniana najwiecej razy: %d\n", maxRow+1, maxCol+1, maxChanges);
    fprintf(logFile, "Komorka (%d, %d) byla zmieniana najwiecej razy: %d\n", maxRow+1, maxCol+1, maxChanges);
    
}