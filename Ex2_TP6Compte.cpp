#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;
class Compte{
    float solde;
	static int numero;
	const int cle;

public:
	Compte (float s=0) : solde(s),cle(++numero){
		cout<<"creation du compte num : " << numero<< endl;
		cout<<"le nombre des comptes est: "<<cle<< endl;
	}
	
	Compte (const Compte & c) : solde(c.solde),cle(numero){
		cout<< "copie du compte num : "<< numero<< endl;
		cout<<"le nombre des comptes est : "<<cle<< endl;
	}
/* solution de la question 3 et 4
	void operator << (float s){
		solde +=s;
		
	}
	
	void operator >> (float s){
		solde -=s;
	}
*/	
//solution de la question 6
	Compte & operator << (float s){
		solde +=s;
		return *this ;
		
	}
	
	Compte & operator >> (float s){
		solde -=s;
		return *this ;
	}

	
	float getSolde(){
	return solde;}
};
int Compte::numero=0;
int main(){
	Compte C1;
	Compte C2=C1;
	C1<<5.2<<3.3;
	C1>>5.5 ;
	cout << C1.getSolde();
}
		
       