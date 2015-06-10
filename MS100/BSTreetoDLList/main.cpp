#include <iostream>
#include "StringtoTree.h"

using namespace std;

struct BSTreeNode
{
    int m_nValue;//value of node
    BSTreeNode * m_pLeft;//left child of node
    BSTreeNode * m_pRight;//right child of node
};

BSTreeNode * convert(BSTreeNode * pCurt)
{
    BSTreeNode * LastNode = NULL;
    if (pCurt == NULL)
        return NULL;
    if (pCurt->m_pLeft != NULL)
    {
        LastNode = convert(pCurt->m_pLeft );
    }

    pCurt->m_pLeft = LastNode;

    if(LastNode != NULL)
        LastNode->m_pRight = pCurt;

    if (pCurt->m_pRight != NULL)
    {
        LastNode = convert(pCurt->m_pRight );
    }

    return LastNode;
}

BSTreeNode * BSTreetoDLList(BSTreeNode * root )
{
    if(root== NULL)
        return NULL;

    BSTreeNode * dllist = convert(root);

    while(dllist!= NULL && dllist->m_pLeft != NULL)
    {
        cout<<dllist->m_nValue<<" ";
        dllist = dllist->m_pLeft;
    }

    return dllist;
}

int main()
{

    string str("10,6,14,4,8,12,16,#,#,7,9");
    BSTreeNode * root = StringToBinaryTree(str);

    Inorder(root );

    BSTreetoDLList( root );

    return 0;
}
