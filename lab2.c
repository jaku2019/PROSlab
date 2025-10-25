//TODO zapetlenie rysowania tablicy, licznik ruchow, WYKRYWANIE zapelnienia tablicy x-ami
#include <stdio.h>
//#include "/home/mion/s/65/jtatarsk/Documents/PROS/lib/polibudex.h"
char macierzLiczb[9][9]={
    { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' },
    { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' },
    { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' },
    { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' },
    { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' },
    { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' },
    { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' },
    { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' },
    { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' },
    };
int wierszWej;
int kolumnaWej;
void rysujPlansze();
int sprawdzWejscie();
char zmienZnakMac();
void znakISasiedzi();
int main(void){
    rysujPlansze();    
    // wybor wiersza i kolumny ze sprawdzeniem poprawnosci
    sprawdzWejscie();
    // zmiana wybranego znaku i jego sasiadow na przeciwne
    znakISasiedzi(wierszWej - 1, kolumnaWej - 1);
    rysujPlansze();
    return 0;
};
void rysujPlansze(){
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
            printf("%c.", macierzLiczb[m][n]);
        };
    printf("\n....................\n");
    }
};
//pryjęcie nr. wiersza i kolumny, przerwanie gdy spoza zakresu
int sprawdzWejscie(){
    printf("Liczba ruchow: \n");
    printf("Podaj nr wiersza (1-9): ");
    scanf("%d", &wierszWej);
    if(wierszWej < 1 || wierszWej > 9){
        printf("Podano bledny nr wiersza! Sprobuj od nowa.\n");
    }
    else {
    printf("Podaj nr kolumny (1-9): ");
    scanf("%d", &kolumnaWej);
        if(wierszWej < 1 || wierszWej > 9){
            printf("Podano bledny nr wiersza! Sprobuj od nowa.\n");
        }
        else {
            printf("\nWybrano wiersz %d i kolumne %d\n\n", wierszWej, kolumnaWej);
        };
    };
    return wierszWej, kolumnaWej;  
};
//zamiana znaku w macierzLiczb na przeciwny
char zmienZnakMac(int wierszMac, int kolumnaMac){
    if (macierzLiczb[wierszMac][kolumnaMac] == 'o'){
        macierzLiczb[wierszMac][kolumnaMac] = 'X';
    }
    else{
        macierzLiczb[wierszMac][kolumnaMac] = 'o';
    }
};
// zamiana znaku i jego sasiadów w macierzLiczb
void znakISasiedzi(int w, int k){
    zmienZnakMac(w, k);
    if(w > 1){
        zmienZnakMac(w + 1, k);
    };
    if(w < 9){
        zmienZnakMac(w - 1, k);
    };
    if(k > 1){
        zmienZnakMac(w, k + 1);
    };
    if(k < 9){
        zmienZnakMac(w, k - 1);
    };
}