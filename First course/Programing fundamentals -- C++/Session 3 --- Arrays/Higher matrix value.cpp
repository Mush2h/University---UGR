#include<iostream>

using namespace std;

int main(){
	
	const int MAX_F=10;
	const int MAX_C=10;
	int matriz[MAX_F][MAX_C],utiles_f,utiles_c,mayor=-100000, fila, temp=0;
	
	//FILTRO PARA LAS FILAS
	do{
		cout<< "Introduce el numero de filas: ";
		cin >> utiles_f;
	}while(utiles_f>MAX_F);
	
	//FILTRO PARA LAS COLUMNAS 
		do{
		cout<< "Introduce el numero de columnas: ";
		cin >> utiles_c;
	}while(utiles_c>MAX_C);
	
	// INTRODUCIR LOS VALORES EN LA CELDAS DE LA MATRIZ
	for(int i=0; i<utiles_f;i++){
		for(int j=0;j<utiles_c;j++){
		
			cout << "Introduce un numero en la fila "<<i<<" y en la columna "<<j<<": ";
			cin >> matriz[i][j];
		}
	}
	
	// PARA VER QUE POSICION ES LA MAYOR SI ES MAYOR QUE LA ANTERIOR LA ALMACENA EN MAYOR Y ALMACENA SU FINA EN LA VARIABLE FILA
	for(int i=0;i<utiles_f;i++){
		for(int j=0; j<utiles_c;j++){
			if(matriz[i][j]>mayor){
				mayor= matriz[i][j];
				fila=i;
			}
					
		}
			
	}
	
	//METODO BURBUJA PARA LA BUSQUEDA
	
	for( int i=0; i<utiles_f;i++){
		for(int j=0; j<utiles_c;j++){
			if(matriz[fila][i]<matriz[fila][j]){
				temp=matriz[fila][i];
				matriz[fila][i]=matriz[fila][j];
				matriz[fila][j]= temp;
			}		
		}			
	}
	
	//MOSTRAMOS LA MATRIZ
	
	for(int i=0;i<utiles_c;i++){
		
			cout<< matriz[fila][i];
			cout<<endl;
		
	}
}