#include <iostream>
#include "StringtoTree.h"

using namespace std;

int getdepth(BSTreeNode * root)
{
    if(root ==NULL)
        return 0;
    int left=0, right=0;
    left = getdepth(root->m_pLeft);
    right = getdepth(root->m_pRight);
    return (left > right)?left+1:right+1;
}

bool Isbalanced(BSTreeNode *root, int & depth)
{
    if(!root)
    {
        depth=0;
        return true;
    }
    int left, right;
    if(Isbalanced(root->m_pLeft, left) && Isbalanced(root->m_pRight, right))
    {
        int t = left>right?left-right:right-left;
        if(t <2)
        {
            depth = 1+(left>right?left:right);
            return true;
        }

    }
    return false;
}

bool IsBalance(BSTreeNode * root)
{
    int depth=0;
    return Isbalanced(root, depth);

}

int main()
{
    BSTreeNode * root = StringToBinaryTree("10,6,14,#,#,12,16,#,#,11");

    TopOrder(root);
    cout<<endl;
    cout<<IsBalance(root);

    return 0;
}
