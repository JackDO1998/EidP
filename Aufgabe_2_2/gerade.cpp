/*
 * gerade.cpp
 * Das Programm berechnt die Geradenparameter~$m, b$ fuer die Geradengleichung
 * f(x) = mx + b 
 * Als Eingabe dienen die Punkte (x1, y1), (x2, y2)
 */

#include <iostream>
using namespace std;

int main() {
  double x1, y1, x2, y2, m, b, x3, y3 ;
  y3=4;
  x3=3;

  std :: cout << "X1 Eingeben";
  std :: cin >> x1;
  std :: cout << "Y1 Eingeben";
  std :: cin >> y1;
  std :: cout << "X2 Eingeben";
  std :: cin >> x2;
  std :: cout << "Y2 Eingeben";
  std :: cin >> y2;
  std :: cout << "X3 Eingeben";
  std :: cin >> x3;
  std :: cout << "Y3 Eingeben";
  std :: cin >> y3;
m=(y1-y2)/(x1-x2);
b=y1-(m*x1);
std :: cout << "Die Geradengleichung lautet: y=" << m <<"x+" << b << endl;
if (y3==m*x3+b){
std :: cout << "Der Punkt" <<x3<<","<<y3<<"liegt auf der Geraden";
}
else{
std :: cout << "Der Punkt ( " <<x3<<","<<y3<<" ) liegt nicht auf der Geraden";
}
return(0);
}