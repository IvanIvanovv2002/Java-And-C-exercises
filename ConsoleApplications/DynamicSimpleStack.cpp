
#include <iostream>
using namespace std;

struct element {
    int data;
    element* next;
};
element* top;

void pop(int &x) {
    element* p;
    x = top->data;
    p = top;
    top = top->next;
    delete(p);
}

void push(int value) {
    element* p;
    p = new element();
    p->data = value;
    p->next = top;
    top = p;
}
int main()
{
    int num;
    cin >> num;
    while (num != 0) {
        push(num);
        cin >> num;
    }
    while (top != NULL) {
        pop(num);
        printf("%d ", num);
    }
}
