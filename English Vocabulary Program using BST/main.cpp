#include "BST_code.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    bst* tree = new bst;
    Dict data;
    string str;

    //input file
    ifstream inFile;
    inFile.open("input.txt");
    if(!inFile) {
        cout << "Unable to open file\n";
        exit(1);
    }
    clock_t t;
    t=clock();
    while(inFile>>data.Word) {
        getline(inFile, str);

        getline(inFile,data.syn);
        getline(inFile,data.ant);
        getline(inFile,str);

        transform(data.Word.begin(), data.Word.end(), data.Word.begin(), ::tolower);
        transform(data.syn.begin(), data.syn.end(), data.syn.begin(), ::tolower);
        transform(data.ant.begin(), data.ant.end(), data.ant.begin(), ::tolower);
        
        if(tree->search(tree->Root(), data.Word) == NULL)
            tree->insertWord(data);
    }
    inFile.close();
    t=clock()-t;
    cout << (double)t/1000 << " sec" << endl;

    while(1) {
        //tree->inorder(tree->Root()); cout<<"\n\n";
        cout<<"\t\tEnter 1 to insert data:"<<endl;
        cout<<"\t\tEnter 2 to delete a word:"<<endl;
        cout<<"\t\tEnter 3 to edit data:"<<endl;
        cout<<"\t\tEnter 4 to search a word:"<<endl;
        cout<<"\t\tEnter 5 to traverse inorder:"<<endl;
        cout<<"\t\tEnter 6 to find first word:"<<endl;
        cout<<"\t\tEnter 7 to find last word:"<<endl;
        cout<<"\t\tEnter 8 to find successor of a word:"<<endl;
        cout<<"\t\tEnter others to close the program:"<<endl;
        int x;
        cin>>x;
        if(x<1 || x>8) break;
        switch (x){
            case 1: {
                //insert data
                Dict data = tree->inputData();
                clock_t t;
                t=clock();
                tree->insertWord(data);
                t=clock()-t;
                cout<<(double)t/1000<<" sec"<<endl;
            }
            case 2: {
                //delete Word
                cin>>str;
                Node* tmp = tree->search(tree->Root(), str);
                if(tmp == NULL) cout << "Word doesn't exist, can't delete\n";
                else {
                    data = tree->copyData(tmp);
                    tree->deleteWord(tree->Root(), data);
                }
                break;
            }
            case 3: {
                //Edit Data
                tree->editWord();
                break;
            }
            case 4: {
                //searching
                string v;
                cin>>v;
                Node* res = new Node;
                res = tree->search(tree->Root(), v);
                if(res == NULL)
                    cout << "\tNot found\n";
                else {
                    cout << "\t" << res->Word << endl;
                    cout << "\t" << res->syn <<endl;
                    cout << "\t" << res->ant <<endl;
                }
                break;
            }
            case 5: {
                //inorder print
                tree->inorder(tree->Root()); cout<<'\n';
                break;
            }
            case 6: {
                //find minimum
                Node* tmp = tree->minimum(tree->Root());
                cout<<tmp->Word<<'\n';
                break;
            }
            case 7: {
                //find maximum
                Node* tmp = tree->maximum(tree->Root());
                cout<<tmp->Word<<'\n';
                break;
            }
            case 8: {
                //find successor
                cout << "Enter a Word to find it's successor: ";
                cin>>str;
                transform(str.begin(), str.end(), str.begin(), ::tolower);

                Node* tmp = new Node;
                tmp = tree->search(tree->Root(), str);
                tmp = tree->successor(tmp);
                if(tmp == NULL) cout << "This is the last word\n";
                else {
                    cout << tmp->Word <<endl;
                    cout << tmp->syn <<endl;
                    cout << tmp->ant <<endl;
                }
                break;
            }
            default:
                cout << "Please Enter a choice" << endl;
                break;
        }
    }
    return 0;
}