
#include <iostream>
using namespace std;

class Queue {
	const int DEFAULT_CAPACITY = 6;
private:
	int* array;
	int top;
	int bottom;
	int capacity;
public:
	Queue() {
		this->capacity = DEFAULT_CAPACITY;
		this->array = new int[capacity];
		this->top = -1;
		this->bottom = -1;
	}
	~Queue() {
		delete[] array;
	}
	void poll(int value) {
		if (bottom == capacity - 1) {
			capacity *= 2;
			int* copyArray = new int[capacity];
			for (int i = 0; i <= bottom; i++) {
				copyArray[i] = array[i];
			}
			delete[] array;
			array = copyArray;
		}
		bottom++;
		array[bottom] = value;
	}

	int remove() {
		if (!isEmpty()) {
			return array[++top];
		}
		return 0;
	}

	bool isEmpty() {
		return top == bottom;
	}
};

int main()
{
	Queue* queue = new Queue();
	
	for (size_t i = 0; i < 15; i++)
	{
		queue->poll(i);
	}
	while (!queue->isEmpty()) { cout << queue->remove() << " "; }

}



