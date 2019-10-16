#include <iostream>
#include "BBSTree.h"
#include <iomanip>
using namespace std;

int main()
{
	BBSTree<int> tree;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0; i < 10; i++)
	{
		tree.AddData(arr[i]);
	}
	tree.PreOrder();
	tree.InOrder();
	tree.PostOrder();
	cout << ">>>>>>>>>>>>>>>>>>>>After Delete Data 6" << endl;
	tree.DelData(6);
	tree.PreOrder();
	tree.InOrder();
	tree.PostOrder();
	cout << ">>>>>>>>>>>>>>>>>>>>After Insert Data 6" << endl;
	tree.AddData(6);
	tree.PreOrder();
	tree.InOrder();
	tree.PostOrder();
	return 0;
}