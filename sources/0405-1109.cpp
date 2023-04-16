#include<iostream>
using namespace std;
struct Node {
	string data; 
	Node* left;  
	Node* right;  
	Node* pp;
	Node() //构造函数
    {
		left = right = NULL;
	}
	Node(string st, Node* lt = NULL, Node* rt = NULL)//构造函数
    {
		data = st;
		left = lt;
		right = rt;
	}
};

void CreateTree(Node* &tree)//创建树
{
	static int i = -1;
	string a;
	cin >> a;
	if (a != ".")
	{
		tree = new Node;
		tree->data = a;
		CreateTree(tree->left);
		CreateTree(tree->right);
	}
	else
	{
		tree = NULL;
	}
}

void inOrder(Node* root)//中序
{
	if (root)
	{
		inOrder(root->left);//左 
		cout << root->data<<" "; //根 
		inOrder(root->right); //右 
	}
	else { return; }
}

void preOrder(Node* root)//先序
{
	if (root)
	{
		cout << root->data<<" "; //根 
		preOrder(root->left); //左 
		preOrder(root->right); //右 
	}
	else { return; }
}

void postOrder(Node* root)//后序
{
	if (root)
	{
		postOrder(root->left); //左 
		postOrder(root->right); //右 
		cout << root->data<<" "; //根 
	}
	else { return; }
}

/*void deletetree(Node* root) {
	if (root == NULL)  return;
	deletetree(root->left);
	deletetree(root->right);
	delete root;
	root = NULL;
}*/

int main()
{	Node* root=new Node;
	
	CreateTree(root); 

	inOrder(root);
	cout << endl;
	postOrder(root);
	
	//deletetree(root);
	
	return 0;
}