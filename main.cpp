#include <iostream>
#include <string>
using namespace std;

char findElement(string field, int x, int y)
{
    return field[3 * x + y];
}

int count(string field, char f)
{
    int count = 0;
    for (int i = 0; i < field.length(); i++)
        if (field[i] == f)
            count++;
    return count;
}

string findStrWinner(string field)
{
    for (int i = 0; i < 3; i++) {
        int countX = 0;
        int countO = 0;
        for (int j = 0; j < 3; j++) {
            if (findElement(field, i, j) == 'X')
                countX++;
            if (findElement(field, i, j) == 'O')
                countO++;
        }
        if (countX == 3)
            return "X";
        if (countO == 3)
            return "O";
    }
    return ".";
}

string findColumnWinner(string field)
{
    for (int i = 0; i < 3; i++) {
        int countX = 0;
        int countO = 0;
        for (int j = 0; j < 3; j++) {
            if (findElement(field, j, i) == 'X')
                countX++;
            if (findElement(field, j, i) == 'O')
                countO++;
        }
        if (countX == 3)
            return "X";
        if (countO == 3)
            return "O";
    }
    return ".";
}

string findDiagWinner(string field)
{
    int countX = 0, countO = 0,
    countX1 = 0, countO1 = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (findElement(field, i, j) == 'X')
                countX++;
            if (findElement(field, i, j) == 'O')
                countO++;
            if (i == 2 - j && findElement(field, i, j) == 'X')
                countX1++;
            if (i == 2 - j && findElement(field, i, j) == 'O')
                countO1++;
        }
    }
    if (countX == 3 || countX1 == 3)
        return "X";
    if (countO == 3 || countO1 == 3)
        return "O";
    return ".";
}

string winner(string field)
{
    if (findDiagWinner(field) == "O" || findStrWinner(field) == "O" || findColumnWinner(field) == "O")
        return "O";
    if (findDiagWinner(field) == "X" || findStrWinner(field) == "X" || findColumnWinner(field) == "X")
        return "X";
    return ".";
}

bool countWinners(string field)
{
    int countPetyaWin = 0,
    countVasyaWin = 0;
    if (findColumnWinner(field) == "X")
        countPetyaWin++;
    if (findColumnWinner(field) == "O")
        countVasyaWin++;
    if (findStrWinner(field) == "X")
        countPetyaWin++;
    if (findStrWinner(field) == "O")
        countVasyaWin++;
    if (findDiagWinner(field) == "X")
        countPetyaWin++;
    if (findDiagWinner(field) == "O")
        countVasyaWin++;
    if (countPetyaWin > 0 && countPetyaWin <= 2 && countVasyaWin == 0)
        return true;
    else if (countVasyaWin == 1 && countPetyaWin == 0)
        return true;
    else return false;
}

bool correctSymb(string field)
{
    string dictionary = "XO.";
    for (int i = 0; i < field.length(); i++) {
        bool flag = false;
        for (int j = 0; j < dictionary.length(); j++) {
            if (field[i] == dictionary[j]) {
                flag = true;
                break;
            }
        }
        if (!flag)
            return false;
    }
    return true;
}

bool countVal(string field)
{
    if (winner(field) == "X" && count(field, 'X') == count(field, 'O') + 1)
        return true;
    if (winner(field) == "O" && count(field, 'O') == count(field, 'X'))
        return true;
    if (winner(field) == ".")
        return true;
    return false;
}

int main() {
    string field;
    cout << "Do you want to know the results of the Tic-Tac-Toe game?" << endl;
    cout << "Enter 3 lines: " << endl;
    for (int i = 0; i < 3; i++) {
        string tempStr;
        cin >> tempStr;
        field += tempStr;
    }
    cout << "Answer: ";
    if (correctSymb(field) && countVal(field)) {
        if (countWinners(field))
            cout << "Petya won" << endl;
        else if (countWinners(field))
            cout << "Vasya won" << endl;
        else if (winner(field) == ".")
            cout << "Nobody" << endl;
        else
            cout << "Incorrect" << endl;
    }
    else
        cout << "Incorrect" << endl;
    return 0;
}
