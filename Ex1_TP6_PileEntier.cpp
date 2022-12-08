#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;
class PileEntier{
    int nelem;
    int dim;
    int *adr;

    public:
        PileEntier(int n){
           nelem=0;
           dim=n;
           adr=new int[n];

        }
        
        PileEntier(){
           nelem=0;
           dim=20;
           adr=new (int[20]); 

        }

       //consturcteur par recopie
        PileEntier (PileEntier& P){
            nelem= P.nelem;
            dim=P.dim;
            adr= new int[dim];
            for(int i=0; i<nelem; i++){
                adr[i]=P.adr[i];
            }

        }
        ~PileEntier(){
            delete(adr);
        }
        bool vide(){
            return nelem==0;
          
        }
        bool pleine(){
            return (nelem==dim);
        }

        void empiler(int p){//on ne peut empiler que si la pile n'est pas encore pleine 
            assert(!pleine());
            adr[nelem++]=p;
        }

        void depiler(){//on ne peut dépiler que si la pile n'est pas vide
            assert(!vide()); 
            nelem--;
        }

        int dernier(){
            assert(!vide());
            return adr[nelem-1];

        }
//Question C en utilisant des fonctions membres
        /*  void operator< (int n){
            empiler(n);
        }
        void operator> (int &n){
           n=dernier();
            depiler();
        }*/
//Question C en utilisant des fonctions amies	
	friend void operator< (PileEntier &P, int n); 
    friend void operator> (PileEntier &P, int &n);

};
 void operator< (PileEntier &P, int n){
    P.empiler(n);
 }
 void operator> (PileEntier &P, int &n){
           n=P.dernier();
           P.depiler();
        }

int main(){
    PileEntier a(10);
    PileEntier b= a;//appel constructeur par recoppie
    PileEntier *T;
    int n=20;
    T=new PileEntier[20];
   

    a<5; a<6; a<17; // 3 empilements
    int x;
    a>x;	//retourne le dernier dans x puis dépiler
    cout <<x << endl; //noremalement il affiche la valeur 17
   
}