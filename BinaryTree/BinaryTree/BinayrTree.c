#include "BinayrTree.h"


// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (*pi >= n) return NULL;

	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[(*pi)++];
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);

	return root;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if ((*root) == NULL) return;

	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);

	free(*root);
	*root = NULL;
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL) return 0;

	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL) return 0;

	int cnt = 0;
	if (root->_left == NULL && root->_right == NULL)
	{
		cnt = 1;
	}

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right) + cnt;
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL) return 0;

	if (k == 1) return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right,k-1);

}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if(root == NULL) return NULL;

	if (root->_data == x) return root;

	//BTNode* left = BinaryTreeFind(root->_left, x);
	//BTNode* right = BinaryTreeFind(root->_right, x);

	//if (left == NULL && right == NULL) return NULL;
	//return left ? left : right;

	BTNode* left = BinaryTreeFind(root->_left, x);
	if (left) return left;
	BTNode* right = BinaryTreeFind(root->_right, x);
	if (right) return right;

	return NULL;
}


// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL) return;

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL) return;

	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		pirntf("%c ", front->_data);

		if (front->_left)
			QueuePush(&q, front->left);

		if (front->_right)
			QueuePush(&q, front->right)
	}

	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL) break;

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front) return false;
	}

	QueueDestroy(&q);

	return true;
}