#include "FuzzySet.h"
#include <sstream>
#include <iomanip>

FuzzySet::FuzzySet(const std::string &nombre, TipoFuncion tipo, const std::vector<float> &puntos)
    : nombre(nombre), tipo(tipo), puntos(puntos), pertenencia(0.0f) {}

float FuzzySet::calcularPertenencia(float x)
{
    float mu = 0.0f;

    if (tipo == TipoFuncion::TRIANGULAR && puntos.size() == 3)
    {
        float a = puntos[0], b = puntos[1], c = puntos[2];
        if (x <= a || x >= c)
            mu = 0.0f;
        else if (x == b)
            mu = 1.0f;
        else if (x < b)
            mu = (x - a) / (b - a);
        else
            mu = (c - x) / (c - b);
    }

    else if (tipo == TipoFuncion::TRAPEZOIDAL && puntos.size() == 4)
    {
        float a = puntos[0], b = puntos[1], c = puntos[2], d = puntos[3];
        if (x <= a || x >= d)
            mu = 0.0f;
        else if (x >= b && x <= c)
            mu = 1.0f;
        else if (x > a && x < b)
            mu = (x - a) / (b - a);
        else // x > c && x < d
            mu = (d - x) / (d - c);
    }

    pertenencia = mu;
    return mu;
}

std::string FuzzySet::getNombre() const
{
    return nombre;
}

float FuzzySet::getPertenencia() const
{
    return pertenencia;
}

void FuzzySet::setPertenencia(float valor)
{
    pertenencia = valor;
}

std::string FuzzySet::toString() const
{
    std::ostringstream oss;
    oss << "Conjunto: " << nombre
        << " | Tipo: " << (tipo == TipoFuncion::TRIANGULAR ? "Triangular" : "Trapezoidal")
        << " | Puntos: ";
    for (float p : puntos)
        oss << std::fixed << std::setprecision(2) << p << " ";
    oss << "| µ = " << std::fixed << std::setprecision(2) << pertenencia;
    return oss.str();
}
