# Adapter Design Pattern

The Adapter pattern is a structural design pattern that allows objects with incompatible interfaces to collaborate. It's often used when you want to make your own classes work with others without modifying their source code.

## Structure

The Adapter pattern involves a single class, the 'Adapter', which is responsible for communication between the existing ('Adaptee') and the new ('Target') systems.

1. **Target**: This is the domain-specific interface that Client is expected to work with.
2. **Adapter**: This adapts the interface Adaptee to the Target interface.
3. **Adaptee**: This is the existing interface that needs adapting.
4. **Client**: This collaborates with objects conforming to the Target interface.

## When to use

Use the Adapter pattern when you want to use some existing class, but its interface isn’t compatible with the rest of your code. The Adapter pattern lets you create a middle-layer class that serves as a translator between your code and a legacy class, a 3rd-party class or any other class with a weird interface.

## Example

An example can be a card reader acting as an adapter between a memory card and a laptop. The laptop's USB interface is not compatible with the memory card's interface. Therefore, the card reader adapts the memory card's interface to the laptop's interface.
