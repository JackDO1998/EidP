#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "eidpliste.h"

using namespace std;

template<typename T>
class BinTree {
private:
    struct Node {
        T data;
        Node *left, *right; // linker und rechter Unterbaum
    };
    
    Node* root; // Wurzel
    
    bool isElement(Node* node, T data) {
        if (node == nullptr)
            return false;
        if (node->data == data)
            return true;
        if (node->data < data)
            return isElement(node->right, data);
        return isElement(node->left, data);
    }
    
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
    
    Node* insert(Node *node, T data) {
        if (node == nullptr) {
            node = new Node;
            node->data = data;
            node->left = node->right = nullptr;
            return node;
        }
        if (node->data < data)
            node->right = insert(node->right, data);
        else if (node->data > data)
            node->left = insert(node->left, data);
        return node;
    }
    
    // Aufgabe 1a)
    void preOrder(Node* node) {
        if (node == nullptr) {  //prüft ob im jeweiligen Knoten etwas drin steht(ob er existiert)
      return;
   }
   cout<<node->data<<" "; //gibt die Daten aus dem Knoten aus
      preOrder(node->left); // geht im Suchbaum nach links und ruft sich rekursiv wieder auf
      preOrder(node->right); // wenn es nicht mehr nach links geht geht er nach rechtsreturn;}
    
    }
    // Aufgabe 1a)
    void inOrder(Node* node) {
        if (node != nullptr) {
      inOrder(node->left); //geht bis zum linkesten Element 
      cout<<node->data<<" "; // gibt die Daten dieses Elementes aus
      inOrder(node->right); // geht zum rechten Element 
        }
    }
    
    // Aufgabe 1a)
    void postOrder(Node* node) {
        if (node != nullptr) {
        postOrder(node->left); //geht bis zur wurzel ganz links
        postOrder(node->right); //geht einen nach rechts durch rekursion dann eventuell wieder nach links
        cout<<node->data<<" "; // gibt daten aus
        }
    }
    
    // Aufgabe 1b)
    int height(Node* node) {
        if (node == nullptr) {return 0;}
        else{
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        
        if(lHeight > rHeight){
            return lHeight +1;
        }
        else{
        return rHeight + 1;
        }}
    }
    
    // Aufgabe 1c)
    int count(Node* node){
        if (node == nullptr) {return 0;}
        else{
        return count(node->left) + count(node->right) + 1;}
    }
    
    // Aufgabe 1d)
    void range(Node* node, T min, T max){
         if (node == nullptr) return;
        if (node->data > min) {
            range(node->left, min, max); //rekursiver aufruf nach links
        }
        if (node->data >= min && node->data <= max) { //prüfen ob der Wert innerhalb des intervalls ist
            cout << node->data << " "; //Ausgeben
        }
        if (node->data < max) {
            range(node->right, min, max); // rekursiver Aufruf nach links
        }
    }
    
public:
    BinTree() : root(nullptr) {
    }
    
    ~BinTree() {
        clear(root);
    }
    
    void clear() {
        clear(root);
        root = nullptr;
    }
    
    void insert(T x) {
        root = insert(root, x);
    }
    
    bool isElement(T x) {
        return isElement(root, x);
    }
    
    T rootData(){
        return root->data;
    }
    
    void preOrder() {
        preOrder(root);
        cout << endl;
    }
    
    void inOrder() {
        inOrder(root);
        cout << endl;
    }
    
    void postOrder() {
        postOrder(root);
        cout << endl;
    }
    
    int height() {
        return height(root);
    }
    
    int count() {
        return count(root);
    }
    
    void range(T min, T max){
        range(root, min, max);
    }
    
    // Aufgabe 1e)
    void rotateLeft(){
        if (root == nullptr || root->left == nullptr) return; // wenn die Wurzel oder der linke unterbaum =0 ist wird abgebrochen

        Node *oldRoot = root; // oldroot weißt auf die aktuelle Wurzel
        root = oldRoot->left; // Die Wurzel des linken Unterbaums wird die neue Wurzel

        Node *oldRight = oldRoot->left->right; // 
        root->right = oldRoot; // Die alte Wurzel hängt nun rechts an der neuen Wurzel

        root->right->left = oldRight;
    }

 Liste<int> liste() {
        Liste<int> l; // int Liste initialisieren
        liste(root, l);  //aufruf der Methode Liste an der Wurzel
        return l;
    }

    void liste(Node *node, Liste<int> &l) {
        if (node == nullptr) return; //abbrechen wenn der Knoten =0
        l.append(node->data); // ans ende der Liste die Daten im jeweiligen Knoten
        liste(node->left, l); //rekursiver aufruf
        liste(node->right, l);
    }

    string stringa() {
        string s; //string initialisieren
        Liste<int> l = liste(); 
        for (int i = 0; i < l.size() - 1; i++) {
            s += to_string(l.elementAt(i)) + ','; //solange i kleiner ist als die liste lang ans ende des strings das ite listenelement als string anfügen und mit komma trennen
        }
        s += to_string(l.elementAt(l.size() - 1)); // Ans ende der Liste die Zahl der Einträge von l schreiben
        return s;
    }
    };

// Aufgabe 1f)
// Preorder
void save(BinTree<int> &tree) {
    string s = tree.stringa(); 

    ofstream output;
    output.open("suchBaum.txt"); //datei zum speichern öffnen
    output << s; // den string hineinschreiben
    output.close(); // die datei wieder schließen
}

   


#endif /* BINTREE_H */


