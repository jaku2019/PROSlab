# Jakub Tatarski nr 337166 5.12.2025
Program uruchamia w pętli main kolejne funkcje. Poniżej przedstawiono występujące w programie zmienne i funkcje.


## createBoard

Tworzy dynamicznie zaalokowaną tablicę dwuwymiarową (tablicę struktur `cell`). Funkcja rezerwuje pamięć najpierw na tablicę wskaźników (wiersze), a następnie na każdy wiersz osobno. Alokuje tablicę wskaźników o długości `rows`, następnie dla każdego wiersza rezerwuje `cols` i zapisuje wynik przez przekazany wskaźnik.

**Parametry:**
- `board` – potrójny wskaźnik, do którego zostanie zapisany adres utworzonej tablicy  
- `rows` – liczba wierszy  
- `cols` – liczba kolumn  

**Zwraca:** nic

## freeBoard

Zwalnia pamięć zajmowaną przez dynamicznie utworzoną tablicę dwuwymiarową. Dla każdego wiersza wywołuje `free` na zaalokowanej tablicy, a po zwolnieniu wszystkich wierszy wywołuje `free` na tablicy wskaźników.

**Parametry:**
- `board` – wskaźnik na tablicę dwuwymiarową typu `cell`  
- `rows` – liczba wierszy  

**Zwraca:** nic

## drawBoard

Rysuje planszę 9×9 oraz zapisuje jej stan do pliku logu.

-   wypisuje nagłówki kolumn 1--9
-   rysuje ramkę
-   dla każdego pola drukuje symbol zgodny z `argumentX` lub
    `argumentO`
-   po każdym wierszu drukuje linię kropkowaną

**Parametry:**
- `board` - tablica 9×9
- `logFile` - uchwyt do pliku logu
- `argumentX` - znak odpowiadający wartości 1
- `argumentO` - znak odpowiadający wartości 0

**Zwraca:** nic

## checkInput

Pobiera współrzędne ruchu od użytkownika, kontroluje liczbę pozostałych
ruchów oraz zakres wejścia.

-   zmniejsza licznik dostępnych ruchów
-   przy braku ruchów ustawia `movesCount` na -2
-   sprawdza zakres 1--9
-   zwraca 1 przy poprawnym wejściu lub 0 przy błędzie

**Parametry:**
- `movesCount` - licznik ruchów
- `inputRow` - wskaźnik na wybrany wiersz
- `inputCol` - wskaźnik na wybraną kolumnę
- `logFile` - uchwyt do pliku logu

**Zwraca:** 1 lub 0

## toggleCell

Odwraca stan wybranego pola planszy.

-   0 zamienia na 1
-   1 zamienia na 0

**Parametry:**
- `board`
- `row`
- `col`

**Zwraca:** nic

## toggleCellAndNeighbors

Odwraca stan wybranego pola oraz jego sąsiadów w górę, dół, lewo i prawo
(jeśli mieszczą się w planszy).

**Parametry:**
- `board`
- `w`
- `k`

**Zwraca:** nic

## checkWin

Sprawdza, czy wszystkie pola planszy mają wartość 1.

-   jeśli suma pól wynosi 81, ustawia `movesCount` na -1

**Parametry:**
- `board`
- `movesCount`

**Zwraca:** nic

## gameOver

Wypisuje komunikat o przegranej i zamyka plik logu.

**Parametry:**
- `logFile`

**Zwraca:** nic

## winnerMessage

Wypisuje liczbę ruchów, komunikat o zwycięstwie i zamyka plik logu.

**Parametry:**
- `movesCount`
- `logFile`

**Zwraca:** nic

## startLogFile

Otwiera plik `polibudex_log.txt` w trybie zapisu.

**Parametry:**
- `logFile`

**Zwraca:** nic

## checkArguments

Sprawdza liczbę argumentów i ostrzega przy podaniu więcej niż dwóch
symboli.

**Parametry:**
- `argc`
- `argv`

**Zwraca:** nic

## useArguments

Nadpisuje domyślne symbole X i O, jeśli zostały przekazane w
argumentach.

**Parametry:**
- `argc`
- `argv`
- `symbolX`
- `symbolO`

**Zwraca:** nic

## countChanges

Sprawdza która komórka tablicy była zmieniana najwięcej razy 
(pole struktury `changes`). Printfuje wynik operacji.

**Parametry:**
- `board`
- `rows` - wskaźnik na wybrany wiersz
- `cols` - wskaźnik na wybraną kolumnę
- `logFile`

**Zwraca:** nic

## z lotu ptaka
Pętla `main` uruchamia funkcje `checkArguments`, `useArguments` i `startLogFile`. Dwa pierwsze są odpowiedzialne za obsługę parametrów przekazywanych przez main, ten ostatni uruchamia zapis historii do pliku "polibudex_log.txt". Dalej uruchamiana jest pętla `do…while`, w której najpierw rysowana jest plansza, a potem pobierany jest ruch; jeśli `checkInput()` zwróci błąd, pomijamy ruch i iterację. Przy poprawnym wejściu funkcja odwraca wskazane pole i jego sąsiadów (`toggleCellAndNeighbors`), zwiększa `movesCount` i sprawdza zwycięstwo funkcją `checkWin()`. Pętla trwa, dopóki `movesCount` nie zostanie ustawiony na -1 (wygrana) lub  -2 (przegrana). Po wyjściu program rysuje planszę końcową, wypisuje liczbę ruchów i komunikat o wygranej lub komunikat o przegranej (wykorzystaniu wszystkich ruchów). W obydwu wariantach zostaje również zamknięty plik z historią gry.
