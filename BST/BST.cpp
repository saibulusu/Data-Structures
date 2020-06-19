#include <iostream>

template <typename T>
class TreeNode {
	TreeNode<T>* left;
	TreeNode<T>* right;
	T data;
};

/** BST class declarations */
template <typename T>
class BST {
private:
    int size;
    TreeNode<T>* root;
public:
    BST();
    ~BST();
    void insert(T key);
    T remove(T key);
    int getSize();
    void print();
};

/** Construct the BST with no initial elements */
template <typename T>
BST<T>::BST() {
    size = 0;
	root = new TreeNode<T>;
}

/** Destruct the BST **/
template <typename T>
BST<T>::~BST() {
    delete root;
    root = nullptr;
}

/** Access the size of the BST */
template <typename T>
int BST<T>::getSize() {
    return size;
}

/** Display the elements of the BST from left to right */
template <typename T>
void BST<T>::print() {
	if (root == nullptr) {
		return;
	}
	root->left->print();
	std::cout << root->data << " " << std::endl;
	root->right->print();
}
