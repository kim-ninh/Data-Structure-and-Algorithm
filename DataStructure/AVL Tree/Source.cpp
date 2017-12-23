#include"AVLTree.cpp"

int main()
{
	AVL_TREE<int> T;
	// int n;
	// do
	// {
	// 	cin >> n;
	// 	if (n != -1)
	// 		T.InsertNode(n);
	// } while (n != -1);
	T.InsertNode(10);
	T.InsertNode(30);
	T.InsertNode(35);
	//cout << endl << endl;

	T.printTree();
	system("pause");
	return 0;
}
