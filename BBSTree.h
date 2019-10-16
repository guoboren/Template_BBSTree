#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

template<typename T> class BBSTree {
private:
	enum BALANCE {
		LH = -1,
		EH = 0,
		RH = 1
	};
	enum DIRECTION {
		LEFT = 0,
		RIGHT = 1
	};
	class Node {
	public:
		Node(T d, Node* l, Node* r, Node* p, int b) :data(d), left(l), right(r), parent(p), balance(b) {}
		T data;
		Node* left;
		Node* right;
		Node* parent;
		int balance;
	};
public:
	BBSTree();
	~BBSTree();
	void AddData(T d);
	void DelData(T d);
	void PreOrder();
	void InOrder();
	void PostOrder();
private:
	void PreOrder(BBSTree::Node* t);
	void InOrder(BBSTree::Node* t);
	void PostOrder(BBSTree::Node* t);
	BBSTree::Node* GetPreMaxNode(BBSTree::Node* t);
	void Destroy(BBSTree::Node* t);
	bool Insert(BBSTree<T>::Node* parent, BBSTree::Node** pt, T d, bool* taller);
	void Delete(BBSTree::Node** pt, T d);
	void L_Rotate(BBSTree::Node** pt);
	void R_Rotate(BBSTree::Node** pt);
	void L_Balance(BBSTree::Node** pt);
	void R_Balance(BBSTree::Node** pt);
	int Height(BBSTree::Node** pt);
private:
	BBSTree::Node* root;
};


template<typename T>
BBSTree<T>::BBSTree()
{
	root = NULL;
}

template<typename T>
BBSTree<T>::~BBSTree()
{
	Destroy(root);
}

template<typename T>
void BBSTree<T>::AddData(T d)
{
	bool taller = false;
	Insert(NULL, &root, d, &taller);
}

template<typename T>
void BBSTree<T>::DelData(T d)
{
	Delete(&root, d);
}

template<typename T>
void BBSTree<T>::PreOrder()
{
	cout << "$PRE-ORDER$" << endl;
	PreOrder(root);
	cout << endl;
}

template<typename T>
void BBSTree<T>::InOrder()
{
	cout << "$IN-ORDER$" << endl;
	InOrder(root);
	cout << endl;
}

template<typename T>
void BBSTree<T>::PostOrder()
{
	cout << "$POST-ORDER$" << endl;
	PostOrder(root);
	cout << endl;
}

template<typename T>
void BBSTree<T>::PreOrder(BBSTree<T>::Node* t)
{
	if (t == NULL)
	{
		return;
	}
	cout << setw(10) << "[self]:" << setw(6) << t->data;
	if (t->parent == NULL) 
	{
		cout << setw(10) << " [parent]:" << setw(6) <<"NULL";
	}
	else
	{
		cout << setw(10) << " [parent]:" << setw(6) << t->parent->data;
	}
	if (t->left == NULL) 
	{
		cout << setw(10) << " [left]:" << setw(6) << "NULL";
	}
	else
	{
		cout << setw(10) << " [left]:" << setw(6) << t->left->data;
	}
	if (t->right == NULL) 
	{
		cout << setw(10) << " [right]:" << setw(6) << "NULL" << endl;
	}
	else
	{
		cout << setw(10) << " [right]:" << setw(6) << t->right->data << endl;
	}
	PreOrder(t->left);
	PreOrder(t->right);
}

template<typename T>
void BBSTree<T>::InOrder(BBSTree<T>::Node* t)
{
	if (t == NULL)
	{
		return;
	}
	InOrder(t->left);
	cout << setw(10) << "[self]:" << setw(6) << t->data;
	if (t->parent == NULL) 
	{
		cout << setw(10) << " [parent]:" << setw(6) <<"NULL";
	}
	else
	{
		cout << setw(10) << " [parent]:" << setw(6) << t->parent->data;
	}
	if (t->left == NULL) 
	{
		cout << setw(10) << " [left]:" << setw(6) << "NULL";
	}
	else
	{
		cout << setw(10) << " [left]:" << setw(6) << t->left->data;
	}
	if (t->right == NULL) 
	{
		cout << setw(10) << " [right]:" << setw(6) << "NULL" << endl;
	}
	else
	{
		cout << setw(10) << " [right]:" << setw(6) << t->right->data << endl;
	}
	InOrder(t->right);
}

