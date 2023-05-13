# Abstract Factory Design Pattern

The Abstract Factory is a creational design pattern that provides an interface for creating families of related or dependent objects without specifying their concrete classes.

## Structure

The Abstract Factory pattern involves a super-factory (the 'Abstract Factory') which creates other factories. This pattern includes the following components:

1. **AbstractFactory**: This is an interface for creating abstract products.
2. **ConcreteFactory**: This is a class which implements the AbstractFactory interface to create concrete products.
3. **AbstractProduct**: This is an interface for a type of product objects.
4. **ConcreteProduct**: This is a class which implements 
the AbstractProduct interface.

## When to use

Use the Abstract Factory when your code needs to work with various families of related products, but you don’t want it to depend on the concrete classes of those products—they might be unknown beforehand or you simply want to allow for future extensibility.

## Example

An example can be a GUI library that allows application to work with different OS. The library's code shouldn't be tied to a specific OS. To achieve this, the library's classes should work with GUI elements through abstract interfaces. The library should provide different sets of UI elements that match those in Windows, Linux, and MacOS. The application's code should instantiate a factory object for each OS. The rest of the client code just needs to work with these factories and UI elements through their generic interfaces.
