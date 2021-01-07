#include <iostream>
using namespace std;

int position(char a){
    if (isupper(a)){
        int pos =(((int)a)-65);
        return pos;
    }
    else{
        int pos =(((int)a)-97);
    return pos;
    }
}


void zaehleHoch(char buchstabe, int anzahlen[]){
anzahlen[position(buchstabe)]++;
}


void zaehleRunter(char buchstabe, int anzahlen[]){
anzahlen[position(buchstabe)]--;
}

void zaehleAlleHoch (char const w[], int l1, int anz[]){
    int m=0;
    while (m<l1)
    {
        zaehleHoch(w[m],anz);
        m++;
    }
    
}

void zaehleAlleRunter (char const w[], int l2, int anz[]){
    int o=0;
    while (o<l2)
    {
        zaehleRunter(w[o],anz);
        o++;
    }
}

bool sindAlleNull (int anzahlen[], int laenge){
    int p=0;
    int s=0;
    while (p<laenge)
    {
        s=anzahlen[p]+s;
        p++;
    }
    if (s==0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
    
}

int main() {
    char const wort1[] = "ThomasMueller";
    char const wort2[] = "LuemmelSahRot";
    int laenge1 = sizeof(wort1) / sizeof(char) - 1;
    int laenge2 = sizeof(wort2) / sizeof(char) - 1;

    if (laenge1 != laenge2) {
        std::cout << "Die Woerter \"" << wort1 << "\" und \""
                  << wort2 << "\" sind unterschiedlich lang.\n";
        return 1;
    }

    int const alphabet_groesse = 'z' - 'a' + 1;
    int anzahlen[alphabet_groesse] = {0};

    zaehleAlleHoch(wort1, laenge1, anzahlen);
    zaehleAlleRunter(wort2, laenge2, anzahlen);

    bool const istAnagramm = sindAlleNull(anzahlen, alphabet_groesse);
    if (istAnagramm) {
        cout << '\"' << wort1
             << "\" ist ein Anagramm von \""
             << wort2 << "\".\n";
        return 0;
    } else {
        cout << '\"' << wort1
             << "\" ist leider kein Anagramm von \""
             << wort2 << "\". :-((((((((((\n";
        return 1;
    }
}
