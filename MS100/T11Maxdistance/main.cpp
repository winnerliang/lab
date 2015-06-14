#include <iostream>
#include "StringtoTree.h"
using namespace std;

void GetMaxDistance(BSTreeNode * root, int & maxlen)
{
    if(root==NULL)
        return ;
    if(root->m_pLeft== NULL  )
        root->m_maxleft =0;
    else
        GetMaxDistance(root->m_pLeft, maxlen);
    if(root->m_pRight==NULL)
        root->m_maxright =0;
    else
        GetMaxDistance(root->m_pRight, maxlen);

    if(root->m_pLeft!= NULL)
    {
        root->m_maxleft = (root->m_pLeft->m_maxleft > root->m_pLeft->m_maxright)?root->m_pLeft->m_maxleft:root->m_pLeft->m_maxright;
        root->m_maxleft++;
    }
    if(root->m_pRight!= NULL)
    {
        root->m_maxright = (root->m_pRight->m_maxleft  > root->m_pRight->m_maxright)?root->m_pRight->m_maxleft :root->m_pRight->m_maxright ;
        root->m_maxright++;
    }
    int a = root->m_maxleft+root->m_maxright;
    maxlen = (a > maxlen)?a:maxlen;
}

int main()
{
    char str[] ="9,7,11,5,8,10,#,#,6";

    BSTreeNode * root = StringToBinaryTree(str);
    Inorder(root);

    int maxlen =0;
    GetMaxDistance(root, maxlen);
    cout<<endl<<maxlen;
    return 0;
}
