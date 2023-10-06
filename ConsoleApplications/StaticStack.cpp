 #include <iostream>
using namespace std;

class Stack {
private:
	int* array;
	int lenght;
	int top = -1;
public:
	~Stack() {
		cout << "Stack destroyed";
	}
	Stack(int length) {
		this->lenght = length;
		this->array = new int[lenght];
	}
	void push(int number) {
		if (top == lenght - 1) { cout << "Not enough capacity !";  return;}
		top++;
		array[top] = number;
	}
	int pop() {
		int currentNumber;
		if (top < 0) { cout << "Stack is already empty !";  return 0;}
		currentNumber = array[top];
		top--;
		return currentNumber;
	}
	int peek() {
		return array[top];
	}
	bool isEmpty() {
		return top == -1;
	}

};


int main()
{
	Stack* stack = new Stack(5);
	stack->push(8);
	stack->push(2);
	stack->push(4);
	stack->push(12);
	stack->push(25);
	cout << stack->peek();
	while (!stack->isEmpty()) {
		cout << stack->pop() << " ";
	}
}