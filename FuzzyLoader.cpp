#include "FuzzyLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<FuzzyVariable> FuzzyLoader::cargarDesdeArchivo(const std::string &nombreArchivo)
{
    std::ifstream archivo(nombreArchivo);
    std::vector<FuzzyVariable> variables;

    if (!archivo.is_open())
    {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return variables;
    }

    std::string linea;
    FuzzyVariable *variableActual = nullptr;

    while (std::getline(archivo, linea))
    {
        if (linea.empty() || linea[0] == '#')
            continue;

        std::istringstream iss(linea);
        std::string token;
        iss >> token;

        if (isalpha(token[0]))
        { // Línea de nombre de variable o conjunto
            if (!iss.eof())
            {
                // Podría ser una nueva variable
                std::string nombreVar = token;
                float inicio, fin;
                if (iss >> inicio >> fin)
                {
                    variableActual = new FuzzyVariable(nombreVar, inicio, fin);
                    variables.push_back(*variableActual);
                }
                continue;
            }
        }

        // Si no es variable, es un conjunto
        if (variableActual != nullptr)
        {
            std::string nombreConjunto = token;
            std::string tipoStr;
            iss >> tipoStr;

            TipoFuncion tipo = tipoStr == "TRIANGULAR" ? TipoFuncion::TRIANGULAR : TipoFuncion::TRAPEZOIDAL;

            std::vector<float> puntos;
            float p;
            while (iss >> p)
            {
                puntos.push_back(p);
            }

            FuzzySet conjunto(nombreConjunto, tipo, puntos);
            variableActual->agregarConjunto(conjunto);
        }
    }

    archivo.close();
    return variables;
}
