#ifndef FUZZYSET_H
#define FUZZYSET_H

#include <string>
#include <vector>

enum class TipoFuncion
{
    TRIANGULAR,
    TRAPEZOIDAL
};

class FuzzySet
{
private:
    std::string nombre;
    TipoFuncion tipo;
    std::vector<float> puntos; // 3 para TRIANGULAR, 4 para TRAPEZOIDAL
    float pertenencia;         // valor calculado en fuzzificación

public:
    // Constructor
    FuzzySet(const std::string &nombre, TipoFuncion tipo, const std::vector<float> &puntos);

    // Calcula el grado de pertenencia de un valor x al conjunto
    float calcularPertenencia(float x);

    // Devuelve el nombre del conjunto
    std::string getNombre() const;

    // Devuelve el grado de pertenencia actual
    float getPertenencia() const;

    // Asigna y almacena el grado de pertenencia
    void setPertenencia(float valor);

    // Muestra info como string
    std::string toString() const;
};

#endif // FUZZYSET_H
