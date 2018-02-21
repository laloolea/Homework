#include <iostream>
#include <cstdlib>
#include "Matriz.h"
#include <iomanip>

using namespace std;
template <typename T>
void CapturaNum(const char mensage[100], T &num);


int main () {

    try {
        int m1,n1,m2,n2, mn3;

        cout <<"Programa que realiza operaciones basicas de matrices"<<endl;
        //Matriz matriz (5, 5 , 3) , a (2 , 3 , 4);

        CapturaNum ("Ingrese el n\xA3mero de renglones de las  matrices: " , m1);

        CapturaNum ("Ingrese el n\xA3mero de columnas de las  matrices: ",n1);
        //CapturaNum ("Ingrese el n\xA3mero de renglones de las segunda matrices: " , m2);

        //CapturaNum ("Ingrese el n\xA3mero de columnas de las segunda matrices: ",n2);



        Matriz matriz1(m1,n1,0);

        Matriz matriz2(m1,n1,0);

        Matriz matriz3(m1,n1,0);



        cout<<"CAPTURA PRIMER MATRIZ";

        cin >> matriz1;

        cout << "CAPTURA SEGUNDA MATRIZ";

        cin >> matriz2;

        cout << matriz1(1,2) <<endl;

        cout << matriz1*matriz2;

        cout  <<"OPERACION SUMA."<<endl;

        matriz3= matriz1+matriz2;
        cout << matriz1 << "+"<<endl<< matriz2 <<"= "<<endl<<matriz3<<endl;

        cout<< "OPERACION RESTA"<<endl;
        matriz3= matriz1-matriz2;
        cout << matriz1 << "-"<<endl<< matriz2 <<"= "<<endl<<matriz3<<endl;


        cout <<"OPERACION TRANSPUESTA" <<endl;
        Matriz matriz4 = matriz1.Transpuesta ();
        cout << matriz1 << "Y su transpuesta es: "<<endl<<matriz4<<endl;





        cout <<"OPERACION PRODUCTO DE MATRICES"<<endl;



        cout << matriz1 << "*"<<endl<< matriz4 <<"= "<<endl<<matriz1*matriz4<<endl;


        cout <<"OPERACION PRODUCTO POR ESCALAR"<<endl;

        matriz3=matriz1 * 0.5;

        cout << matriz1 << "*"<<endl<< "0.5\n= "<<endl<<matriz3<<endl;


        cout <<"OPERACION PRODUCTO POR ESCALAR CONMUTATIVA"<<endl;
        matriz3 =  1.5  * matriz1;

        cout << "1.5 \n *\n" << matriz1<<"="<<endl<<matriz3<<endl;




    } catch ( bad_alloc &exc ) {
        cout << "ERROR: asignacion de memoria incorrecta " << endl;
    }catch(Excepcion &exc){
        cout << exc.QuePaso()<<endl;
    }
    system("pause");
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
