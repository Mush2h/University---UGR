
#include <iostream>
#include <string.h>
 
using namespace std;
 
 
const double    VERSION_GAME        = 1.1;
const string    NOMBRE_GAME         = "GAME ADVENTURE";
 
 
/*
    CLASE PERSONAJE.
        Atributos:
            Nombre;
            Vida:
            Fuerza:
            Armadura:
     
*/

class Personaje{
     
    private:
        string nombre;
        int vida, fuerza, armadura;
     
    public:
        Personaje (){}
         
        Personaje(string name, int nvida, int nfuerza, int narmad){
            insertar_datos(name,nvida,nfuerza,narmad);
        }
         
        void insertar_datos (string name, int nvida, int nfuerza, int narmad){
            nombre = name;
            vida = nvida;
            fuerza = nfuerza;
            armadura = narmad;
        }
         
        string get_nombre(){
            return nombre;
        }
         
         
        int get_vida(){
            if(vida < 0)
                vida = 0;
            return vida;
        }
         
        int get_fuerza(){
            if(fuerza < 1)
                fuerza = 1;
            return fuerza;
        }
         
        int get_armadura(){
            if(armadura < 0)
                armadura = 0;
            return armadura;
        }
     
        void herir(int herida){
            vida -= herida;
        }
         
        void curar(int sanacion){
            vida += sanacion;
        }
         
        void renombrar(string nuevo){
            nombre = nuevo;
        }
         
        void aumentar_fuerza(int aum){
            if(aum < 1)
                aum = 1;
            fuerza += aum;
        }
         
        void aumentar_armadura (int aum){
            if(aum < 1)
                aum = 1;
            armadura += aum;
        }
     
};
 
 
//Funcion Muestra_Datos
void Muestra_Datos (Personaje P);
 
 
int main(){
     
    const int TAM_ENEMIGOS = 4;
    const int RONDAS_MAXIMAS = 20;
     
    //Iniciamos un personaje inicial con datos por defecto
     
    Personaje inicial("inicial",25,5,2);
     
    //Base de datos de enemigos
    Personaje unidades[TAM_ENEMIGOS];
    unidades[0].insertar_datos("Ciervo",12,3,1);
    unidades[1].insertar_datos("Cabra",14,4,1);
    unidades[2].insertar_datos("Halcon",13,5,2);
    unidades[3].insertar_datos("Cocodrilo",20,6,3);
     
     
     
    string str;
     
    cout << "\n------------------------\n"
        << NOMBRE_GAME
        << "\n------------------------\n"
        << "\nVersion : " << VERSION_GAME << "\n";
     
     
    cout << "\nIntroduzca su nombre :  ";
    cin >> str;
    inicial.renombrar(str);
     
     
    char resp;
    Personaje enemigo;
    int enemigo_a_vencer = 0, contador_ronda, dano;
    while(inicial.get_vida() > 0 && enemigo_a_vencer < TAM_ENEMIGOS){
         
        enemigo = unidades[enemigo_a_vencer];
        contador_ronda = 1;
        while(enemigo.get_vida()>0 && inicial.get_vida()>0 && contador_ronda < RONDAS_MAXIMAS){
            cout << "\nRonda : " << contador_ronda++;
            dano = inicial.get_fuerza() - enemigo.get_armadura();
            if(dano < 0)
                dano = 0;
            enemigo.herir(dano);
            cout << "\n" << enemigo.get_nombre() << " recibio " << dano << " puntos de dano!";
            if(enemigo.get_vida() > 0){
                dano = enemigo.get_fuerza() - inicial.get_armadura();
                if(dano < 0)
                    dano = 0;
                inicial.herir(dano);
                cout << "\n" << inicial.get_nombre() << " recibio " << dano << " puntos de dano!";    
            }
        }
         
 
        if(inicial.get_vida() > 0){
             
            do{
                cout << "\nDesea luchar contra el siguiente enemigo? (s/n) : ";
                cin >> resp;
            }while(resp != 's' && resp != 'n');
             
            if(resp == 's'){
                inicial.curar(3 + enemigo.get_vida()*0.2);
                //Mejora "subida de nivel"
                if(enemigo_a_vencer%3)
                    inicial.aumentar_fuerza(enemigo_a_vencer%3);
                else
                    inicial.aumentar_armadura(1);
                     
                enemigo_a_vencer++;
            }else
                inicial.curar(1 + enemigo.get_vida()*0.1);
        }
 
    }
     
    if(inicial.get_vida() > 0)
        cout << "\n\nENHORABUENA HAS GANADO!!";
    else
        cout << "\n\nVaya, has perdido... \n\t(Superaste " << enemigo_a_vencer << "/"
            << TAM_ENEMIGOS  << " enemigos...)";
        
    cout << "\n\n";
    return 0;
}
 
 
//----------------
//FUNCIONES
//---------------
 
 
void MuestraDatos(Personaje P){
    cout
        << "\nNOMBRE   : " << P.get_nombre()
        << "\nVIDA     : " << P.get_vida()
        << "\nFUERZA   : " << P.get_fuerza()
        << "\nARMADURA : " << P.get_armadura();
}
