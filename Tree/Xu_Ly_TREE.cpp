#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
using namespace std;
struct Node {
  int data;
  Node *left;
  Node *right;
};
typedef Node *Tree;
Node *taoNut(int tam)
{
    Node *p = new Node;
    p->data=tam;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void themNut(Tree &root, Node *node)
{
    if (root)
    {
        if (root->data== node->data)
            return;
        if (node->data<root->data)
            themNut(root->left, node);
        else
            themNut(root->right, node);
    }
    else
    {
        root = node;
    }
}
int demNutLa(Tree t)
{
	if(t==NULL)
		return 0;
	float x=demNutLa(t->left);
	float y=demNutLa(t->right);
	if(t->left==NULL && t->right==NULL)
	    return x+y+1;
	    else
	        return x+y;
}
int main()
{
    Tree t=NULL;
    t = NULL;
    int n=8;
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	themNut(t,taoNut(x));
    }
    cout<<"So nut la : "<<demNutLa(t)<<endl;
    return 0;
}

