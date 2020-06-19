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

/** Insert a key into the tree */
template <typename T>
void BST<T>::insert(T key) {
	if (root == nullptr) {
		root = new TreeNode<T>;
		root->data = key;
	} else {
		TreeNode<T>* cur = root;
		while (cur != nullptr) {
			if (cur->data == key) {
				throw std::runtime_error("Inserting duplicate key");
			} else {
				cur = (cur->data < key) ? cur->right : cur->left;
			}
		}
		cur = new TreeNode<T>;
		cur->data = key;
		++size;
	}
}

/** Remove a key from the tree */
template <typename T>
T BST<T>::remove(T key) {
	TreeNode<T>* cur = root;
	while (cur != nullptr) {
		if(cur->data == key) {	
			if (cur->left == nullptr && cur->right == nullptr) {
				T oldKey = cur->data;
				delete cur;
				return oldKey;
			} else if (cur->left == nullptr) {
				T oldKey = cur->data;
				delete cur;
				cur = cur->right;
			} else if (cur->right == nullptr) {
				T oldKey = cur->data;
				delete cur;
				cur = cur->left;
			} else {
				
			}
		}
	}
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
