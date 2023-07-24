#include "Dia.h"

Dia::Dia(
    const vector<Hora*> diaDoMes
): diaDoMes(diaDoMes) {}

void Dia::setDiaDoMes(vector<Hora*> diaDoMes) {
    this->diaDoMes = diaDoMes;
}
vector<Hora*> Dia::getDiaDoMes() const {
    return diaDoMes;
}