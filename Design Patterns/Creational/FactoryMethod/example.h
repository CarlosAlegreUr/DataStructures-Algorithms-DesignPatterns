#include <string>

// Products class (polymorphic base class)
class Transport
{
public:
    virtual void deliver() = 0;

protected:
    virtual void calculateRoute() = 0;
    std::string route;
};

// Concrete products (subclasses inheriting from the polymorphic base class)
class Truck : public Transport
{
public:
    void deliver() override;

private:
    void calculateRoute() override;
};

class Ship : public Transport
{
public:
    void deliver() override;

private:
    void calculateRoute() override;
};

class Airplane : public Transport
{
public:
    void deliver() override;

private:
    void calculateRoute() override;
};

class Train : public Transport
{
public:
    void deliver() override;

private:
    void calculateRoute() override;
};

// Creator or Factory
class Logistics
{
public:
    virtual Transport *createTransport() = 0;
    void planDelivery();
};

// Different Factory Implementations
class RoadLogistics : public Logistics
{
public:
    Transport *createTransport() override;
};

class SeaLogistics : public Logistics
{
public:
    Transport *createTransport() override;
};

class AirLogistics : public Logistics
{
public:
    Transport *createTransport() override;
};

class RailLogistics : public Logistics
{
public:
    Transport *createTransport() override;
};
