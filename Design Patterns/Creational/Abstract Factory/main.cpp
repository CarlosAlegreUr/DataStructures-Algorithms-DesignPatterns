// main.cpp
#include "example.cpp"
#include <iostream>
#include <memory>

int main()
{
    // Create GUI factories
    std::unique_ptr<GUIFactory> windowsFactory = std::make_unique<WindowsGUIFactory>();
    std::unique_ptr<GUIFactory> linuxFactory = std::make_unique<LinuxGUIFactory>();

    int option;
    do
    {
        std::cout << "Choose an option:\n"
                  << "1. Display Windows Button\n"
                  << "2. Display Windows Checkbox\n"
                  << "3. Display Linux Button\n"
                  << "4. Display Linux Checkbox\n"
                  << "5. Exit\n";

        std::cin >> option;

        switch (option)
        {
        case 1:
        {
            std::unique_ptr<AbstractButton> windowsButton(windowsFactory->CreateButton());
            std::cout << "Windows Button: " << windowsButton->GetLook() << std::endl;
            break;
        }
        case 2:
        {
            std::unique_ptr<AbstractCheckbox> windowsCheckbox(windowsFactory->CreateCheckbox());
            std::cout << "Windows Checkbox: " << windowsCheckbox->GetLook() << std::endl;
            break;
        }
        case 3:
        {
            std::unique_ptr<AbstractButton> linuxButton(linuxFactory->CreateButton());
            std::cout << "Linux Button: " << linuxButton->GetLook() << std::endl;
            break;
        }
        case 4:
        {
            std::unique_ptr<AbstractCheckbox> linuxCheckbox(linuxFactory->CreateCheckbox());
            std::cout << "Linux Checkbox: " << linuxCheckbox->GetLook() << std::endl;
            break;
        }
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid option. Try again.\n";
        }

    } while (option != 5);

    return 0;
}
