#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main (void)
{
	Data data_test;

	data_test.character = 'A';
	data_test.decimal = 42.42;
	data_test.value = 42;


    std::cout << "Original Data address: " << &data_test << std::endl;
    std::cout << "Original values: " << data_test.value << ", " << data_test.character << ", " << data_test.decimal << std::endl;
    
   
	//convertie l'adresse memoire en un format numerique 
    uintptr_t serialized = Serializer::serialize(&data_test);
    std::cout << "Serialized value: " << serialized << std::endl;
    
	//reconverti l'adresse numerique en pointeur 
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << std::endl;
    

    std::cout << "Deserialized values: " << deserialized->value << ", " << deserialized->character << ", " << deserialized->decimal << std::endl;
    
    return 0;
}