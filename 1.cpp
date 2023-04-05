#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    cout<<"n=";
    int n;
    cin>>n;

    // 1 2 3 2 1 2 3 4 5 6 5 4 3 2 1 2 3 4 5 6 7 8 9 8 7 6 5 4 ...

    int numar = 1;
    int delta = 1;
    int tinta = 0;
    for (int numarator = 2; numarator <= n; numarator++) {
       
        if (numar == tinta) {
            delta = -1;
        } else if (numar == 1) {
            delta = 1;
            tinta = tinta + 3;
            // tinta+=3;
        }

        numar = numar + delta;
        //cout<<numar<<endl;

    }

    cout<<"rezultat="<<numar<<endl;

    return 0;
}
