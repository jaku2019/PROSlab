#include <stdio.h>
//#include "/home/mion/s/65/jtatarsk/Documents/PROS/lib/polibudex.h"
int macierzLiczb[9][9]={
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    };
int wierszWej;
int kolumnaWej;
int licznik = 0;
void rysujPlansze();
int sprawdzWejscie();
int zmienZnakMac();
void znakISasiedzi();
int licz();
int main(void){
    do{
        rysujPlansze();    
        // wybor wiersza i kolumny ze sprawdzeniem poprawnosci
        sprawdzWejscie();
        // zmiana wybranego znaku i jego sasiadow na przeciwne
        znakISasiedzi(wierszWej - 1, kolumnaWej - 1);
        licznik++;
        licz;
    }
    while(licznik >= 0);
    rysujPlansze();
    printf("Liczba ruchow: %d\n", licznik);
    printf("GRATULACJE - WYGRANA!!!\n");
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
            if(macierzLiczb[m][n] == 0){
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
int sprawdzWejscie(){
    printf("Liczba ruchow: %d\n", licznik);
    printf("Podaj nr wiersza (1-9): ");
    scanf("%d", &wierszWej);
    if(wierszWej < 1 && wierszWej > 9){
        printf("Podano bledny nr wiersza! Sprobuj od nowa.\n");
        licznik = -1;
    }
    else {
    printf("Podaj nr kolumny (1-9): ");
    scanf("%d", &kolumnaWej);
        if(wierszWej < 1 && wierszWej > 9){
            printf("Podano bledny nr wiersza! Sprobuj od nowa.\n");
            licznik = -1;
        }
        else {
            printf("\nWybrano wiersz %d i kolumne %d\n\n", wierszWej, kolumnaWej);
        };
    };
    return wierszWej, kolumnaWej;  
};
//zamiana znaku w macierzLiczb na przeciwny
int zmienZnakMac(int wierszMac, int kolumnaMac){
    if (macierzLiczb[wierszMac][kolumnaMac] == 0){
        macierzLiczb[wierszMac][kolumnaMac] = 1;
    }
    else{
        macierzLiczb[wierszMac][kolumnaMac] = 0;
    }
};
// zamiana znaku i jego sasiadów w macierzLiczb
void znakISasiedzi(int w, int k){
    zmienZnakMac(w, k);
    if(w >= 0 && w < 8){
        zmienZnakMac(w + 1, k);
    };
    if(w <= 8 && w > 0){
        zmienZnakMac(w - 1, k);
    };
    if(k >= 0 && k < 8){
        zmienZnakMac(w, k + 1);
    };
    if(k <= 8 && k > 0){
        zmienZnakMac(w, k - 1);
    };
};
// liczy sume elementow macierzLiczb, gdy same x-y ustawia licznik na -1
int licz(){
    int suma = 0;
    for(int m=0; m<9; m++){
        for(int n=0; n<9; n++){
            suma += macierzLiczb[m][n];
        };
    };
    if(suma == 81){
        licznik = -1;
    };
}