template<typename T>
void BBSTree<T>::PostOrder(BBSTree<T>::Node* t)
{
	if (t == NULL)
	{
		return;
	}
	PostOrder(t->left);
	PostOrder(t->right);
	cout << setw(10) << "[self]:" << setw(6) << t->data;
	if (t->parent == NULL) 
	{
		cout << setw(10) << " [parent]:" << setw(6) <<"NULL";
	}
	else
	{
		cout << setw(10) << " [parent]:" << setw(6) << t->parent->data;
	}
	if (t->left == NULL) 
	{
		cout << setw(10) << " [left]:" << setw(6) << "NULL";
	}
	else
	{
		cout << setw(10) << " [left]:" << setw(6) << t->left->data;
	}
	if (t->right == NULL) 
	{
		cout << setw(10) << " [right]:" << setw(6) << "NULL" << endl;
	}
	else
	{
		cout << setw(10) << " [right]:" << setw(6) << t->right->data << endl;
	}
}

template<typename T>
class BBSTree<T>::Node* BBSTree<T>::GetPreMaxNode(BBSTree<T>::Node* t)
{
	if (t->left != NULL)
	{
		BBSTree<T>::Node* tmp = t->left;
		while (tmp != NULL)
		{
			if (tmp->right != NULL)
			{
				tmp = tmp->right;
			}
			else
			{
				return tmp;
			}
		}
	}
	else
	{
		BBSTree<T>::Node* parent = t->parent;
		BBSTree<T>::Node* tmp = t;
		while (parent != NULL)
		{
			if (parent->right == t)
			{
				return parent;
			}
			tmp = parent;
			parent = parent->parent;
		}
	}
	return NULL;
}

template<typename T>
void BBSTree<T>::Destroy(BBSTree<T>::Node* t)
{
	if (t == NULL)
	{
		return;
	}
	Destroy(t->left);
	Destroy(t->right);
	delete t;
	t = NULL;
}

template<typename T>
bool BBSTree<T>::Insert(BBSTree<T>::Node* parent, BBSTree<T>::Node** pt, T d, bool* taller)
{
	if (*pt == NULL)
	{
		*pt = new BBSTree<T>::Node(d, NULL , NULL, parent, EH);
		*taller = true;
	}
	else
	{
		if ((*pt)->data == d)
		{
			*taller = false;
			return false;
		}
		else if(d < (*pt)->data)
		{
			Insert(*pt, &(*pt)->left, d, taller);
			if (*taller)
			{
				switch((*pt)->balance)
				{
				case LH:
				{
					*taller = false;
					L_Balance(pt);
				}
				break;
				case EH:
				{
					(*pt)->balance = LH;
					*taller = true;
				}
				break;
				case RH:
				{
					(*pt)->balance = EH;
					*taller = false;
				}
				break;
				}
			}
		}
		else
		{
			Insert(*pt, &(*pt)->right, d, taller);
			if (*taller)
			{
				switch((*pt)->balance)
				{
				case LH:
				{
					*taller = false;
					(*pt)->balance = EH;
				}
				break;
				case EH:
				{
					(*pt)->balance = RH;
					*taller = true;
				}
				break;
				case RH:
				{
					R_Balance(pt);
					*taller = false;
				}
				break;
				}
			}
		}
	}
	return true;
}

