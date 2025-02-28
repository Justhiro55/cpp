#include "Serialization.hpp"

Serialization::Serialization() {}

Serialization::Serialization(const Serialization &src) {
    (void)src;
}

Serialization &Serialization::operator=(const Serialization &obj) {
    (void)obj;
    return *this;
}

Serialization::~Serialization() {}

uintptr_t Serialization::serialize(Data *ptr) {
    if (!ptr) {
        std::cerr << "Error: Null pointer" << std::endl;
        return 0;
    }
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialization::deserialize(uintptr_t raw) {
    if (!raw) {
        std::cerr << "Error: Null pointer" << std::endl;
        return NULL;
    }
    return reinterpret_cast<Data *>(raw);
}
