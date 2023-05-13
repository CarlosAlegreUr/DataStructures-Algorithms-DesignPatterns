#include <string>

// The Product interface declares the operations that all concrete products must implement.
class Product
{
public:
    virtual std::string Operation() const = 0;
};

// Concrete Products provide various implementations of the Product interface.
class ConcreteProduct1 : public Product
{
public:
    std::string Operation() const override
    {
        return "{Result of the ConcreteProduct1}";
    }
};

class ConcreteProduct2 : public Product
{
public:
    std::string Operation() const override
    {
        return "{Result of the ConcreteProduct2}";
    }
};

// The Creator class declares the factory method that must return an object of a Product class.
class Creator
{
public:
    virtual Product *FactoryMethod() const = 0;
    // Also note that, despite its name, the Creator's primary responsibility is not creating products.
    std::string SomeOperation() const
    {
        // Call the factory method to create a Product object.
        Product *product = this->FactoryMethod();
        // Now, use the product.
        std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};

// Concrete Creators override the factory method in order to change the resulting product's type.
class ConcreteCreator1 : public Creator
{
public:
    Product *FactoryMethod() const override
    {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator
{
public:
    Product *FactoryMethod() const override
    {
        return new ConcreteProduct2();
    }
};
