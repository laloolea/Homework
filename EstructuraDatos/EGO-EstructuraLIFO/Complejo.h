//
// Created by Eduardo Gonzalez Olea on 2/16/18.
//

#ifndef EGO_ESTRUCTURALIFO_COMPLEJO_H
#define EGO_ESTRUCTURALIFO_COMPLEJO_H
#include <iostream>

class Complejo {
    friend std::ostream& operator << (std::ostream& salida,const Complejo & c ){
        return salida << c.a << (c.b>= 0 ? " + " : " - ") << (c.b >= 0 ? c.b : -c.b ) <<" i ";
    }

public:
    Complejo(float _a = 0, float _b =0): a(_a),b (_b) {

    }
private:
    float a,b;//parte real, parte imaginaria
};


#endif //EGO_ESTRUCTURALIFO_COMPLEJO_H
