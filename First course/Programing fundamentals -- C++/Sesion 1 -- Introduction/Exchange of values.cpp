#include<iostream>         
using namespace std;

int main () {
	
	int caja_izda;
	int caja_dcha;
	int aux;

	cout<<"Introduzca valor de caja derecha:";
	cin>>caja_dcha;
	cout<<"introduzca valor de caja iquierda:";
	cin>>caja_izda;
	
	 aux=caja_izda;
	 caja_izda = caja_dcha; 
	 caja_dcha = aux;
	
	cout<<"El valor de la caja derecha es:"<<caja_dcha<<endl;
	cout<<"El valor de la caja izquierda es :"<<caja_izda;
	
	return 0;
}