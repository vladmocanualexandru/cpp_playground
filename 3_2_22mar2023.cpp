#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
    Citeste de la tastatura n si n numere; afiseaza produsul maxim a 2 elemente din sir

*/
int main(){
    cout << "n=";
    int n;
    cin >> n;

    int sir[n];

    for (int i=0; i<n; i++) {
        cout<<"sir["<<i<<"]=";
        cin>>sir[i];
    }

    int produsMaxim = -1;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            produsMaxim = max(produsMaxim, sir[i]*sir[j]);
        }
    }

    cout<<"Produs maxim="<<produsMaxim<<endl;
    
    return 0;
}
