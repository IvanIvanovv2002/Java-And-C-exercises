
#include <iostream>
using namespace std;

//finding GCD for 3 values.

int greatComDiv_2(int a, int b) {
    int currentNum;
    while (b != 0) {
        currentNum = a % b;
        a = b;
        b = currentNum;
    }
    return a;
}

int greatComDiv_3(int a,int b,int c) {
   int greatCom2 = greatComDiv_2(a, b);
   return greatComDiv_2(greatCom2, c);
}
int main()
{
    cout << greatComDiv_3(20, 2, 10);
}
