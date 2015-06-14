#include <iostream>
#include "StringtoTree.h"

using namespace std;

int main()
{
    char str[] = "8,6,10,5,#,#,11,4";
    BSTreeNode * root = StringToBinaryTree( str);

    Inorder(root);

    cout<<endl;
    TopOrder(root);
    return 0;
}
