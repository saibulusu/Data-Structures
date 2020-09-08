#include <iostream>

template <typename T>
class TreeNode {
	std::vector<T> keys;
	std::vector<TreeNode<T>> child;
}

/** BTree class declarations */
template <typename T>
class BTree {
private:
	int size;
	TreeNode<T>* root;
public:
	BTree();
	~BTree();
	void insert(T key);
	T remove(T key);
	int getSize();
	void print();
}

/** Construct the BTree with no initial elements */
template <typename T>
BTree<T>::BTree() {
	size = 0;
	root = new TreeNode<T>;
}

/**Destruct the BTree */
template <typename T>
BTree<T>::~BTree<T>() {
	delete root;
	root = nullptr;
}

/** Insert a key into the tree */
template <typename T>
void BTree<T>::insert(T key) {
	
}


