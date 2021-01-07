#include <iostream>
#include <cmath>
using namespace std;

long long rekEidp(unsigned int n, unsigned int* pointer){
    long long rueckgabe=0;
    if (n==1 || n==2){
        rueckgabe=1;
        return rueckgabe;
    }
    else{
        rueckgabe=rekEidp((n-1),pointer) + (3 * rekEidp((n-2),pointer)); 
        *pointer=*pointer +1;
        return rueckgabe;
    }

} 

long long itEidp (unsigned int n, unsigned int* pointer){
    unsigned int j=3;
    long long rueckgabe[n];
    rueckgabe[0]=0;
    rueckgabe[1]=1;
    rueckgabe[2]=1;
    long long ausgabe=0;

    if(n==1 || n==2){
        rueckgabe[n]=1;
    }
    else{
    while (j<=n){
        
        rueckgabe[j]=rueckgabe[(j-1)] + (3*rueckgabe[(j-2)]);
        j++;
        *pointer=*pointer +2;
        
        
    }
    }
    ausgabe=rueckgabe[n];
    return ausgabe;

}

long long moivreBinetEidP(unsigned int n){
    long long a =0;
    long long b =0;
    long long c =0;
    
    return (1/sqrt(13))*(pow(((1+sqrt(13))/2),n)-pow(((1-sqrt(13))/2),n));
    
}

int main(){

unsigned int k=0;
unsigned int count=0;
long long r=0;
long long s=0;
long long t=0;


cout << "Zahl eingeben:";
cin >> k;

r=rekEidp(k,&count);
cout << "Das rekursiv berechnete Folgenglied Nr."<< k << " ist " << r << " es wurde " << count <<" mal addiert" <<endl;
count =0;
s=itEidp(k,&count);
cout << "Das iterativ berechnete Folgenglied Nr."<< k << " ist " << s << " es wurde " << count <<" mal addiert" << endl;
count=0;
t=moivreBinetEidP(k);
cout << "Das durch Moivere-Binet berechnete Folgenglied Nr."<< k << " ist " << t << endl;

return 0;
}