template<typename T>
void BBSTree<T>::Delete(BBSTree<T>::Node** pt, T d)
{
	if (*pt == NULL)
	{
		return;
	}
	else
	{
		if ((*pt)->data == d)
		{
			BBSTree<T>::Node* parent = (*pt)->parent;
			int direction = -1;
			if (parent)
			{
				if (parent->left == *pt)
				{
					direction = LEFT;
				}
				else
				{
					direction = RIGHT;
				}
			}
			if ((*pt)->left == NULL && (*pt)->right == NULL)
			{
				delete *pt;
				*pt = NULL;
				if (parent && direction == LEFT)
				{
					parent->left = NULL;
				}
				else
				{
					parent->right = NULL;
				}
			}
			else if ((*pt)->left != NULL && (*pt)->right == NULL)
			{
				if (parent && direction == LEFT)
				{
					parent->left = (*pt)->left;
				}
				else if (parent && direction == RIGHT)
				{
					parent->right = (*pt)->left;
				}
			}
			else if ((*pt)->left == NULL && (*pt)->right != NULL)
			{
				if (parent && direction == LEFT)
				{
					parent->left = (*pt)->right;
				}
				else if (parent && direction == RIGHT)
				{
					parent->right = (*pt)->right;
				}
			}
			else
			{
				BBSTree<T>::Node* preMaxNode = GetPreMaxNode(*pt);
				(*pt)->data = preMaxNode->data;
				Delete(&(*pt)->left, (*pt)->data);
			}
		}
		else if (d < (*pt)->data)
		{
			Delete(&(*pt)->left, d);
			if (Height(&(*pt)->right) - Height(&(*pt)->left) > 1)
			{
				R_Balance(pt);
			}
		}
		else
		{
			Delete(&(*pt)->right, d);
			if (Height(&(*pt)->left) - Height(&(*pt)->right) > 1)
			{
				L_Balance(pt);
			}
		}
	}
}

template<typename T>
void BBSTree<T>::L_Rotate(BBSTree<T>::Node** pt)
{
	if (pt == NULL || *pt == NULL)
	{
		return;
	}
	BBSTree<T>::Node* r = (*pt)->right;
	(*pt)->right = r->left;
	if (r->left != NULL)
	{
		r->left->parent = *pt;
	}
	r->left = *pt;
	r->parent = (*pt)->parent;
	(*pt)->parent = r;
	(*pt) = r;
}

template<typename T>
void BBSTree<T>::R_Rotate(BBSTree<T>::Node** pt)
{
	if (pt == NULL || *pt == NULL)
	{
		return;
	}
	BBSTree<T>::Node* l = (*pt)->left;
	(*pt)->left = l->right;
	if (l->right != NULL)
	{
		l->right->parent = *pt;
	}
	l->right = *pt;
	l->parent = (*pt)->parent;
	(*pt)->parent = l;
	*pt = l;
}

template<typename T>
void BBSTree<T>::L_Balance(BBSTree<T>::Node** pt)
{
	BBSTree<T>::Node* l = (*pt)->left;
	switch (l->balance)
	{
	case LH:
	{
		(*pt)->balance = l->balance = EH;
		R_Rotate(pt);
	}
	break;
	case RH:
	{
		BBSTree<T>::Node* lr = l->right;
		switch (lr->balance)
		{
		case LH:
		{
			l->balance = EH;
			(*pt)->balance = RH;
		}
		break;
		case EH:
		{
			l->balance = EH;
			(*pt)->balance = EH;
		}
		break;
		case RH:
		{
			l->balance = LH;
			(*pt)->balance = EH;
		}
		break;
		}
		lr->balance = EH;
		L_Rotate(&(*pt)->left);
		R_Rotate(pt);
	}
	break;
	}
}

template<typename T>
void BBSTree<T>::R_Balance(BBSTree<T>::Node** pt)
{
	BBSTree<T>::Node* r = (*pt)->right;
	switch(r->balance)
	{
	case LH:
	{
		BBSTree<T>::Node* rl = r->left;
		switch(rl->balance)
		{
		case LH:
		{
			(*pt)->balance = EH;
			r->balance = RH;
		}
		break;
		case EH:
		{
			(*pt)->balance = r->balance = EH;
		}
		break;
		case RH:
		{
			(*pt)->balance = LH;
			r->balance = EH;
		}
		break;
		}
		rl->balance = EH;
		R_Rotate(&(*pt)->right);
		L_Rotate(pt);
	}
	break;
	case RH:
	{
		r->balance = (*pt)->balance = EH;
		L_Rotate(pt);
	}
	break;
	}
}

template<typename T>
int BBSTree<T>::Height(BBSTree::Node** pt)
{
	if (*pt == NULL)
	{
		return 0;
	}
	else
	{
		int leftHeight = Height(&(*pt)->left);
		int rightHeight = Height(&(*pt)->right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
}