#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// se citesc n numere de la tastatura - numere intre 0 si 3;
// sa se afiseze pozitiile (1,2,3,4...) numerelor 0, care nu sunt "invecinate" de 0
// ex: [3] 1 3 0 1 [3] 2
// raspuns: 1 6

int main(){
    int n; // numar numere

    cout<<"n=";
    cin>>n; // citire numar numere

    int sir[n]; //sir de numere

    // citire sir de numere
    for (int i=0; i<n; i++) {
        cout<<"numarul #"<<(i+1)<<" = ";
        cin>>sir[i];
    }

    // parcurgere sir si cautare de solutii

    // existaSolutie o sa devina true, in momentul in care este gasita o solutie
    bool existaSolutie = false;

    // verifica primul numar
    if (sir[0] == 3 && sir[1] != 0) {
        cout<<1<<" ";
        existaSolutie = true;
    }

    // verifica toate numerele de la al doilea pana la penultimul inclusiv
    for (int i=1; i<n-1; i++) {
        if (sir[i] == 3 && sir[i-1] != 0 && sir[i+1] != 0) {
            cout<<(i+1)<<" ";
            existaSolutie = true;
        }
    }

    // verifica ultimul numar
    if (sir[n-1] == 3 && sir[n-2] != 0) {
        cout<<n<<" ";
        existaSolutie = true;
    }

    // daca nu exista o solutie, afiseaza "nu exista"
    if (!existaSolutie) {
        cout<<"nu exista";
    }

    cout<<endl;
    return 0;
}
