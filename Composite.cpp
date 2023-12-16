#include <iostream>
#include <string>

using namespace std;

class Component {
public:
    virtual void display() const = 0;
};

class Product : public Component {
    string name;
public:
    Product(const string& name) : name(name) {}

    void display() const override {
        cout << "Product: " << name << endl;
    }

};

class Box : public Component {
    Component* components[10];
    int count = 0;
public:
    void add(Component* component) {
        components[count++] = component;
    }

    void display() const override {
        cout << "Box:" << endl;
        for (int i = 0; i < count; ++i) {
            components[i]->display();
        }
    }
};

int main() {
    Product apple("Apple");
    Product banana("Banana");

    Box fruitBox;
    fruitBox.add(&apple);
    fruitBox.add(&banana);

    Product orange("Orange");

    Box biggerBox;
    biggerBox.add(&fruitBox);
    biggerBox.add(&orange);

    biggerBox.display();

    return 0;
}