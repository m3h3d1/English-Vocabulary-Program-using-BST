#ifndef BST_code
#define BST_code

#include "BST.h"

bst::bst() {
    root = NULL;
}

Node* bst::Root() { 
    return root;
}

Dict bst::inputData() {
    string str;
    Dict data;
    cout << "Enter Word:\n";
    cin >> data.Word;
    getline(cin, str);
    cout << "Enter Synonyms:\n";
    cin >> data.syn;
    getline(cin,data.syn);
    cout << "Enter Antonyms:\n";
    getline(cin,data.ant);
    //getline(cin,str);

    transform(data.Word.begin(), data.Word.end(), data.Word.begin(), ::tolower);
    transform(data.syn.begin(), data.syn.end(), data.syn.begin(), ::tolower);
    transform(data.ant.begin(), data.ant.end(), data.ant.begin(), ::tolower);

    return data;
}

void bst::insertWord(Dict data) {
    root = insertWord(root, NULL, data);
}

Node* bst::insertWord(Node* curr, Node* par, Dict data) {
    if(curr == NULL) {
        Node* tmp = new Node;
        tmp->Word = data.Word;
        tmp->syn = data.syn;
        tmp->ant = data.ant;

        tmp->parent = par;
        return tmp;
    }
    if(data.Word == curr->Word) cout<< "This Word is already existed!\n";
    else if(data.Word < curr->Word)
        curr->left = insertWord(curr->left, curr, data);
    else
        curr->right = insertWord(curr->right, curr, data);
    return curr;
}

void bst::inorder(Node* curr) {
    if(curr) {
        inorder(curr->left);
        cout << curr->Word << " ";
        inorder(curr->right);
    }
}

Node* bst::search(Node* curr, string key) {
    if(curr == NULL || curr->Word == key)
        return curr;
    if(key < curr->Word)
        return search(curr->left, key);
    else
        return search(curr->right, key);
}

Node* bst::minimum(Node* curr) {
    if(curr->left != NULL) {
        return minimum(curr->left);
    }
    return curr;
}

Node* bst::maximum(Node* curr) {
    if(curr->right != NULL) {
        return maximum(curr->right);
    }
    return curr;
}

Node* bst::successor(Node* curr) {
    if(curr->right != NULL)
        return minimum(curr->right);
    Node* tmp = curr->parent;
    while(tmp != NULL && curr == tmp->right) {
        curr = tmp;
        tmp = tmp->parent;
    }
    return tmp;
}

Dict bst::copyData(Node* tmp) {
    Dict data;
    data.Word = tmp->Word;
    data.syn = tmp->syn;
    data.ant = tmp->ant;
    return data;
}

Node* bst::deleteWord(Node* curr, Dict data) {
    if(curr == NULL) return curr;
    else if(data.Word < curr->Word)
        curr->left = deleteWord(curr->left, data);
    else if(data.Word > curr->Word)
        curr->right = deleteWord(curr->right, data);
    else {
        //No child
        if(curr->left == NULL && curr->right == NULL) {
            curr = NULL;
            delete curr;
        }

        //One child
        else if(curr->left == NULL) {
            Node* tmp = curr;
            curr = curr->right;
            delete tmp;
        }
        else if(curr->right == NULL) {
            Node* tmp = curr;
            curr = curr->left;
            delete tmp;
        }

        //both child
        else {
            Node* tmp = minimum(curr->right);
            curr->Word = tmp->Word;
            curr->syn = tmp->syn;
            curr->ant = tmp->ant;
            data = copyData(tmp);
            
            curr->right = deleteWord(curr->right, data);
        }
    }
    return curr;
}

void bst::editWord() {
    string str;
    cout << "Enter Word which will be edited\n";
    cin >> str;
    Node* tmp = search(root, str);
    if(tmp == NULL) cout << "input word doesn't exist in database\n";
    else {
        Dict data;
        data = copyData(tmp);
        deleteWord(root, data);

        data = inputData();

        insertWord(root, NULL, data);
    }
}

#endif