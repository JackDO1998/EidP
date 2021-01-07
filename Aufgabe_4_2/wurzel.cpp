#include <iostream>
#include <iomanip>      // setprecision
#include <cmath>        //für sqrt
using namespace std;


double wurzel(double a,int j) {
    double x=((a+1)/2);
    double y=1;
    int i=0;
    while (i<j)
    {
        
    
        if (y!=x){
            x=y;
            y=(x+(a/x))/2;
            
            i++;
            cout << setprecision(17) << "x=" << y << ", i=" << i << endl;

        }
        else
        {
            return x;
        }
    }
}


int main() {
double n;
int k;

cout << "Wert eingeben!" << endl;
cin >> n;
cout << "Maximale zahl der Durchläufe eingeben!" << endl;
cin >> k;
double z=wurzel(n,k);
cout << "Der durch sqrt berechnete Wert ist:" << setprecision(17) << sqrt(n) << endl;
cout << "Der durch wurzel(a) berechnete Wert ist:" << setprecision(17) << z << endl;
cout << "die Differenz der beiden Werte ist:" << setprecision(17) << (sqrt(n)-z) << endl;






return 0;
}

