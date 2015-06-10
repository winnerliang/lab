#include <iostream>
#include <vector>
#include <stdlib.h>
#include "StringtoTree.h"

using namespace std;

struct BSTreeNode
{
    int m_nValue;//value of node
    BSTreeNode * m_pLeft;//left child of node
    BSTreeNode * m_pRight;//right child of node
};

static int getOneNodeVal(string &str,int &curPos){
	int rootVal = 0;
	unsigned int nextPos = curPos;
	string valStr;
	//生成根节点
	nextPos=str.find_first_of(',',curPos);
	if (nextPos != string::npos){
		valStr = str.substr(curPos,nextPos-curPos);
	}
	else{
		valStr = str.substr(curPos,str.size()-curPos);
	}
	rootVal = atoi(valStr.c_str());
	curPos = nextPos;
	return rootVal;
}

BSTreeNode * StringToBSTreeNode(string str){
	//空树返回NULL
	if (str.compare("{}")==0){
		return NULL;
	}

	//生成根节点
	int rootVal=0;
	int curPos= 0;
	rootVal = getOneNodeVal(str,curPos);
	BSTreeNode *root = new BSTreeNode[1];
	root->m_nValue = rootVal;
	root->m_pLeft =NULL;
	root->m_pRight = NULL;

    BSTreeNode * pTemp = NULL;

	//初始化广度优先队列
	vector <BSTreeNode *> preLevel,curLevel;
	preLevel.push_back(root);

	//遍历字符串生成二叉树
	int levelNodeNum=2;
	int alreadyGenerate=0;

	while(true){
		//证明所有节点都生成完毕了
		if (curPos == string::npos){
			break;
		}
		curPos++;
		if (str[curPos]=='#'){
			curPos++;
			pTemp=NULL;
		}
		else{
			rootVal = getOneNodeVal(str,curPos);
			BSTreeNode *pTemp = new BSTreeNode();
			pTemp->m_nValue = rootVal;
			pTemp->m_pLeft =NULL;
			pTemp->m_pRight = NULL;
			//left child
			if (alreadyGenerate%2==0){
				preLevel[alreadyGenerate/2]->m_pLeft=pTemp;
			}
			//right child
			else{
				preLevel[alreadyGenerate/2]->m_pRight=pTemp;
			}
			curLevel.push_back(pTemp);
		}
		alreadyGenerate ++;
		if (alreadyGenerate==levelNodeNum)
		{
			alreadyGenerate=0;
			preLevel.swap(curLevel);
			curLevel.clear();
			levelNodeNum=preLevel.size()*2;
		}
	}
	return root;
}

//using for Testing
static void Inorder(BSTreeNode * root )
{
    if (root->m_pLeft != NULL)
        Inorder(root->m_pLeft);
    cout<<root->m_nValue<<" ";
    if (root->m_pRight != NULL)
        Inorder(root->m_pRight);
}


int main()
{
    string str("1,2,3,4,5");
    BSTreeNode * root = StringToBSTreeNode(str);

    Inorder(root);

    return 0;
}

