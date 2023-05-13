#include <iostream>
#include <string>

// Abstract Products
class AbstractButton {
public:
    virtual ~AbstractButton() = default;
    virtual std::string GetLook() const = 0;
};

class AbstractCheckbox {
public:
    virtual ~AbstractCheckbox() = default;
    virtual std::string GetLook() const = 0;
};

// Concrete Products
class WindowsButton : public AbstractButton {
public:
    std::string GetLook() const override {
        return "Windows Button [XD button]";
    }
};

class WindowsCheckbox : public AbstractCheckbox {
public:
    std::string GetLook() const override {
        return "Windows Checkbox [x]";
    }
};

class LinuxButton : public AbstractButton {
public:
    std::string GetLook() const override {
        return "Linux Button [X button]";
    }
};

class LinuxCheckbox : public AbstractCheckbox {
public:
    std::string GetLook() const override {
        return "Linux Checkbox [x]";
    }
};

// Abstract Creator
class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual AbstractButton* CreateButton() = 0;
    virtual AbstractCheckbox* CreateCheckbox() = 0;
};

// Concrete Creators
class WindowsGUIFactory : public GUIFactory {
public:
    AbstractButton* CreateButton() override {
        return new WindowsButton;
    }

    AbstractCheckbox* CreateCheckbox() override {
        return new WindowsCheckbox;
    }
};

class LinuxGUIFactory : public GUIFactory {
public:
    AbstractButton* CreateButton() override {
        return new LinuxButton;
    }

    AbstractCheckbox* CreateCheckbox() override {
        return new LinuxCheckbox;
    }
};
