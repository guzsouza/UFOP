#ifndef DIA_H
#define DIA_H

#include <iostream>
#include <vector>

#include "Hora.h"

using namespace std;

class Dia{
    private:
        vector<Hora*> diaDoMes;

    protected:
        Dia(vector<Hora*> = vector<Hora*>());

        void setDiaDoMes(vector<Hora*>);
        vector<Hora*> getDiaDoMes() const;
};

#endif