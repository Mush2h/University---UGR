
#include <chrono>
#include <iostream>
using namespace std;


class Cronometro{
private:
   typedef std::chrono::time_point<std::chrono::steady_clock> Punto_en_el_Tiempo;
   typedef chrono::duration <double, nano>  IntervaloTiempo;

   Punto_en_el_Tiempo inicio;
   Punto_en_el_Tiempo final;   // Podr�a haberse puesto como dato local a MiliSegundosTranscurridos
public:
   void Reset(){
      inicio = chrono::steady_clock::now();
   }
   double MiliSegundosTranscurridos(){
      final = chrono::steady_clock::now();
      IntervaloTiempo diferencia = final - inicio;

      return diferencia.count() / 1e+6;  // count() devuelve nanosegundos
   }
};


class  SecuenciaCaracteres{
private:
   static  const  int  TAMANIO  =  22e+5;
   char  vector_privado[TAMANIO];
   int  total_utilizados;
public:
   SecuenciaCaracteres()
      :total_utilizados(0)
   {
   }

   int  TotalUtilizados(){
      return  total_utilizados;
   }

   int Capacidad(){
      return TAMANIO;
   }
   
   void  Aniade(char  nuevo){
      if (total_utilizados  <  TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }

   void AniadeCadena(string nuevo){
      int tope = nuevo.size();

      for (int i = 0; i < tope; i++)
         Aniade(nuevo[i]);
   }

   char Elemento(int  indice){
      return  vector_privado[indice];
   }

   void Modifica(int indice_componente, char nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }
   
   string ToString(){
      // Si el n�mero de caracteres en memoria es muy grande,
      // es mucho m�s eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++)
         cadena.push_back(vector_privado[i]);
         //cadena = cadena + vector_privado[i]  <- Evitarlo. Muy ineficiente para tama�os grandes;

      return cadena;
   }
   
   // Elimina una componente, dada por su posici�n
   void Elimina(int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i=posicion ; i<tope ; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }
   }

   int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, char buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }

   int PrimeraOcurrencia (char buscado){
      return PrimeraOcurrenciaEntre(0, total_utilizados - 1, buscado);
   }

   void Ordena_por_Insercion(){
      int izda, i;
      char a_desplazar;

      for (izda=1; izda < total_utilizados; izda++){
         a_desplazar = vector_privado[izda];

         for (i=izda; i > 0 && a_desplazar < vector_privado[i-1]; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[i] = a_desplazar;
      }
   }
   
   ///////////////////////////////////////////////////////////////////////
   
   void EliminaRepetidos_con_VectorLocal(){
      /*
      Recorrer todas las componentes del vector original
         Si la componente NO est� en el vector sin_repetidos,
         a�adirla (al vector sin_repetidos)

      Asignar las componentes de sin_repetidos al vector original
      */
      char sin_repetidos[TAMANIO];
      bool encontrado_en_repetidos;
      int utilizados_en_repetidos;

      if (total_utilizados > 0){
         sin_repetidos[0] = vector_privado[0];
         utilizados_en_repetidos = 1;

         for (int actual = 1; actual < total_utilizados; actual++){
            encontrado_en_repetidos = false;

            for (int j = 0; j < utilizados_en_repetidos && !encontrado_en_repetidos; j++){
               if (vector_privado[actual] == sin_repetidos[j])
                  encontrado_en_repetidos = true;
            }

            if (!encontrado_en_repetidos){
               sin_repetidos[utilizados_en_repetidos] = vector_privado[actual];
               utilizados_en_repetidos++;
            }
         }

         for (int i=0; i<utilizados_en_repetidos; i++)
            vector_privado[i] = sin_repetidos[i];

         total_utilizados = utilizados_en_repetidos;
      }
   }

   void EliminaRepetidosIneficiente(){
      /*
         Recorrer todas las componentes del vector original
            Si la componente es igual a alguna de las componentes que
            hay a su izquierda, eliminarla
      */
      int i = 1, pos_encontrado;

      while (i < total_utilizados){
         pos_encontrado = PrimeraOcurrenciaEntre (0, i-1, vector_privado[i]);

         if (pos_encontrado != -1)
            Elimina(i);
         else
            i++;
      }

      // Importante: i++ debe ir dentro de else. En caso contrario, no funcionar�a
      // correctamente si hubiese dos repetidos consecutivos que hubiese que eliminar
   }
   
   void EliminaRepetidos(){
      /*
      Idea:
 
         Las componentes no repetidas se van a ir colocando al principio del vector.
         Para ello, comprobamos si cada componente est� en el subvector
         izquierdo de componentes no repetidas.
         En el caso de que no est�, colocamos la componente al final del subvector
   
 
      Descripci�n del Algoritmo:
   
         Recorrer todas las componentes v[pos_lectura] con pos_lectura > 0
            Si la componente v[pos_lectura] NO se encuentra entre
            las posiciones 0 y pos_escritura,
            colocamos dicha componente en pos_escritura.
      */
   
      int pos_escritura, pos_lectura;
      int pos_encontrado;

      if (total_utilizados > 0){
         pos_escritura = 1;

         for(pos_lectura=1; pos_lectura < total_utilizados; pos_lectura++){
            pos_encontrado = PrimeraOcurrenciaEntre(0, pos_escritura-1,
                                             vector_privado[pos_lectura]);

            if (pos_encontrado == -1){
               vector_privado[pos_escritura] = vector_privado[pos_lectura];
               pos_escritura++;
            }
         }

         total_utilizados = pos_escritura;
      }
   }

};



class LectorSecuenciaCaracteres{
private:
   char terminador;
public:
   LectorSecuenciaCaracteres(char caracter_terminador)
      :terminador(caracter_terminador)
   {
   }
   SecuenciaCaracteres Lee(){
      SecuenciaCaracteres a_leer;
      int total_introducidos;  // Esta variable es para contar los introducidos
                               // y que no nos pasemos de la capacidad de la secuencia.
      int capacidad_secuencia;
      char caracter;

      total_introducidos = 0;
      capacidad_secuencia = a_leer.Capacidad();
      caracter = cin.get();

      while (caracter == '\n')
         caracter = cin.get();

      while (caracter != terminador && total_introducidos < capacidad_secuencia){
         a_leer.Aniade(caracter);
         total_introducidos++;
         caracter = cin.get();
      }

      return a_leer;
   }
};




int main(){
   const char TERMINADOR = '#';
   Cronometro crono_mayusculas;
   LectorSecuenciaCaracteres lector_secuencias(TERMINADOR);
   double milisegundos_transcurridos;
   
   SecuenciaCaracteres secuencia;

   /*
   secuencia.Aniade('H');
   secuencia.Aniade('H');
   secuencia.Aniade('o');
   secuencia.Aniade('l');
   secuencia.Aniade('a');
   secuencia.Aniade('a');
   secuencia.Aniade('a');
   secuencia.Aniade('H');
   */
   
   // Lectura

   secuencia = lector_secuencias.Lee();
   
   crono_mayusculas.Reset();
   secuencia.EliminaRepetidos();
   // secuencia.EliminaRepetidosIneficiente();
   milisegundos_transcurridos = crono_mayusculas.MiliSegundosTranscurridos();

   secuencia.Ordena_por_Insercion();

   cout << "\nTiempo de ejecuci�n del m�todo: " << milisegundos_transcurridos << " milisegundos";
   cout << "\n\nCaracteres no repetidos, una vez ordenados:\n";
   cout  << secuencia.ToString() << " ";
   
   // Con el Quijote, el m�todo eficiente tarda 75 milisegundos
   // mientras que el ineficiente tarda m�s de una hora!! (en un i7)
}
