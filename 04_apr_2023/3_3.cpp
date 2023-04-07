#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

/*
    doua numere x si y sunt p-ordonate daca au aceeasi paritate sau paritate diferita si x>y
    din fisier se citeste n si apoi sir de 2*n numere
    sirul este ip-ordonat daca primele n numere sunt pare sau
    daca fiecare numar impar in primele n numere, este p-ordonat cu fiecare numar din ultmele n numere
    daca sirul este ip-ordonat, se afiseaza DA altfel NU
*/

int main(){
    ifstream fisier("bac.in");

    // citim numarul n, care reprezinta lungimea celor 2 jumatati de numere din sir
    int n;
    fisier>>n;

    // citim primele n numere, in timp ce tinem cont de cel mai mic numar impar
    int numar;
    int minimImpar = pow(10,6)+1;
    for (int i=0; i<n; i++) {
        fisier>>numar;

        if (numar%2==1 && numar < minimImpar) {
            minimImpar = numar;
        }
    }

    // daca nu a fost gasit un numar impar, atunci inseamna ca primele n numere sunt impare => se afiseaza DA
    if (minimImpar == pow(10,6)+1) {
        cout<<"DA";
    } else {
        // altfel cautam numarul par maxim, in urmatoare n numere
        int maximPar = -1;    
        for (int i=0; i<n; i++) {
            fisier>>numar;

            if (numar%2==0 && numar>maximPar) {
                maximPar = numar;
            }
        }

        // in final, fiecare numar impar din primele n numere trebuie sa fie mai mare decat orice numar par din urmatoarele n numere
        // adica cel mai mic numar impar din stanga, trebuie sa fie mai mare decat cel mai mare numar par din dreapta
        if (minimImpar>maximPar) {
            cout<<"DA";
        } else {
            cout<<"NU";
        }
    }

    cout<<endl;
    return 0;
}
