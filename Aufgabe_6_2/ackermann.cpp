#include <iostream>
#include <cmath>
using namespace std;

int ack(int n, int m){
    if (n == 0){
      return (m + 1);
    }
  else if (m == 0)
    {
      return ack((n - 1), 1);
    }
  else
    {
      return ack(n - 1, (ack(n, (m - 1))));
    }
}

int ack2(int n, int m){
    while(n!=0){
        if(m==0){
            m=1;
        }
        else{
            m= ack2(n, (m - 1));
        }
        n=n-1;

    }
    return (m+1);
}



int main(){
    int m=0;
    int n=0;
    cout << "Zahl fuer m eingeben!"<< endl;
    cin >> m;
     cout << "Zahl fuer n eingeben!"<< endl;
    cin >> n;
    cout << "Der durch die Ackermann-Funktion berechnete Wert fuer m = "<<m<<" und n = "<<n<< " ist: "<< ack(n,m) <<endl; 
    cout << "Der durch die Ackermann2-Funktion berechnete Wert fuer m = "<<m<<" und n = "<<n<< " ist: "<< ack2(n,m) <<endl;

    return 0;
}