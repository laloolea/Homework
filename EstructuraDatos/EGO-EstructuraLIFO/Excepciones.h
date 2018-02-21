//
// Created by Eduardo Gonzalez Olea on 2/11/18.
//

#ifndef OPERACIONMATRICES2_EXCEPCIONES_H
#define OPERACIONMATRICES2_EXCEPCIONES_H
#include <string>
class Excepcion {
public:

    Excepcion (std::string _msn) : msn (_msn) {}

    std::string QuePaso() const { return msn; }

private:
    std::string msn;
};

#endif //OPERACIONMATRICES2_EXCEPCIONES_H
