
 #include<iostream>
 #include<cmath>

 using namespace std;
 
 int main(){
 	
 	// declaracion de variables
 	double med , desv, x ,gau,max,min,incremento,i;
 	const double PI=3.1416;
 	
 	cout<<"Escriba el valor de la media:";
 	cin>>med;
 	cout<<"Escriba el valor de la desviacion:";
 	cin>>desv;
 	cout<<"Escriba el valor de x:";
 	cin>>x;
 	cout<<"Escriba el valor maximo:";
 	cin>>max;
 	cout<<"Escriba el valor del minimo:";
 	cin>>min;
 	
 	if (max>min && desv>= 0){
 		cout<<"Introducir el incremento"<<endl;
 		cin>>incremento;
	 
 	
 	    //computos
 	    while(max>= x){
	        i++;
 	        gau = exp(-0.5 * pow (((x-med) / desv),2)) / (desv * sqrt (2 * PI));
 	        cout<<"El valor es:"<<gau;
        }
    }else{
 	    cout<<"No se pudo calcular"<<endl;
    }
 	return 0;
}
