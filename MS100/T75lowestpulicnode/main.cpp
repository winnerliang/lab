#include <iostream>
#include "StringtoTree.h"
#include <stack>

using namespace std;

bool Getlist(BSTreeNode * root, BSTreeNode * nodea, stack<BSTreeNode * > &lista)
{
    stack <BSTreeNode * > save;
    save.push(root);

    while( !lista.empty())
    {
        BSTreeNode * tree = save.top();
        save.pop();
        lista.push(tree);

        if(tree == nodea)
        {
            lista.pop();
            break;
        }
        if(tree->m_pRight!=NULL)
        {
            save.push(tree->m_pRight);
        }
        if(tree->m_pLeft!=NULL)
        {
            save.push(tree->m_pLeft);

        }
    }
}

BSTreeNode * Findpublicnode(BSTreeNode * root, BSTreeNode * nodea, BSTreeNode * nodeb)
{
    vector<BSTreeNode * > lista,  listb;
    if(root== NULL || nodea==NULL || nodeb == NULL)
        return NULL;
    ds
}

int main()
{
    char str[]="6,4,8,2,5,7,9,1,3";

    BSTreeNode * root =  StringToBinaryTree( str);
    Inorder(root);

    return 0;
}
