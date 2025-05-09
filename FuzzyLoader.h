#ifndef FUZZYLOADER_H
#define FUZZYLOADER_H

#include <vector>
#include <string>
#include "FuzzyVariable.h"

class FuzzyLoader
{
public:
    static std::vector<FuzzyVariable> cargarDesdeArchivo(const std::string &nombreArchivo);
};

#endif
