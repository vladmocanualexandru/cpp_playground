#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

/*
    numar interior = numar fara prima si ultima cifra; ex: 34 interior pentru 1347
    se citesc din fisier numerele si se afiseaza in ordine descrescatoare numerele interioare,
    care au prima si ultima cifra egale; altfel "Nu exista"
*/  

int* adaugaNumar(int* sir, int n, int numar) {
    int* sirNou = (int*)calloc(n+1, sizeof(int));

    for (int i=0; i<n; i++) {
        sirNou[i] = sir[i];
    }

    sirNou[n] = numar;

    return sirNou;
}

int extragePrimaCifra(int numar) {
    int cifre = (int)log10(numar);
    return (int)numar/pow(10,cifre);
}

int extrageUltimaCifra(int numar) {
    return numar%10;
}

int tunde(int numar, int primaCifra) {
    numar -= primaCifra*pow(10, (int)log10(numar));
    return numar / 10;
}

void sorteazaBubbleDesc(int* sir, int n) {
    bool nesortat = true;
    while (nesortat) {
        nesortat = false;
        for (int i=0; i<n-1; i++) {
            if (sir[i]<sir[i+1]) {
                nesortat = true;
                int aux = sir[i];
                sir[i] = sir[i+1];
                sir[i+1] = aux;
            }
        }
    }
}

int main(){
    ifstream bacin("bac.in");

    int* sir;
    int n = 0;

    int numar;
    while(bacin>>numar) {
        int primaCifra = extragePrimaCifra(numar);
        int ultimaCifra = extrageUltimaCifra(numar);

        if (primaCifra == ultimaCifra) {
            numar = tunde(numar, primaCifra);
            sir = adaugaNumar(sir, n, numar);
            n++;    
        }
        
    }
    
    sorteazaBubbleDesc(sir, n);

    for (int i=0; i<n; i++) {
        cout<<i<<":"<<sir[i]<<endl;
    }

    return 0;
}
