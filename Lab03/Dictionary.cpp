//
// Created by Chris Simaan on 5/6/22.
//

#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary() {
    Root = nullptr;
    current = nullptr;
    //Open Data File
    dictData.open("Dictionary.txt");
    //Empty BST Just In Case
    makeEmpty();
    //Populate From Data File
    populateFromFile();
    //Close Data File
    dictData.close();
}

Dictionary::~Dictionary() {
    //Save to file on close
    save();

    //Clear node list
    makeEmpty();
}


void Dictionary::put(Node* root, string word, string def) {
    if (word < root->word)//to the left
    {
        if (root->left == nullptr) {
            root->left = new Node(word, def);
        }
        else
            put(root->left, word, def);
    }
    else//to the right
    {
        if (root->right == nullptr) {
            root->right = new Node(word, def);
        }
        else
            put(root->right, word, def);
    }
}

void Dictionary::empty(Node* root) {
//post order traversal Left Right Middle
    if (root->left != nullptr)
        empty(root->left);

    if (root->right != nullptr)
        empty(root->right);

    delete root;

}

void Dictionary::putItem(string word, string def) {
    //Convert to lowercase
    std::for_each(word.begin(), word.end(), [](char & c) {
        c = tolower(c);
    });

    if (isEmpty())
    {
        Root = new Node(word, def);
    }
    else
        put(Root, word, def);
}

void Dictionary::deleteNode(Node *root) {

    Node*parent= findParent(root);

    if (root->left == nullptr && root->right == nullptr)
    {
        //no children
        if (parent == nullptr)
        {
            Root = nullptr;
        }
        else if (parent->left == root)
            parent->left = nullptr;
        else
            parent->right = nullptr;

        delete root;

    }
    else if (root->left != nullptr && root->right == nullptr)
    {
        if (parent == nullptr)
        {
            Root = root->left;
        }
        else if(parent->left == root)
        {
            parent->left = root->left;
        }
        else
        {
            parent->right = root->left;
        }

        delete root;
    }
    else if (root->right != nullptr && root->left == nullptr)
    {

        if (parent == nullptr)
        {
            Root = root->right;
        }
        else if (parent->left == root)
            parent->left = root->right;
        else
            parent->right = root->right;

        delete root;
    }
    else //right and left child
    {
        if (parent == nullptr) //deleting root
        {

            Node* rightMost = rightMostLeft(root->left);
            string temp = rightMost->word;

            deleteNode(rightMost);

            root->word = temp;
        }
    }
}

Node* Dictionary::findParent(Node* child) {
    Node* parent;
    if (child == Root)
    {
        parent = nullptr;
        return parent;
    }

    parent = Root;


    while (parent != nullptr )
    {
        if (child->word < parent->word)
        {
            if (parent->left == child)
                return parent;
            else
                parent = parent->left;
        }
        else
        {
            if (parent->right == child)
                return parent;
            else
                parent = parent->right;
        }

    }

    return nullptr;
}


//finds right most child on left side of current node.
Node* Dictionary::rightMostLeft(Node* rightMost) {
    while (rightMost->right != nullptr)
        rightMost = rightMost->right;

    return rightMost;

}

bool Dictionary::deleteItem(string word) {
    //Convert to lowercase
    for_each(word.begin(), word.end(), [](char & c) {
        c = tolower(c);
    });

    if (isEmpty())
        return false;

    if (!findItem(word))
        return false;
    else
        deleteNode(current);
}


//Sets current to location if item is found.
bool Dictionary::findItem(string word) {
    //Convert to lowercase
    for_each(word.begin(), word.end(), [](char & c) {
        c = tolower(c);
    });

    if (isEmpty())
        return false;

    current = Root;
    bool found = false;

    while (current != nullptr && found == false)
    {
        if (current->word == word)
            found = true;
        else if (word < current->word)
            current = current->left;
        else
            current = current->right;
    }

    return found;
}

bool Dictionary::isEmpty() {
    if (Root == nullptr)
        return true;
    else
        return false;
}

void Dictionary::makeEmpty() {
    if (isEmpty())
        return;

    empty(Root);//recursive function

    Root = nullptr;
    current = nullptr;

}

void Dictionary::orderPrint(Node* root) {
    // inorder Traversal (LMR)

    if (root->left != nullptr)
        orderPrint(root->left);

    std::cout << root->word << " " << root->def << endl;

    if (root->right != nullptr)
        orderPrint(root->right);
}

void Dictionary::printOrderedList() {
    if (isEmpty())
        std::cout << "Tree Empty!" << std::endl;

    orderPrint(Root);
    std::cout << std::endl;

}

string Dictionary::getCurrent() {
    if (current == nullptr)
        return "DNE";

    return current->word;
}

string Dictionary::getDefinition(string word) {
    //Convert to lowercase
    for_each(word.begin(), word.end(), [](char & c) {
        c = tolower(c);
    });
    findItem(word);
    if (current == nullptr)
        return "DNE";
    return current->def;
}

void Dictionary::saveToFile(Node* root) {
    // inorder Traversal (LMR)

    if (root->left != nullptr)
        saveToFile(root->left);

    dictData << root->word << ": " << root->def << endl;


    if (root->right != nullptr)
        saveToFile(root->right);


}

void Dictionary::populateFromFile() {
    string str;

    while (getline(dictData, str)) {
        int delimiter = str.find(":");
        string word = str.substr(0, delimiter);
        string def = str.substr(delimiter+2);
        //cout << word << " " << def << endl;
        putItem(word, def);
    }
}

void Dictionary::saveFile() {
    dictData.open("Dictionary.txt");

    if (isEmpty())
        std::cout << "Tree Empty!" << std::endl;

    saveToFile(Root);
    std::cout << std::endl;

}

void Dictionary::save() {
    //Clear text file to make sure it doesn't overlap definitions
    ofstream ofs;
    ofs.open("Dictionary.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    //Saves on close
    dictData.open("Dictionary.txt");
    saveToFile(Root);
    dictData.close();
}
