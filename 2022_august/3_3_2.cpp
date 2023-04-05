#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main(){
    ifstream fisier("bac.in");

    // int sir[(int)pow(10,6)];
    // int n = 0;

    int paritateCurenta = 0;
    int lungimeSec = 0;
    int lungimeMaxima = -8765;

    int a;
    while(fisier>>a) {
        if (a%2!=paritateCurenta) {
            if (lungimeSec>lungimeMaxima) {
                lungimeMaxima = lungimeSec;
            }

            paritateCurenta = a%2;
            lungimeSec = 1;
        } else {
            lungimeSec++;
        }
    }

    if (lungimeSec>lungimeMaxima) {
        lungimeMaxima = lungimeSec;
    }

    cout<<"raspuns:"<<lungimeMaxima<<endl;

    return 0;
}
