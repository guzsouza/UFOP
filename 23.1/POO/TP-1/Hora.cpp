#include "Hora.h"

Hora::Hora(
    const int horas, const int minutos
): horas(horas), minutos(minutos) {}

void Hora::setHoras(int horas) {
    this->horas = horas;
}
int Hora::getHoras() const {
    return horas;
}

void Hora::setMinutos(int minutos) {
    this->minutos = minutos;
}
int Hora::getMinutos() const {
    return minutos;
}