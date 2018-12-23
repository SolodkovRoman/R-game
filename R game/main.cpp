#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    srand(time(NULL));
    int q = 5;
    string p[q];
    for (int i = 0; i<q; i++) {
        p[i] = *new string [q];
    }
    int score = 0;
newpole:
    int hmany = 0;
    for (int y = 0; y<q; y++) {
        for (int x = 0; x<q; x++) {
            p[y][x] = ' ';
        }
    }
    int x = rand() % q;
    int y = rand() % q;
    p[y][x] = 'P';
    int x2 = rand() % q;
    int y2 = rand() % q;
    while (x2 == x && y2 == y) {
        x2 = rand() % q;
        y2 = rand() % q;
    }
    p[y2][x2] = 'X';
    int x3 = rand() % q;
    int y3 = rand() % q;
    while (x3 == x && y3 == y) {
        x3 = rand() % q;
        y3 = rand() % q;
    }
    p[y3][x3] = 'X';
    int x4 = rand() % q;
    int y4 = rand() % q;
    while (x4 == x && y4 == y) {
        x4 = rand() % q;
        y4 = rand() % q;
    }
    p[y4][x4] = 'X';
    int x5 = rand() % q;
    int y5 = rand() % q;
    while (x5 == x && y5 == y) {
        x5 = rand() % q;
        y5 = rand() % q;
    }
    p[y5][x5] = 'X';
    int x6 = rand() % q;
    int y6 = rand() % q;
    while (x6 == x && y6 == y) {
        x6 = rand() % q;
        y6 = rand() % q;
    }
    p[y6][x6] = 'W';
    int m;
    int n;
    char cont = ' ';
    system("cls");
    cout << "-----------" << endl;
    for (int y1 = 0; y1<q; y1++) {
        for (int x1 = 0; x1<q; x1++) {
            cout << '|' << p[y1][x1];
        }
        cout << '|' << endl << "-----------" << endl;
    }
    while (true) {
        m = y;
        n = x;
        system("cls");
        cout << "-----------" << endl;
        for (int y1 = 0; y1<q; y1++) {
            for (int x1 = 0; x1<q; x1++) {
                cout << '|' << p[y1][x1];
            }
            cout << '|' << endl << "-----------" << endl;
        }
        int press = ' ';
        cout << "Enter '1'(for next step) or '2'(for new area)" << endl;
        cin >> press;
        switch (press)
        {
        case 1:
            cout << endl << "Enter w(up), s(down), a(left) or d(right)" << endl << "P.S.: Only this controls" << endl;
            cin >> cont;
            hmany++;
            break;
        case 2:
            score--;
            goto newpole;
        default:
            cout << "U can enter only '1' or '2'!" << endl;
            score--;
        }
        Sleep(100);
        switch (cont)
        {
        case 'w':
            if(y > 0) {
                y--;
            }
            break;
        case 's':
            if(y < q-1) {
                y++;
            }
            break;
        case 'a':
            if(x > 0) {
                x--;
            }
            break;
        case 'd':
            if(x < q-1) {
                x++;
            }
            break;
        default:
            cout << "U can enter only 'w', 's', 'a' or 'd'!" << endl;
            score--;
        }
        if (p[y][x] == 'X'){
                break;
        }
        if (p[y][x] == 'W'){
                score = score + 3;
                if (hmany < 5)
                    score = score + 3;
                else if (hmany < 7)
                    score = score + 3;
                else if (hmany < 10)
                    score = score + 1;
                goto newpole;
        }
        p[m][n] = ' ';
        p[y][x] = 'P';
    }
/*
    int hm = 0;
    for (int g = 0; g<q; g++) {
        for (int h = 0; h<q; h++) {
            if (p[q][h] == 'W') {
                    break;
            }
            else if (p[q][h] != 'W') {
                hm++;
            }
        }
    }
    if (hm == 25) {
        goto newpole;
    }
*/
    system("cls");
    cout << "Game over! ";
    cout << "Your score is: " << score;
    return 0;
}
