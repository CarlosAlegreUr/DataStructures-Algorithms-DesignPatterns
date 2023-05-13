#include <iostream>
#include "example.h"

void Truck::deliver()
{
    this->calculateRoute();
    std::cout << "Delivered by Truck! (Legislation for trucks here)" << std::endl;
    std::cout << "Route is: " << this->route << std::endl;
}

void Airplane::deliver()
{
    this->calculateRoute();
    std::cout << "Delivered by Airplane! (Legislation for airplanes here)" << std::endl;
    std::cout << "Route is: " << this->route << std::endl;
}

void Ship::deliver()
{
    this->calculateRoute();
    std::cout << "Delivered by Ship! (Legislation for ships here)" << std::endl;
    std::cout << "Route is: " << this->route << std::endl;
}

void Train::deliver()
{
    this->calculateRoute();
    std::cout << "Delivered by Train! (Legislation for trains here)" << std::endl;
    std::cout << "Route is: " << this->route << std::endl;
}

void Truck::calculateRoute()
{
    this->route = "Route made for Trucks.";
}

void Ship::calculateRoute()
{
    this->route = "Route made for Ship.";
}

void Airplane::calculateRoute()
{
    this->route = "Route made for Airplane.";
}

void Train::calculateRoute()
{
    this->route = "Route made for Train.";
}

void Logistics::planDelivery()
{
    Transport *transport = createTransport();
    transport->deliver();
    delete transport;
}

Transport *RoadLogistics::createTransport()
{
    return new Truck();
}

Transport *SeaLogistics::createTransport()
{
    return new Ship();
}

Transport *AirLogistics::createTransport()
{
    return new Airplane();
}

Transport *RailLogistics::createTransport()
{
    return new Train();
}
