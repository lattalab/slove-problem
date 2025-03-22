# include <iostream>
# include <string>
using namespace std;
// divide and conquer
struct Node // tree Node
{
    char value;
    Node *left,*right;
};
    void findroot(string preorder, string inorder, string& temp)
    {
        for(int i = 0; i<inorder.length() ; i++)
        {
            if (preorder[0] == inorder[i]) // find root
            {
                // find the root position in the inorder sequence
                int pos = inorder.find(preorder[0]);

                // divide into left-subtree and right-subtree
                string InLeft=inorder.substr(0,pos);         
                string InRight=inorder.substr(pos+1);
                string preLeft=preorder.substr(1,InLeft.size());
                string preRight=preorder.substr(InLeft.size()+1);

                findroot(preLeft, InLeft, temp); // left
                findroot(preRight, InRight, temp); // right
                temp += preorder[0];
            }
        }
    }

int main()
{
    string preorder,inorder;
    while(cin >> preorder >> inorder)
    {
        string temp = "";
        findroot(preorder,inorder, temp);
        cout << temp << endl;
    }
    return 0;
}