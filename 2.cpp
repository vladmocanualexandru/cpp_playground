#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){

    cout<<"n=";
    int n;
    cin>>n;

    int sir[n]; 

    for(int i=0; i<n; i++) {
    	cout<<"sir["<<i<<"]=";
    	cin>>sir[i];
    }

    /*
     1 2
     1 3
     1 4 
     ...
     1 n
	 2 1
	 2 3
	 2 4
	 2 5
	 ...
	 2 n
	 3 1
	 3 2
	 3 4
	 3 5

	 10 2 4 6 8
    */

    int produsMaxim = 1;
    //for(int i1=0; i1<n-1; i1++) {
    for(int i1=0; i1<n; i1++) {
    	int numarA = sir[i1];

    	//for(int i2=i1+1; i2<n; i2++) {
    	for(int i2=0; i2<n; i2++) {
    		int numarB = sir[i2];
    		int produs = numarA*numarB;

    		if (numarA != numarB && produs > produsMaxim) {
    			produsMaxim = produs;
    		}
    	}
    }

    cout<<"Produs maxim="<<produsMaxim<<endl;

    return 0;
}
