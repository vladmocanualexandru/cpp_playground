#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main(){
    ifstream fisier("bac.in");

    int sir[(int)pow(10,6)];
    int n = 0;

    int a;
    while(fisier>>a) {
        sir[n] = a;
        n++;
    }

    // consideram activa paritatea primului numar
    int paritateActiva = sir[0]%2;
    int lungimeSecventaParitate = 1;
    int lungimeSecventaMaxima = -9999;
    
    // incepem cu al doilea numar doarece primul a fost analizat anterior
    for(int i=1; i<n; i++) {
        int numarCurent = sir[i];

        if (numarCurent%2!=paritateActiva) {
            //cout<<"DING! lungime secventa="<<lungimeSecventaParitate<<endl;

            if(lungimeSecventaParitate>lungimeSecventaMaxima) {
                lungimeSecventaMaxima = lungimeSecventaParitate;
            }

            paritateActiva = numarCurent%2;

            lungimeSecventaParitate = 1;
        } else {
            lungimeSecventaParitate++;
        }
    }

    if(lungimeSecventaParitate>lungimeSecventaMaxima) {
        lungimeSecventaMaxima = lungimeSecventaParitate;
    }

    cout<<"Lungime maxima "<<lungimeSecventaMaxima<<endl;

    return 0;
}
