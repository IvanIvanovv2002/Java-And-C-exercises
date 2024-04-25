#include <iostream>
#include <math.h> 
using namespace std;
#define PI 3.14

int main() {
    double R, L, H;

   
    cout << "radius: ";
    cin >> R;

    cout << endl;
  
    cout << "length: ";
    cin >> L;

    cout << endl;
  
    cout << "height: ";
    cin >> H;

    double volumStanding = PI * pow(R, 2) * H;

    double angle = acos((L - H) / R);
    double volumeLaying = (PI * pow(R, 2) * L) - (pow(R, 2) * (angle - sin(angle)) * (L - H));

    cout << endl;
  
    cout << "volume standing: " << volumStanding << endl;
    cout << "volume laying: " << volumeLaying << endl;

    return 0;
}
