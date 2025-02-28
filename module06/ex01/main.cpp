#include "Serialization.hpp"

void testSuccessSerialization()
{
    Data data;
    data.playerName = "hhagiwar";
    data.score = 42;
    data.isGameCompleted = false;

    std::cout << "---Before Serialization---" << std::endl;
    uintptr_t serializedData = Serialization::serialize(&data);

    std::cout << "Player Name: " << data.playerName << std::endl;
    std::cout << "Score: " << data.score << std::endl;
    std::cout << "Is Game Completed: " << data.isGameCompleted << std::endl;
    std::cout << "Original Address: " << &data << std::endl;
    std::cout << std::endl;

    std::cout << "---After Serialization---" << std::endl;
    Data *deserializedData = Serialization::deserialize(serializedData);

    std::cout << "Player Name: " << deserializedData->playerName << std::endl;
    std::cout << "Score: " << deserializedData->score << std::endl;
    std::cout << "Is Game Completed: " << deserializedData->isGameCompleted << std::endl;
    std::cout << "Deserialized Address: " << deserializedData << std::endl;

    std::cout << std::endl;
    std::cout << "--Addresses Comparison--" << std::endl;
    if (&data == deserializedData) {
        std::cout << BLUE << "Addresses match!" << RESET << std::endl;
    } else {
        std::cout << MAGENTA << "Addresses do not match!" << RESET << std::endl;
    }
    std::cout << std::endl;
}

void testNullPointer() {
    Data* nullData = NULL;
    std::cout << "---Before Serialization---" << std::endl;

    uintptr_t serializedData = Serialization::serialize(nullData);
    if (serializedData == 0) {
        std::cout << "Null Pointer: " << serializedData << std::endl;
        std::cout << std::endl;
        return;
    } else {
        std::cout << "Serialized Data: " << serializedData << std::endl;
    }
    std::cout << std::endl;
}

int main(void)
{
    std::cout << CYAN << "=== Testing Serialization Class ===" << RESET << std::endl;
    std::cout << std::endl;
    std::cout << GREEN << "[Testing Serialization]" << RESET << std::endl;
    testSuccessSerialization();

    std::cout << std::endl;
    std::cout << GREEN << "[Testing Null Pointer]" << RESET << std::endl;
    testNullPointer();

    return 0;
}
