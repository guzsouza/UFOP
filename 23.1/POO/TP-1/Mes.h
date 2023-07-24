#ifndef MES_H
#define MES_H

#include <iostream>
#include <vector>

#include "Dia.h"

using namespace std;

class Mes{
    private:
        vector<Dia*> mesDoAno;

    protected:
        Mes(vector<Dia*> = vector<Dia*>());

        void setMesDoAno(vector<Dia*>);
        vector<Dia*> getMesDoAno() const;
};

#endif