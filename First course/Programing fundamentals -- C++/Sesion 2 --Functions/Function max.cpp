#include <iostream> 
using namespace std;    
 
double max (double a, double b){
    return a>b ? a : b;
}
 
double max3 (double a, double b, double c){
    return max(max(a,b),c);
}
 
int main(){
     
    //DECLARACION DE VARIABLES
    double a,b,c;
     
    //ENTRADA DE DATOS 
    cout << "Introducir tres numeros : ";
    cin >> a >> b >> c;
     
    //SALIDAS
    cout << "Maximo de " << a << " , " << b << " , " << c << "  es  " << max3(a,b,c);
    return 0;
}
