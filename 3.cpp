#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

/*

12345
 vvv
 234

*/

int extragePrimaCifra(int numar){
	int rezultat;
	
	if (numar > 9999) {
		// 5 cifre
		rezultat = numar / 10000;
	} else if (numar > 999) {
		// 4 cifre
		rezultat = numar / 1000;
	} else {
		// 3 cifre
		rezultat = numar / 100;
	}

	return rezultat;
}

// pentru oricate cifre, extragerea primei cifre:
// 354387
// 1. while(nr>10) nr = nr / 10;
// 2. log10(354387) = 5,... -> 5, pow(10,5)=100000, 354387 / 100000 == 3
// 3. int -> char*/string, stringulMeu[0] -> int 


int tundeNumar(int numar) {
	int rezultat;
	// elimina prima cifra
	// 23635 % 10000 == 3635

	if (numar > 9999) {
		// 5 cifre
		rezultat = numar % 10000;
	} else if (numar > 999) {
		// 4 cifre
		rezultat = numar % 1000;
	} else {
		// 3 cifre
		rezultat = numar % 100;
	}

	// elimina ultima cifra
	// 24 / 10 == 2
	rezultat = rezultat / 10;

	return rezultat;
}

void sorteazaNumere(int* sir, int n){

	// 32<>6 5 87 23 6
	// 6 32<>5 87 23 6
	// 6<>5 32 87 23 6
	// 5 6 32 87<>23 6
	// 5 6 32<>23 87 6
	// ...
	// 5 6 6 23 32 87

	bool sirSortat = false;
	while(sirSortat==false) {
	//while(!sirSortat) {
	//while(sirSortat!=true) {	
		sirSortat = true;

		for (int i=0; i<n-1; i++) {
			if (sir[i] < sir[i+1]) {
				// daca numarul curent este mai MIC decat urmatorul, le invart
				// a=3, b=7
				// aux=a, a=b, b=aux
				// schimbare numere fara aux VVVVVVVV
				// b=b-a; a=a+b; b=a-b;
				// 7-3=4  3+4=7  7-4=3

				int aux = sir[i];
				sir[i] = sir[i+1];
				sir[i+1] = aux;

				sirSortat = false;
			}
		}
	}
}

// int* alocaSpatiuPtNumar(int* sirVechi, int n, int numarNou) {
// 	int* sirNou = (int*)calloc(n+1, sizeof(int));

// 	// 12 4 3     + 99
// 	// _  _ _   _ 
// 	// 12 4 3   99

// 	for(int i=0; i<n; i++) {
// 		sirNou[i] = sirVechi[i];
// 	}

// 	sirNou[n] = numarNou;
	
// 	return sirNou;
// }

int main(){
	// citesc numerele din fisier
    ifstream bacIn("bac.in");

    int numar;
    int sir[(int)pow(10,6)];
    int n = 0;

    // int* sir2 = (int*)calloc(0, sizeof(int));
    // int n2 =0;

    while(bacIn>>numar) {   
    	int primaCifra = extragePrimaCifra(numar);
    	int ultimaCifra = numar%10;	

    	if (primaCifra == ultimaCifra) {
    		//caz de interes - numarul are prima si ultima cifra la fel
    		sir[n] = tundeNumar(numar);
    		n++;

    		// sir2 = alocaSpatiuPtNumar(sir2, n2, numar);
    		// n2++;
    	}
    }

    // sortez numerele
    sorteazaNumere(sir, n);

    // afisez numerele in consola
    for (int i=0; i<n; i++) {
    	cout<<"sir["<<i<<"]="<<sir[i]<<endl;
    }

    // cout<<"dimensiune sir "<<sizeof(sir)<<endl;
    // cout<<"dimensiune sir2 "<<sizeof(sir2)<<endl;

    return 0;
}
