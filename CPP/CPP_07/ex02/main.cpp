#include "Array.hpp"

int main()
{
    try 
	{
        Array<int> emptyArray;
        std::cout << "Taille: " << emptyArray.size() << std::endl;

        Array<int> intArray(5);
        std::cout << "Taille: " << intArray.size() << std::endl;
        std::cout << std::endl;

        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = i * 10;
        std::cout << "Contenu:" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        //copie
        Array<int> copyArray(intArray);
        std::cout << "\nContenu copie:" << std::endl;
        for (unsigned int i = 0; i < copyArray.size(); i++) 
            std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;

        // Modif copie
        copyArray[0] = 999;
        std::cout << "\nApres modif:" << std::endl;
        std::cout << "intArray[0] = " << intArray[0] << std::endl;
        std::cout << "copyArray[0] = " << copyArray[0] << std::endl;// y a que copy qui change dc copie profonde 

        // Test avec un autre type
        Array<std::string> stringArray(3);
        stringArray[0] = "salut";
        stringArray[1] = "tu";
        stringArray[2] = "vas bien ?";
        
        std::cout << "\nContenu:" << std::endl;
        for (unsigned int i = 0; i < stringArray.size(); i++)
            std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;

        // Test exception
        intArray[10] = 100;
    }
    catch (const std::exception& e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}