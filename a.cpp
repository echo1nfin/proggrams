#include <windows.h>
#include <iostream>
using namespace std;

int board[4][4];

// Функция для установки цвета текста в консоли
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
// Функция для инициализации доски
void initializeBoard()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
}
// Функция для отображения доски с измененными символами
void displayBoard()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == -1) {
                cout << "Q ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}
int k = 1; // Переменная для счета шагов рекурсии
// Функция для визуализации шагов рекурсии в консоли
void recursionSteps(int i, int j)
{
    setColor(14);
    cout << "Шаг " << k << ": i = " << i << " j = " << j << endl;
    setColor(8);
    cout << "Доска с шагами: " << endl;
    setColor(7);
    for (int y = 0; y < 4; y++)
    {
        for (int z = 0; z < 4; z++)
        {
            cout << board[y][z] << " ";
        }
        cout << endl;
    }
    k++;
}
// Функция для установки ферзя
void placeQueen(int i, int j)
{
    for (int x = 0; x < 4; ++x) {
        board[x][j] += 1;
        board[i][x] += 1;

        int d;
        d = j - i + x;
        if (d >= 0 && d < 4) {
            board[x][d] += 1;
        }

        d = j + i - x;
        if (d >= 0 && d < 4) {
            board[x][d] += 1;
        }
    }
    board[i][j] = -1;
    recursionSteps(i, j);
    setColor(8);
    cout << "Доска с ферзями: " << endl;
    setColor(7);
    displayBoard();
}
// Функция для удаления ферзя
void removeQueen(int i, int j)
{
    for (int x = 0; x < 4; ++x) {
        board[x][j] -= 1;
        board[i][x] -= 1;

        int d;
        d = j - i + x;
        if (d >= 0 && d < 4) {
            board[x][d] -= 1;
        }

        d = j + i - x;
        if (d >= 0 && d < 4) {
            board[x][d] -= 1;
        }
    }
    board[i][j] = 0;
}
// Функция для проверки расстановки ферзей
bool checkQueen(int i)
{
    bool result = false;

    for (int j = 0; j < 4; ++j) { // Итерация по столбцам
        if (board[i][j] == 0) { // Если клетка свободна от ферзя
            placeQueen(i, j); // Размещаем ферзя и отмечаем атакованные клетки

            if (i == 3) { // Если последняя строка, все ферзи расставлены
                result = true;
            }
            else if (!(result = checkQueen(i + 1))) { // Если неудачно, удалить ферзя и продолжить проверку
                removeQueen(i, j);
            }
        }
        if (result) break;
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    initializeBoard();
    checkQueen(0);
    setColor(14);
    cout << "Результат: " << endl;
    setColor(7);
    displayBoard();
    return 0;
}
