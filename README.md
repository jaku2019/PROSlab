# Jakub Tatarski nr 337166 4.11.2025
Program uruchamia w pętli main kolejne funkcje. Poniżej przedstawiono występujące w programie zmienne i funkcje.

## Zmienne globalne
- `int macierzLiczb[9][9]` – plansza gry ( rysujPlansze `0` → drukuje „o.”, `1` → „X.”).
- `int wierszWej` – wybrany przez użytkownika numer wiersza (`1–9`).
- `int kolumnaWej` – wybrany przez użytkownika numer kolumny (`1–9`).
- `int licznik = 0` – liczba wykonanych ruchów; ustawienie `-1` kończy pętlę gry.

## Funkcje

### `void rysujPlansze(void)`
Rysuje planszę:
- nagłówki kolumn `1–9` oraz linię ramki,
- dla każdego wiersza: numer wiersza i zawartość pól (`o.` dla `0`, `X.` dla `1`), po każdym wierszu kropkowana "ramka".  
**Parametry / zwraca:** brak.

### `int sprawdzWejscie(void)`
Pobiera ruch użytkownika **z weryfikacją zakresu**:
- czyta do zmiennych "chwilowych" `tmpWierszWej`, `tmpKolumnaWej`,
- jeśli wartości są w `1–9` → przepisuje do zmiennych globalnych `wierszWej`, `kolumnaWej`, wypisuje potwierdzenie i zwraca `1` - OK,
- jeśli poza zakresem → wypisuje komunikat i zwraca `0` - błąd.  
**Parametry:** brak. **Zwraca:** `1` (OK) / `0` (błąd).

### `void zmienZnakMac(int wierszMac, int kolumnaMac)`
Odwraca stan pojedynczego pola tablicy: `0 → 1`, `1 → 0`.   
**Parametry:** indeksy `0–8`. **Zwraca:** brak.

### `void znakISasiedzi(int w, int k)`
Odwraca wybrane pole `(w, k)` oraz sąsiadów, **tylko jeśli mieszczą się w planszy** (unika odwrócenia pól poza planszą).  
**Parametry:** indeksy `0–8`. **Zwraca:** brak.

### `void licz(void)`
Sumuje wszystkie elementy `macierzLiczb`. Jeśli suma = `81` (same jedynki), ustawia `licznik = -1` → zakończenie gry (wygrana).  
**Parametry / zwraca:** brak.

# pętla main()
Pętla `main` uruchamia pętlę `do…while`, w której najpierw rysuje planszę, a potem pobiera ruch; jeśli `sprawdzWejscie()` zwróci błąd, pomija ruch i iterację. Przy poprawnym wejściu odwraca wskazane pole i jego sąsiadów (`znakISasiedzi`), zwiększa licznik ruchów i sprawdza zwycięstwo funkcją `licz()`. Pętla trwa, dopóki licznik nie zostanie ustawiony na -1 (wygrana). Po wyjściu program rysuje planszę końcową, wypisuje liczbę ruchów i komunikat o wygranej.
