#include <iostream>
#include "StringtoTree.h"

using namespace std;

BSTreeNode * createBST(int *p, int len)
{
    if (len<1)
        return NULL;
    BSTreeNode *root = new BSTreeNode[1];

    root->m_nValue = p[len/2];
    root->m_pLeft = createBST(p, len/2);
    root->m_pRight = createBST(p+len/2+1, len - len/2-1);
    return root;
}

int main()
{
    int len =10;
    int * p = new int [len];
    for(int i=0; i<len; cout<<p[i]<<", ",i++)
        p[i] =i+1;
    cout<<endl;
    BSTreeNode * root = createBST(p, len);

    Inorder(root);
    delete[]p;
    return 0;
}
