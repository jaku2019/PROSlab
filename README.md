# Jakub Tatarski nr 337166 4.11.2025
Program uruchamia w pętli main kolejne funkcje. Poniżej przedstawiono występujące w programie zmienne i funkcje.

## Zmienne globalne
- `int macierzLiczb[9][9]` – plansza gry (`0` → drukuje „o.”, `1` → „X.”).
- `int wierszWej` – wybrany przez użytkownika numer wiersza (`1–9`).
- `int kolumnaWej` – wybrany przez użytkownika numer kolumny (`1–9`).
- `int licznik = 0` – liczba wykonanych ruchów; ustawienie `-1` kończy pętlę gry.

## Funkcje

### `void rysujPlansze(void)`
Rysuje planszę:
- nagłówki kolumn `1–9` oraz linię ramki,
- dla każdego wiersza: numer wiersza i zawartość pól (`o.` dla `0`, `X.` dla `1`), po każdym wierszu ramka.  
**Parametry / zwrot:** brak.

### `int sprawdzWejscie(void)`
Pobiera ruch użytkownika **z weryfikacją zakresu**:
- czyta do zmiennych tymczasowych `tmpWierszWej`, `tmpKolumnaWej`,
- jeśli wartości są w `1–9` → przepisuje do globalnych `wierszWej`, `kolumnaWej`, wypisuje potwierdzenie i zwraca `1`,
- jeśli poza zakresem → wypisuje komunikat i zwraca `0` (globalne nie są zmieniane).  
**Parametry:** brak. **Zwraca:** `1` (OK) / `0` (błąd).

### `void zmienZnakMac(int wierszMac, int kolumnaMac)`
Odwraca stan pojedynczego pola tablicy: `0 → 1`, `1 → 0`.  
**Parametry:** indeksy `0–8`. **Zwraca:** brak.

### `void znakISasiedzi(int w, int k)`
Odwraca wybrane pole `(w, k)` oraz sąsiadów ortogonalnych, **tylko jeśli mieszczą się w planszy** (sprawdzenia brzegowe w funkcji).  
**Parametry:** indeksy `0–8`. **Zwraca:** brak.

### `void licz(void)`
Sumuje wszystkie elementy `macierzLiczb`. Jeśli suma = `81` (same jedynki), ustawia `licznik = -1` → zakończenie gry (wygrana).  
**Parametry / zwrot:** brak.
