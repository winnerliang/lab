#include <iostream>
#include <vector>
#include "StringtoTree.h"

using namespace std;

struct BSTreeNode
{
    int m_nValue;//value of node
    BSTreeNode * m_pLeft;//left child of node
    BSTreeNode * m_pRight;//right child of node
};

void GetPath(BSTreeNode * root , vector<int > & ss, int sum, int CurtSum)
{
    if(CurtSum > sum)
        return ;
    if (root->m_pLeft== NULL && root->m_pRight==NULL)
    {
        if (CurtSum + root->m_nValue == sum)
        {
            for(unsigned int j =0; j<ss.size(); j++)
                cout<<ss[j]<<",";
            cout<<root->m_nValue<<endl;
        }
        return ;
    }

    if(root->m_pLeft!= NULL )
    {
        ss.push_back(root->m_nValue);
        GetPath(root->m_pLeft, ss, sum, CurtSum+root->m_nValue );
        ss.pop_back();
    }
    if (root->m_pRight!=NULL)
    {
        ss.push_back(root->m_nValue);
        GetPath(root->m_pRight, ss, sum, CurtSum+root->m_nValue);
        ss.pop_back();
    }
}
int main()
{
    std::string str("10,5,12,5,7");
    BSTreeNode * root = StringToBinaryTree(str);
    //Inorder(root);

    vector<int > ss;

    GetPath(root, ss, 20, 0);
    return 0;
}
