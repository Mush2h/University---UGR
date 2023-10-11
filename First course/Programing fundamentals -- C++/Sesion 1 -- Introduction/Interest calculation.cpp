#include<iostream>         // Primero incluimos las bibliotecas
using namespace std;

int main () {
	
	double capital;
    	double interes;	// declaramos las variables
	double total;
	
	cout<<"Introduzca el capital:";			
	cin>>capital;
	cout<<"Introduzca el interes :";			
	cin>>interes;
	
	total= capital + capital * interes / 100;		
	
	cout<<"El valor total es :"<<total;
	
	
 	return 0;
}
