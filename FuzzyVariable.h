#ifndef FUZZYVARIABLE_H
#define FUZZYVARIABLE_H

#include <string>
#include <vector>
#include "FuzzySet.h"

class FuzzyVariable
{
private:
    std::string nombre;
    float universoInicio;
    float universoFin;
    std::vector<FuzzySet> conjuntos;

public:
    // Constructor
    FuzzyVariable(const std::string &nombre, float inicio, float fin);

    // Agregar conjunto difuso
    void agregarConjunto(const FuzzySet &conjunto);

    // Aplicar fuzzificación a un valor real
    void fuzzificar(float valor);

    // Imprimir estado actual
    void imprimir() const;

    // Getters
    std::string getNombre() const;
    float getUniversoInicio() const;
    float getUniversoFin() const;
    const std::vector<FuzzySet> &getConjuntos() const;
};

#endif // FUZZYVARIABLE_H
