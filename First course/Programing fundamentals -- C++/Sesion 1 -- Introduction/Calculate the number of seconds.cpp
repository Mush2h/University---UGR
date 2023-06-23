#include<iostream>
using namespace std;
int main(){
 	
	long long hora_i,minutos_i,segundos_i, hora_f,minutos_f,segundos_f,horas_ambos, minutos_ambos,segundos_ambos,segundos_ambos_finales;
 	const double segundos_hora=3600;
 	const double minutos_hora=60;
 	
 	
 	cout<<"Escriba el valor de la hora inicial:";
 	cin>> hora_i;
 	cout<<"Escriba el valor de los mininutos iniciales:";
 	cin>> minutos_i;
 	cout<<"Escriba el valor de los segundos iniciales:";
 	cin>>segundos_i;
 	cout<<"Escriba el valor de la hora final:";
 	cin>> hora_f;
 	cout<<"Escriba el valor de los mininutos finales:";
 	cin>> minutos_f;
 	cout<<"Escriba el valor de los segundos finales:";
 	cin>>segundos_f;
 
 	
 	horas_ambos= (hora_f - hora_i) * segundos_hora;
 	minutos_ambos=(minutos_f - minutos_i) * minutos_hora;
 	segundos_ambos=(segundos_f-segundos_i);
 	segundos_ambos_finales= horas_ambos + minutos_ambos + segundos_ambos;

 	cout<<"\n El numero de segundos entre ambos instantes es  :"<< segundos_ambos_finales<<endl;

 	return 0;
 	
 	
 }