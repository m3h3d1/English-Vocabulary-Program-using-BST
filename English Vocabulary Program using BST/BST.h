#ifndef BST_H
#define BST_H

#include<iostream>
#include<fstream>
#include<algorithm>
#include<ctime>
using namespace std;
struct Dict {
    string Word, syn, ant;
};
struct Node {
    string Word, syn, ant;
    Node *left, *right, *parent;
    Node() {
        left = right = parent = NULL;
        Word = syn = ant = "";
    }
};

class bst {
    Node *root;
public:
    bst();
    Node* Root();
    Dict inputData();
    void insertWord(Dict data);
    Node* insertWord(Node *curr, Node *par, Dict data);
    void inorder(Node *curr);
    Node* search(Node* curr, string key);
    Node* minimum(Node* curr);
    Node* maximum(Node* curr);
    Node* successor(Node* curr);
    Dict copyData(Node* tmp);
    Node* deleteWord(Node* curr, Dict data);
    void editWord();
};

#endif