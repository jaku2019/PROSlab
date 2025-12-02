# Jakub Tatarski nr 337166 4.11.2025
Program uruchamia w pętli main kolejne funkcje. Poniżej przedstawiono występujące w programie zmienne i funkcje.

## Zmienne globalne

### `int board[9][9]`

Plansza gry 9×9, domyślnie wypełniona wartościami `0`.\
Funkcja `drawBoard` interpretuje wartości: - `0` - drukuje `o.` - `1`
- drukuje `X.`

### `int inputRow`

Numer wiersza wybrany przez użytkownika (zakres `1–9`).

### `int inputCol`

Numer kolumny wybrany przez użytkownika (zakres `1–9`).

### `int movesCount = 0`

Licznik wykonanych ruchów.\
Ustawienie `movesCount = -1` kończy pętlę gry.

## Funkcje

### `void drawBoard(void)`

Rysuje aktualny stan planszy: - wypisuje nagłówki kolumn `1–9`, - rysuje
linię ramki, - dla każdego wiersza wypisuje numer, zawartość pól i linię
oddzielającą.

**Parametry:** brak
**Zwraca:** nic

### `int checkInput(void)`

Pobiera i weryfikuje dane podane przez użytkownika: - odczytuje
`tmpInputRow` i `tmpInputCol`, - sprawdza zakres `1–9`, - jeśli wartości
poprawne, przepisuje je do `inputRow` i `inputCol`, wypisuje
potwierdzenie i zwraca `1`, - jeśli błędne, wypisuje komunikat i zwraca
`0`.

**Parametry:** brak
**Zwraca:**
- `1` - poprawne dane
- `0` - błąd

### `void toggleCell(int row, int col)`

Odwraca stan pola: - `0` - zamienia na `1` - `1` - zamienia na `0`

**Parametry:** `row` i `col` w zakresie `0–8`
**Zwraca:** nic

### `void toggleCellAndNeighbors(int w, int k)`

Zmienia stan wybranego pola i jego sąsiadów.
Modyfikuje tylko pola mieszczące się w granicach planszy.

**Parametry:** `w` i `k` w zakresie `0–8`
**Zwraca:** nic

### `void checkWin(void)`

Sprawdza, czy wszystkie pola są równe `1`: - sumuje wszystkie elementy
tablicy `board`, - jeśli suma wynosi `81`, ustawia `movesCount = -1`, co
oznacza wygraną.

**Parametry:** brak
**Zwraca:** nic

## pętla main()
Pętla `main` uruchamia pętlę `do…while`, w której najpierw rysuje planszę, a potem pobiera ruch; jeśli `checkInput()` zwróci błąd, pomija ruch i iterację. Przy poprawnym wejściu odwraca wskazane pole i jego sąsiadów (`toggleCellAndNeighbors`), zwiększa `movesCount` i sprawdza zwycięstwo funkcją `checkWin()`. Pętla trwa, dopóki `movesCount` nie zostanie ustawiony na -1 (wygrana). Po wyjściu program rysuje planszę końcową, wypisuje liczbę ruchów i komunikat o wygranej.
