#include "Mes.h"

Mes::Mes(
    const vector<Dia*> mesDoAno
): mesDoAno(mesDoAno) {}

void Mes::setMesDoAno(vector<Dia*> mesDoAno) {
    this->mesDoAno = mesDoAno;
}
vector<Dia*> Mes::getMesDoAno() const {
    return mesDoAno;
}