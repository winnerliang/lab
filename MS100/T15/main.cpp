#include <iostream>
#include"StringtoTree.h"

using namespace std;

void MirrorTree(BSTreeNode * root)
{
    if(root==NULL)
        return ;
    BSTreeNode * temp = root->m_pLeft;
    root->m_pLeft = root->m_pRight;
    root->m_pRight = temp;

    MirrorTree(root->m_pLeft);
    MirrorTree(root->m_pRight);
}

int main()
{
    char str []="8,6,10,5,7,9,11";

    BSTreeNode * root = StringToBinaryTree( str);
    Inorder(root);

    MirrorTree(root);
    cout<<endl;

    Inorder(root);

    return 0;
}
