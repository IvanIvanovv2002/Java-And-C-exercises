
#include <iostream>
using namespace std;

class Stack {
    static const int DEFAULT_CAPACITY = 6;
private:
    int* array;
    int top;
    int capacity;
public:
    Stack() {
        this->capacity = DEFAULT_CAPACITY;
        this->array = new int[capacity];
        this->top = -1;
    }
    ~Stack() {
        delete[] array;
    }
    void push(int value) {
        if (top == capacity - 1) {
            capacity *= 2;
            int* copyArray = new int[capacity];
            for (size_t i = 0; i <= top; ++i) {
                copyArray[i] = array[i];
            }
            delete[] array;
            array = copyArray;
        }
        top++;
        array[top] = value;
    }
    int pop() {
        while (!isEmpty()) {
            int currentNum = array[top];
            top--;
            if (top < capacity / 2 && capacity > DEFAULT_CAPACITY) {
                capacity /= 2;
                int* copyArray = new int[capacity];
                for (int i = 0; i <= top; ++i) {
                    copyArray[i] = array[i];
                }
                delete[] array;
                array = copyArray;
            }
            return currentNum;
        }
        return -999;
    }
    bool isEmpty() {
        return top == -1;
    }
};

int main()
{
    Stack* stack = new Stack();
    stack->push(8);
    stack->push(12);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->push(7);
    stack->push(12);
    while (!stack->isEmpty()) {
        cout << stack->pop() << " ";
    }
}
