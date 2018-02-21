#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

template <typename T>
void CapturaNum (const char *message, T &num);

int main(){
      long double an,bn,xn,fa,fb,fx,k ;
      double funcion,epsilon;
      bool faNegativo,fbNegativo;
      //char metodoParo,continuar;
      int metodoParo,continuar;

      cout << "Programa de bisección"<<endl;
      // Funcion 5sen(x) + 0.02x
      do{
          //cout<<"Que metodo de paro desea utilizar? (Núm iteraciones=1 , Error truncamiento =2): ";
          //cin >> metodoParo;
          CapturaNum("Que metodo de paro desea utilizar? (Núm iteraciones=1 , Error truncamiento =2): ",metodoParo);
      }while(metodoParo != 1 &&  metodoParo != 2);

      //do{
          cout<<"Ingresar intervalo"<<endl;
          CapturaNum("A0 = ",an);

          CapturaNum("B0 = ",bn);

          fa = an + sin(an)-(1/an);//5*sin(an)+ 0.02*(an)/*sin(an);*/;

          fb = bn + sin(bn)-(1/bn);//5*sin(bn)+ 0.02*(bn);/*sin(an);*/


            if(fa * fb > 0){
              cout<<"En el intervalo ["<< an<<" , "<<bn<<"] no hay raiz"<<endl;
              return 0;
            }
            //do{
            //CapturaNum("Desea continuar? (No=0,Si=1): ",metodoParo);

          //}while(continuar != 1 && continuar !=2);

          if(metodoParo ==1){
            CapturaNum("Ingrese el núm de iteraciones por favor: ",k);
          }else{
            CapturaNum("Ingrese el epsilon que desea: ",epsilon);
            k= (log((bn-an)/epsilon))/(log(2));
          }

          if(fa>0){
            faNegativo=false;
            fbNegativo=true;
          }

          for(int i = 0 ; i <= k ; ++i){
              xn=(an+bn)/2;
              fx= xn + sin(xn)-(1/xn);//5*sin(xn)+ 0.02*(xn)/*sin(xn);*/;
              if(fx==0){
                //cout<<"La raiz es exactamente = "<< xn;
                break;
              }else if (fx < 0 && faNegativo){
                an = xn;
              }else if(fx < 0 && fbNegativo){
                bn=xn;
              }else if(fx > 0 && !faNegativo){
                an=xn;
              }else if(fx > 0 && !fbNegativo){
                bn=xn;
              }
          }

          if(fx==0){
            cout<<"La raiz es exactamente = "<< xn<<endl;
          }
          else{
          cout<< "La raiz es aproximadamente = "<<(double)xn << endl;
        }
        //}while(continuar == 's');
      //system("pause");
      return 0;
}

template <typename T>
void CapturaNum (const char *mensage , T &num)
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
