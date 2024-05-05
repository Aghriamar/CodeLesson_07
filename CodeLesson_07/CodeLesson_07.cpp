#include <iostream>

class Stack {
private:
    int* data; 
    int size;  
    int capacity; 

public:
    Stack(int initialCapacity = 10) {
        data = new int[initialCapacity]; 
        size = 0; 
        capacity = initialCapacity;
    }

    ~Stack() {
        delete[] data; 
    }

    void push(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* newData = new int[capacity]; 
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i]; 
            }
            delete[] data; 
            data = newData; 
        }
        data[size++] = value; 
    }

    
    int pop() {
        if (size == 0) {
            std::cerr << "Error: Stack is empty!" << std::endl;
            return -1; 
        }
        return data[--size]; 
    }
};

int main() {
    Stack stack; 

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;

    return 0;
}