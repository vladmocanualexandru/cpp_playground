#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
    Se citeste un numar n de la tastatura; programul afiseaza al n-lea numar din seria:
    1,2,3,2,1,2,3,4,5,6,5,4,3,2,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1...
*/
int main(){

    cout << "n=";

    int n;
    cin>>n;

    int numar = 1;
    int delta = 1;
    int tinta = 0;

    for (int c = 2; c<=n; c++) {
        cout << numar << endl;

        if (numar == tinta) {
            delta = -1;
        } else if (numar == 1) {
            delta = 1;
            tinta += 3;
        }

        numar += delta;        
    }

    cout<<"rezultat="<<numar<<endl;

    return 0;
}
