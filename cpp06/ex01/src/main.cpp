#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include <iostream>

int main() {
    Data data = {42, 3.14f, "Hello, World!"};

    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);

    if (deserialized != nullptr && memcmp(deserialized, &data, sizeof(Data)) == 0) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}