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

    int pozitii[n]; // sir cu pozitiile cautate
    int lungimePozitii = 0; // lungime sir cu pozitii 

    // ideea e ca o sa analizam fiecare numar, pe masura ce este citit:
    // ... numar numar numar penultim ultim curent
    // analizam ultim == 3 si penultim != 0 si curent != 0;
    //    daca e adevarata conditia, adaugam pozitia lui ultim la sirul de solutii 
    int numarPenultim=-1;
    int numarUltim=-1;
    int numarCurent;


    for (int pozitie=0; pozitie<n; pozitie++) {
        cout<<"numarul #"<<(pozitie+1)<<" = ";
        cin>>numarCurent;

        if (numarUltim == 3 && numarPenultim != 0 && numarCurent != 0 ) {
            // pozitie + 1, deoarece enuntul considera prima pozitie fiind 1, a doua 2, etc
            // pozitie -1, deorece nu ne referim la pozitia curenta - numarul analizat este anterior
            pozitii[lungimePozitii] = pozitie; 
            lungimePozitii++;
        }

        numarPenultim = numarUltim;
        numarUltim = numarCurent;
    }

    // ultimul numar nu este acoperit, asa ca o verificam individual
    if (numarUltim == 3 && numarPenultim != 0) {
        // pozitia ultimului numar este n-1 dar problema cere pozitie+1, deci n-1+1 == n
        pozitii[lungimePozitii] = n; 
        lungimePozitii++;
    }

    // afisam raspunsul confirm enuntului
    if (lungimePozitii > 0) {
        cout<<"Raspuns = ";
        for (int i=0; i<lungimePozitii; i++) {
            cout<<pozitii[i]<<" ";
        }
    } else {
        cout<<"Nu exista.";
    }

    cout<<endl;
    return 0;
}
