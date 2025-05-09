#include <iostream>
#include "FuzzyLoader.h"

int main()
{
    std::string archivo = "variables.txt";
    auto variables = FuzzyLoader::cargarDesdeArchivo(archivo);

    if (variables.empty())
    {
        std::cout << "No se cargaron variables.\n";
        return 1;
    }

    // Mostrar todas las variables
    for (const auto &var : variables)
    {
        std::cout << "\n--- Variable: " << var.getNombre() << " ---\n";
        var.imprimir();
    }

    // Fuzzificar un valor para una variable específica (ej: velocidad = 70)
    for (auto &var : variables)
    {
        if (var.getNombre() == "Velocidad")
        {
            std::cout << "\n--- Fuzzificación de Velocidad = 70 ---\n";
            var.fuzzificar(70.0f);
        }
    }

    return 0;
}
