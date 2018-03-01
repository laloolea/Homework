#include <iostream>
#include <iomanip>

#include <cmath>
using namespace std;

template <typename T>
void CapturaDato (const char *message, T &num);
float Funcion (float x);

int main(){
    // variables para los intervalos y funciones
      float an,bn,xn,fa,fb,fx,k ,aux;
      double epsilon;
    //Booleanos para ver como acomodar datos
      bool faPositivo,fbPositivo;
      int metodoParo,continuar;

      cout <<fixed<<setprecision(15);// Para precisar los decimales


      cout << "Programa de bisección"<<endl;

      do{
          CapturaDato("Qué metodo de paro desea utilizar? (Núm iteraciones=1 , Error truncamiento =2): ",metodoParo);
      }while(metodoParo != 1 &&  metodoParo != 2);

      do {
          cout << "Ingresar intervalo" << endl;

          CapturaDato ("A0 = " , an);// Capturar intervalos
          CapturaDato ("B0 = " , bn);

          if(an > bn){
              aux =bn;
              bn=an;
              an = aux;
          }
          fa = Funcion (an); // Se calculan las funciones en los intervalos dados con una función
          fb = Funcion (bn);


          if (fa * fb > 0) { //Verificamos cambio de signo.
              cout << "En el intervalo [" << an << " , " << bn << "] no hay raíz" << endl;
              do {
                  CapturaDato ("Desea continuar ? (Si=1, No=0 ): " , continuar);
                  if(continuar == 0) {
                      cout<< "\nAdios. \n";
                      return 0;
                  }
              } while (continuar != 0 && continuar != 1);
          }
      }while(fa * fb > 0 );// Y verificamos que el usuario quiera seguir en el programa

      if(metodoParo ==1){
        CapturaDato("Ingrese el núm de iteraciones por favor: ",k);
      }else {
          CapturaDato ("Ingrese el epsilon que desea: " , epsilon);
          k = (log ((bn - an) / epsilon)) / (log (2)); // Se calcula el número de iteraciones
      }

      if(fa>0){
        faPositivo=true; //Un booleano para ver como acomodaremos los valores de an y xn dependiendo de su signo
        fbPositivo=false;
      }else {
          faPositivo = false;
          fbPositivo = true;
      }
        if(fa ==0|| fb ==0){ // El caso cuando te dan la raíz en el intervalo dado ni entra al algoritmo
            cout << "La raiz es exactamente = 0 "<<endl;
        }else {              // empieza el algoritmo
            cout << "Número de iteraciones: " << (int) k << endl << endl;
            cout << "Iteración" << setw (24) << "an" << setw (30) << "bn" << setw (32) << "xn" << setw (35)
                 << "f(xn)" << endl;
            for ( int i = 0 ; i <= k ; ++i ) {
                xn = (an + bn) / 2; // Se calcula la xn
                fx = Funcion (xn); // La función en xn

                cout << setw (12) << i << setw (12) << "\t" << an << setw (12) << "\t" << bn << setw (12) << "\t"
                     << xn
                     << setw (12) << "\t" << fx << setw (12) << endl;

                if (fx == 0) {//Cuando la raíz es exacta sale del ciclo
                    break;
                } else if (fx < 0 && !faPositivo) { // Para cuando fx es negativa y los negativos van en an
                    an = xn;
                } else if (fx < 0 && !fbPositivo) { // para cuando fx es negativa y los negativos van en bn
                    bn = xn;
                } else if (fx > 0 && faPositivo) { // para cuando fx es positiva y los positivos van en an
                    an = xn;
                } else if (fx > 0 && fbPositivo) { // para cuando fx es positiva y los positivos van en bn
                    bn = xn;
                }
                cout << setw (0);
            }

            if (fx == 0) { // Si la raiz da exacta
                cout << "\n\n\nLa raiz es exactamente = " << xn << endl;
            } else {        // Si la raíz da aproximada
                cout << "\n\n\nLa raiz es aproximadamente = " << xn << endl;

            }
        }
      return 0;
}
//Función que captura cualquier dato de forma segura
template <typename T>
void CapturaDato (const char *mensage , T &num)
{
    while(true){
        std::cout << mensage;
        std::cin >> num;

        if(std::cin.bad()) throw "Ha ocurrido un error fatal en el flujo de entrada, el programa ha terminado";

        if(std::cin.fail()){
            std::cout << "\n\nError: el tipo de dato proporcionado no corresponde con el tipo de dato solicitado" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        return;
    }
}
//Función que calcula la función que necesitas para reutilizar codigo
float Funcion (float x)
{
    return (2*cos(3*x)-0.02*x+10);
}