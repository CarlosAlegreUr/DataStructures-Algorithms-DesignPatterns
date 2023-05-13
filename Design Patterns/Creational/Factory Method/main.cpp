#include <iostream>
#include "example.h"

int main()
{
    Logistics *logistics = nullptr;
    std::string decision;

    while (true)
    {
        std::cout << "Enter type of logistics (road/sea/air/rail or exit): ";
        std::cin >> decision;

        if (decision == "exit")
        {
            break;
        }
        else if (decision == "road")
        {
            logistics = new RoadLogistics();
        }
        else if (decision == "sea")
        {
            logistics = new SeaLogistics();
        }
        else if (decision == "air")
        {
            logistics = new AirLogistics();
        }
        else if (decision == "rail")
        {
            logistics = new RailLogistics();
        }
        else
        {
            std::cout << "Unknown type. Try again.\n";
            continue;
        }

        logistics->planDelivery();
        delete logistics;
    }

    return 0;
}
