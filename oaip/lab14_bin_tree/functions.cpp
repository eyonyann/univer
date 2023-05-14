#include "header.h"

Node* createNode(int key, const string& data) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int key, const string& data) {
    if (root == nullptr) {
        return createNode(key, data);
    }

    if (key < root->key) {
        root->left = insert(root->left, key, data);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key, data);
    }

    return root;
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* remove(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = remove(root->left, key);
    }
    else if (key > root->key) {
        root->right = remove(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* minRight = findMin(root->right);
        root->key = minRight->key;
        root->data = minRight->data;
        root->right = remove(root->right, minRight->key);
    }

    return root;
}

void freeMemory(Node* root);

Node* removeBranch(Node* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }

    if (key < root->key) {
        root->left = removeBranch(root->left, key);
    }
    else if (key > root->key) {
        root->right = removeBranch(root->right, key);
    }
    else {
        // Найдена ветка с заданным ключом, удаляем её
        freeMemory(root);
        cout << "Ветка удалена успешно\n";
        return nullptr;
    }

    return root;
}


void printTree(Node* root, int level = 0) {
    if (root != nullptr) {
        printTree(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            cout << "    ";
        }
        cout << "|" << root->key << " " << root->data << "|" << endl;
        printTree(root->left, level + 1);
    }
}

int findDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}



void freeMemory(Node* root) {
    if (root != nullptr) {
        freeMemory(root->left);
        freeMemory(root->right);
        delete root;
    }
}

int checkInt(int a) {
    while (true) {
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ввод может содержать только числа. Попробуйте еще раз." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.gcount() > 1) {
            cout << "Ввод может содержать только числа. Попробуйте снова." << endl;
            continue;
        }
        break;
    }
    return a;
}

void saveDataToFile(Node* root, ofstream& outputFile) {
    if (root != nullptr) {
        saveDataToFile(root->left, outputFile);
        outputFile << root->key << " " << root->data << endl;
        saveDataToFile(root->right, outputFile);
    }
}