#include "FuzzyVariable.h"
#include <iostream>
#include <iomanip>

FuzzyVariable::FuzzyVariable(const std::string &nombre, float inicio, float fin)
    : nombre(nombre), universoInicio(inicio), universoFin(fin) {}

void FuzzyVariable::agregarConjunto(const FuzzySet &conjunto)
{
    conjuntos.push_back(conjunto);
}

void FuzzyVariable::fuzzificar(float valor)
{
    std::cout << "Fuzzificando valor: " << valor << " para la variable '" << nombre << "'\n";
    for (auto &conjunto : conjuntos)
    {
        float pertenencia = conjunto.calcularPertenencia(valor);
        conjunto.setPertenencia(pertenencia); // Para guardar el valor interno (por si se necesita)
        std::cout << "  - " << conjunto.getNombre() << ": µ = " << std::fixed << std::setprecision(2) << pertenencia << "\n";
    }
}

void FuzzyVariable::imprimir() const
{
    std::cout << "Variable: " << nombre << " [" << universoInicio << ", " << universoFin << "]\n";
    for (const auto &conjunto : conjuntos)
    {
        std::cout << "  " << conjunto.toString() << "\n";
    }
}

std::string FuzzyVariable::getNombre() const
{
    return nombre;
}

float FuzzyVariable::getUniversoInicio() const
{
    return universoInicio;
}

float FuzzyVariable::getUniversoFin() const
{
    return universoFin;
}

const std::vector<FuzzySet> &FuzzyVariable::getConjuntos() const
{
    return conjuntos;
}
