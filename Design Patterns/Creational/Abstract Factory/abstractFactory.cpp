#include <iostream>
#include <memory>

// AbstractProductA
class AbstractProductA
{
public:
    virtual void operationA() const = 0;
};

// AbstractProductB
class AbstractProductB
{
public:
    virtual void operationB() const = 0;
};

// ConcreteProductA1
class ConcreteProductA1 : public AbstractProductA
{
public:
    void operationA() const override
    {
        std::cout << "ConcreteProductA1: Operation A\n";
    }
};

// ConcreteProductB1
class ConcreteProductB1 : public AbstractProductB
{
public:
    void operationB() const override
    {
        std::cout << "ConcreteProductB1: Operation B\n";
    }
};

// AbstractFactory
class AbstractFactory
{
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() = 0;
};

// ConcreteFactory1
class ConcreteFactory1 : public AbstractFactory
{
public:
    std::unique_ptr<AbstractProductA> createProductA() override
    {
        return std::make_unique<ConcreteProductA1>();
    }

    std::unique_ptr<AbstractProductB> createProductB() override
    {
        return std::make_unique<ConcreteProductB1>();
    }
};
