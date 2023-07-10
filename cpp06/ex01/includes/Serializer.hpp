#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    static void printDeserializedData(uintptr_t raw);

private:
    Serializer();  // Constructeur privé pour empêcher l'instanciation de la classe
    ~Serializer(); // Destructeur privé pour empêcher la destruction de la classe
    Serializer(const Serializer& other); // Constructeur de copie privé pour empêcher la copie de la classe
    Serializer& operator=(const Serializer& other); // Opérateur d'affectation privé pour empêcher l'affectation de la classe
};

#endif  // SERIALIZER_HPP