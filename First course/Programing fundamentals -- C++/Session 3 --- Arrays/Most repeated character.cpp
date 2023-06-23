#include <iostream>
using namespace std;

struct LetraFrecuencia{
    char letra;
    int frecuencia=0;
};
 

int main(){
 
    // Si queremos poner el 'fin de fichero' como terminador
    // usaremos cin.eof() en lugar de TERMINADOR
    const char TERMINADOR = '*';
     
    char entrada;
    const int TAM = 256;
    LetraFrecuencia V[TAM];
     
    int frecuencia_maxima = 0;
    int pos_maxima = 0;
     
     
    // INICIALIZAMOS LOS struct CON SU RESPECTIVA LETRA
    for(int i=0;i<TAM;i++)
        V[i].letra = i;
     
    entrada = cin.get();
    while(entrada != TERMINADOR){
        V[entrada].frecuencia++;
         
        if(V[entrada].frecuencia > frecuencia_maxima){
            frecuencia_maxima = V[entrada].frecuencia;
            pos_maxima = entrada;
        }
         
        entrada = cin.get();
    }
     
    cout << "\nCARACTER MAS REPETIDO " << V[pos_maxima].letra << "\t(" << frecuencia_maxima << " veces)";
 
    return 0;
}