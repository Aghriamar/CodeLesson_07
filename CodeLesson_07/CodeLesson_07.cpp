#include <iostream>
#include <vector>

template<typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(const T& value) {
        elements.push_back(value);
    }

    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T value = elements.back();
        elements.pop_back();
        return value;
    }

    bool isEmpty() const {
        return elements.empty();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    while (!intStack.isEmpty()) {
        std::cout << intStack.pop() << std::endl;
    }

    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");

    while (!stringStack.isEmpty()) {
        std::cout << stringStack.pop() << std::endl;
    }

    return 0;
}