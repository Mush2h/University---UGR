
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main(){
   const char TERMINADOR = '#';    
   const int TAMANIO = 100;
   char vector[TAMANIO];
   int total_utilizados;
   char caracter;   
   bool es_palindromo;
   int  izda, dcha;
   char intercambia;

   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:
   
   total_utilizados = 0;
   caracter = cin.get();
   
   while (caracter != TERMINADOR && total_utilizados < TAMANIO){
      vector[total_utilizados] = caracter;
      total_utilizados++;
      caracter = cin.get();
   }

   
   //////////////////////////////////////////////////////////////////
   // Pal�ndromo:


   es_palindromo = true;
   izda = 0;
   dcha = total_utilizados - 1;

   while (izda < dcha && es_palindromo){
      if (vector[izda] != vector[dcha])
         es_palindromo = false;
      else{
         izda++;
         dcha--;
      }
   }

   if (es_palindromo)
      cout << "\nEs pal�ndromo";
   else
      cout << "\nNo Es pal�ndromo";
  
   //////////////////////////////////////////////////////////////////
   // Invierte:   

   izda = 0;
   dcha = total_utilizados - 1;

   while (izda < dcha){
      intercambia = vector[izda];
      vector[izda] = vector[dcha];
      vector[dcha] = intercambia;
      izda++;
      dcha--;
   }
   
   cout << "\nComponentes del vector despu�s de invertirlo: <";
   
   for (int i = 0; i < total_utilizados; i++)
      cout  << vector[i] << " ";
   
   cout << ">\n";

}
