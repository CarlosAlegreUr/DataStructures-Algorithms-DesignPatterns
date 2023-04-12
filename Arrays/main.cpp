#include "dynamicArray.h"
#include "testDynamicArray.h"
#include <iostream>
#include <string>

void displayOptions()
{
    std::cout << "Options:\n";
    std::cout << "1. Push back\n";
    std::cout << "2. Pop back\n";
    std::cout << "3. Insert at\n";
    std::cout << "4. Delete at\n";
    std::cout << "5. Quit\n";
}

int main()
{
    testDynamicArray();

    DynamicArray<int> intArray;
    DynamicArray<std::string> stringArray;
    bool useIntArray = true;

    std::cout << "Choose array type:\n";
    std::cout << "1. Integer array\n";
    std::cout << "2. String array\n";
    int choice;
    std::cin >> choice;

    if (choice == 2)
    {
        useIntArray = false;
    }

    displayOptions();

    while (true)
    {
        std::cout << "\nChoose an option: ";
        std::cin >> choice;

        if (choice == 5)
        {
            break;
        }

        if (useIntArray)
        {
            std::cout << "Current array: ";
            for (int i = 0; i < intArray.getSize(); i++)
            {
                std::cout << intArray[i] << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Current array: ";
            for (int i = 0; i < stringArray.getSize(); i++)
            {
                std::cout << stringArray[i] << " ";
            }
            std::cout << std::endl;
        }

        switch (choice)
        {
        case 1:
        {
            if (useIntArray)
            {
                std::cout << "Enter the integer to push back: ";
                int value;
                std::cin >> value;
                intArray.push_back(value);
            }
            else
            {
                std::cout << "Enter the string to push back: ";
                std::string value;
                std::cin >> value;
                stringArray.push_back(value);
            }
            break;
        }
        case 2:
        {
            if (useIntArray)
            {
                if (intArray.getSize() > 0)
                {
                    intArray.pop_back();
                }
                else
                {
                    std::cout << "Array is empty!" << std::endl;
                }
            }
            else
            {
                if (stringArray.getSize() > 0)
                {
                    stringArray.pop_back();
                }
                else
                {
                    std::cout << "Array is empty!" << std::endl;
                }
            }
            break;
        }
        case 3:
        {
            std::cout << "Enter the index to insert at: ";
            int index;
            std::cin >> index;

            if (useIntArray)
            {
                std::cout << "Enter the integer to insert: ";
                int value;
                std::cin >> value;
                try
                {
                    intArray.insertAt(index, value);
                }
                catch (std::out_of_range &)
                {
                    std::cout << "Invalid index!" << std::endl;
                }
            }
            else
            {
                std::cout << "Enter the string to insert: ";
                std::string value;
                std::cin >> value;
                try
                {
                    stringArray.insertAt(index, value);
                }
                catch (std::out_of_range &)
                {
                    std::cout << "Invalid index!" << std::endl;
                }
            }
            break;
        }
        case 4:
        {
            std::cout << "Enter the index to delete at: ";
            int index;
            std::cin >> index;

            if (useIntArray)
            {
                try
                {
                    intArray.deleteAt(index);
                }
                catch (std::out_of_range &)
                {
                    std::cout << "Invalid index!" << std::endl;
                }
            }
            else
            {
                try
                {
                    stringArray.deleteAt(index);
                }
                catch (std::out_of_range &)
                {
                    std::cout << "Invalid index!" << std::endl;
                }
            }
            break;
        }
        default:
        {
            std::cout << "Invalid option!" << std::endl;
            break;
        }
        }
    }

    return 0;
}
