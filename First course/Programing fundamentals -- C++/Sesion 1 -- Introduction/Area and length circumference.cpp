#include<iostream>         // Primero incluimos las bibliotecas
#include<cmath>

using namespace std;

int main () {
	
	double radio;
	const double PI=3.1416;			// Declaramos las variables y asiganmos el valor PI
	double area;
	double longitud;
	
	
	cout<<"Escribe el valor de radio";		// Escribimos el mensaje que se nos mostrara en la consola
	cin>> radio;
	
	area= PI*(radio*radio);
	longitud= 2*PI*radio;					//Escribimos las formulas matematicas.
	
	cout<<"\n El area es:"<<area<<endl;			// Escribimos el resultado de la ecuacion
	cout<<"\n la longitud es:"<<longitud;
	
	return 0;
}