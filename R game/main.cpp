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
    cout << "-----------" << endl;
    for (int y = 0; y<q; y++) {
        for (int x = 0; x<q; x++) {
            p[y][x] = ' ';
        }
    }
newpole:
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

    while (true) {
        system("cls");
        for (int y1 = 0; y1<q; y1++) {
            for (int x1 = 0; x1<q; x1++) {
                cout << '|' << p[y1][x1];
            }
            cout << '|' << endl << "-----------" << endl;
        }
        cout << endl << "Enter w(up), s(down), a(left) or d(right)" << endl;
        char cont;
        m = y;
        n = x;
        cin >> cont;
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
        }
        p[m][n] = ' ';
        if (p[y][x] == 'W') {
            goto newpole;
        }
        else {
            break;
        }
    }
    system("cls");
    cout << "Game over!";
    return 0;
}
