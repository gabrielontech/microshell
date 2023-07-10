#include "../includes/Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

void Serializer::printDeserializedData(uintptr_t raw) {
    Data* deserialized = deserialize(raw);
    if (deserialized != nullptr) {
        std::cout << "Deserialized Data: " << deserialized->value << ", "
                  << deserialized->floatValue << ", " << deserialized->stringValue << std::endl;
    } else {
        std::cout << "Deserialization failed!" << std::endl;
    }
}