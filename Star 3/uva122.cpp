// Accepted
#include <iostream>
#include <queue>
using namespace std;

string delimiter = ",";
#define MAX 256
typedef struct Node {
    int data;
    bool valid;
    Node *left, *right;

    // constructor
    Node(int data) :data(data), valid(true), left(nullptr), right(nullptr) {}
    Node() :data(-1), valid(false), left(nullptr), right(nullptr) {}
} Node;

bool CorrectBT(Node *root){
    if (root == nullptr) return true;
    if (root != nullptr && root->data == -1) return false;
    if (root->left != nullptr && root->left->data == -1) return false;
    if (root->right != nullptr && root->right->data == -1) return false;
    return CorrectBT(root->left) && CorrectBT(root->right);
}

void delete_tree(Node *root) {
    if (root == nullptr) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

void BFS(Node *root){
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();    // from head
        cout << curr->data;

        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }

        if (!q.empty()) {
            cout << " ";
        }
    }
}

int main() {
    string s;
    bool isComplete = true;
    Node *root = new Node();

    while (cin >> s) {

        // end case
        if (s == "()") {
            // examine
            if (!CorrectBT(root)) {
                isComplete = false;
            }

            // print the tree
            if (isComplete) {
                BFS(root);
                cout << endl;
            } else {
                cout << "not complete" << endl;
            }
            
            // reset
            isComplete = true;
            delete_tree(root);
            root = new Node();
            continue;
        }

        int sep = s.find(delimiter);    // find the first comma
        int num = stoi(s.substr(1, sep-1));    // get the number
        
        Node* curr = root;  // start from the root, and start to insert the node
        if (s[sep+1] == ')') {

            // if the node is the root
            if (root->valid) {
                isComplete = false;
                continue;
            } else {
                root->data = num;
                root->valid = true;
                continue;
            }

        }
        else {

            for (int i = sep+1; s[i] != ')'; i++) {
                if (s[i] == 'L') {
                    // go left
                    if (curr->left == nullptr){
                        curr->left = new Node();
                        curr = curr->left;
                    }
                    else
                        curr = curr->left;
                } else if (s[i] == 'R') {
                    // go right
                    if (curr->right == nullptr){
                        curr->right = new Node();
                        curr = curr->right;
                    }
                    else
                        curr = curr->right;
                } 
            }
            // if encouter the repeated node, set the invalid flag
            if (curr != nullptr && curr->valid) {
                isComplete = false;
                continue;
            } else {
                curr->data = num;
                curr->valid = true;
            }

        }

    }
    return 0;
}