
#include<iostream>
using namespace std;

int main () {

	long long  natalidad,mortalidad,inicial,migracion,operacion1,operacion2,operacion3,operacion4,anio,i , tope,d_inicial;
 	anio =0;
 	i=0;
 	
 	cout<<"Escriba el valor de la poblacion inicial:";
 	cin>>inicial;
	
    if( inicial >0){ 
        cout<<"Escriba el valor de la tasa de natalidad:";
        cin>>natalidad;
        cout<<"Escriba el valor de la tasa de mortalidad:";
        cin>>mortalidad;
    }
 
	if (natalidad > 0 && natalidad<1000 && mortalidad > 0 && mortalidad < 1000){
        cout<<"Escriba el valor de la tasa migracion:";
        cin>>migracion;
        cout<<"Introduzca el numero de anios:";
        cin>>tope;
    }
 	 
 	operacion1= inicial+ ((natalidad - mortalidad + migracion )* 0.001 * inicial);
 	operacion2= inicial+ ((natalidad - mortalidad + migracion )* 0.001 * operacion1);
    	operacion3= inicial+ ((natalidad - mortalidad + migracion )* 0.001 * operacion2);
    
    	d_inicial = inicial *2 ;
    	operacion4 =inicial;
    
    while (tope==anio){
    	tope -- ;
    	operacion1= inicial+ ((natalidad - mortalidad + migracion )* 0.001 * inicial);
 	operacion2= inicial+ ((natalidad - mortalidad + migracion )* 0.001 * operacion1);
        operacion3= inicial+ ((natalidad - mortalidad + migracion )* 0.001 * operacion2);
    }; //repetir la operacion tantos a�os haya 
    
    cout<< operacion3<<"El total es"<<endl;

	while (operacion4< d_inicial){
	 operacion4= inicial+ (natalidad - mortalidad + migracion )* operacion4 + operacion4;
	 i++;
	}//numero de a�os que tiene que pasar hasta alcanzar el doble de la poblacion
	
	cout <<i<<" El total de a�os hasta alcanzar el doble de poblacion"<<endl;
	cout << operacion4<< "el total de poblacion"<<endl;
	
	//resultado 
	cout<< "El resultado es :"<<i<<endl;
	
}

