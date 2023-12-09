#pragma once
#include <iostream>
#include <Windows.h>
#include "List.h"
#include <sstream>

template <typename T>
struct tree_elem_generic {
	T data;
	list_elem* list;
	tree_elem_generic* left, * right, * parent;
	bool color; // True - Black
};

template <typename T>
tree_elem_generic<T>* root_init_generic(tree_elem_generic<T>* nullnode) {
	tree_elem_generic<T>* root = nullnode;
	return root;
}

template <typename T>
tree_elem_generic<T>* null_init_generic() {
	tree_elem_generic<T>* nullnode = new tree_elem_generic<T>;
	nullnode->left = nullptr;
	nullnode->right = nullptr;
	nullnode->list = nullptr;
	nullnode->color = true;
	return nullnode;
}

template <typename T>
tree_elem_generic<T>* search(tree_elem_generic<T>* root, tree_elem_generic<T>* nullnode, T data) {
	tree_elem_generic<T>* temp = root;
	while (temp != nullnode) {
		if (temp->data == data) return temp;
		if (data > temp->data) temp = temp->right;
		else temp = temp->left;
	}
	return nullnode;
}

template <typename T>
void rightRotate(tree_elem_generic<T>* element, tree_elem_generic<T>*& root, tree_elem_generic<T>* nullnode) {
	tree_elem_generic<T>* y = element->left;
	element->left = y->right;
	if (y->right != nullnode) y->right->parent = element;
	y->parent = element->parent;
	if (element->parent == nullptr) root = y;
	else if (element == element->parent->right) element->parent->right = y;
	else element->parent->left = y;
	y->right = element;
	element->parent = y;
}

template <typename T>
void leftRotate(tree_elem_generic<T>* element, tree_elem_generic<T>*& root, tree_elem_generic<T>* nullnode) {
	tree_elem_generic<T>* y = element->right;
	element->right = y->left;
	if (y->left != nullnode) y->left->parent = element;
	y->parent = element->parent;
	if (element->parent == nullptr) root = y;
	else if (element == element->parent->left) element->parent->left = y;
	else element->parent->right = y;
	y->left = element;
	element->parent = y;
}

template <typename T>
void insert_balance(tree_elem_generic<T>*& element, tree_elem_generic<T>*& root, tree_elem_generic<T>* nullnode) {
	tree_elem_generic<T>* uncle;
	while (element->parent->color == false) {
		if (element->parent == element->parent->parent->left) {
			uncle = element->parent->parent->right;
			if (uncle->color == false) {
				uncle->color = true;
				element->parent->color = true;
				element->parent->parent->color = false;
				element = element->parent->parent;
			}
			else {
				if (element == element->parent->right) {
					element = element->parent;
					leftRotate(element, root, nullnode);
				}
				element->parent->color = true;
				element->parent->parent->color = false;
				rightRotate(element->parent->parent, root, nullnode);

			}
		}
		else {
			uncle = element->parent->parent->left;
			if (uncle->color == false) {
				uncle->color = true;
				element->parent->color = true;
				element->parent->parent->color = false;
				element = element->parent->parent;
			}
			else {
				if (element == element->parent->left) {
					element = element->parent;
					rightRotate(element, root, nullnode);
				}
				element->parent->color = true;
				element->parent->parent->color = false;
				leftRotate(element->parent->parent, root, nullnode);
			}
		}
		if (element == root) { break; }
	}
	root->color = true;

}

template <typename T>
tree_elem_generic<T>* insert(tree_elem_generic<T>*& root, tree_elem_generic<T>* nullnode, T data, int index) {
	T key = data;
	tree_elem_generic<T>* existingElement = search(root, nullnode, key);

	if (existingElement == nullnode) {
		// Ёлемент с данным ключом не существует, создаем новый
		tree_elem_generic<T>* element = new tree_elem_generic<T>;
		element->parent = nullptr;
		element->left = nullnode;
		element->right = nullnode;
		element->color = false;
		element->list = list_init();
		list_insert(element->list, index);
		element->data = key;

		tree_elem_generic<T>* parent_buffer = nullptr;
		tree_elem_generic<T>* runner = root;

		while (runner != nullnode) {
			parent_buffer = runner;
			if (element->data < runner->data) runner = runner->left;
			else runner = runner->right;
		}

		element->parent = parent_buffer;

		if (parent_buffer == nullptr) root = element;
		else if (element->data < parent_buffer->data) parent_buffer->left = element;
		else { parent_buffer->right = element; }

		if (element->parent == nullptr) {
			element->color = true;
			return root;
		}
		if (element->parent->parent == nullptr) return root;
		insert_balance(element, root, nullnode);
	}
	else {
		list_insert(existingElement->list, index);
	}
	return root;
}

template <typename T>
void replace_node(tree_elem_generic<T>*& root, tree_elem_generic<T>* nullnode, tree_elem_generic<T>* n, tree_elem_generic<T>* child) {
	if ((n->parent == nullnode) || (n->parent == nullptr)) root = child;
	else if (n == n->parent->left) n->parent->left = child;
	else n->parent->right = child;
	child->parent = n->parent;
}

template <typename T>
void erase_balance(tree_elem_generic<T>*& root, tree_elem_generic<T>* nullnode, tree_elem_generic<T>* element) {
	tree_elem_generic<T>* brother;
	while ((element != root) && (element->color == 1)) {
		if (element == element->parent->left) {
			brother = element->parent->right;
			if (brother->color == false) {
				brother->color = true;
				element->parent->color = false;
				leftRotate(element->parent, root, nullnode);
				brother = element->parent->right;
			}
			if ((brother->left->color == true) && (brother->right->color == true)) {
				brother->color = false;
				element = element->parent;
			}
			else {
				if (brother->right->color == true) {
					brother->left->color = true;
					brother->color = false;
					rightRotate(brother, root, nullnode);
					brother = element->parent->right;
				}
				brother->color = element->parent->color;
				element->parent->color = true;
				brother->right->color = true;
				leftRotate(element->parent, root, nullnode);
				element = root;
			}
		}
		else {
			brother = element->parent->left;
			if (brother->color == false) {
				brother->color = true;
				element->parent->color = false;
				rightRotate(element->parent, root, nullnode);
				brother = element->parent->left;
			}
			if ((brother->left->color == true) && (brother->right->color == true)) {
				brother->color = false;
				element = element->parent;
			}
			else {
				if (brother->left->color == true) {
					brother->right->color = true;
					brother->color = false;
					leftRotate(brother, root, nullnode);
					brother = element->parent->left;
				}
				brother->color = element->parent->color;
				element->parent->color = true;
				brother->left->color = true;
				rightRotate(element->parent, root, nullnode);
				element = root;
			}
		}
	}
	element->color = true;
}

template <typename T>
tree_elem_generic<T>* left_max(tree_elem_generic<T>* element, tree_elem_generic<T>* nullnode) {
	while (element->right != nullnode) element = element->right;
	return element;
}

template <typename T>
void search_between(tree_elem_generic<T>* root, tree_elem_generic<T>* nullnode, int year1, int year2, list_elem*& result_list) {
	if (root == nullnode) {
		return;
	}
	search_between(root->left, nullnode, year1, year2, result_list);
	if (year1 <= root->data && root->data <= year2) {
		list_elem* temp = root->list;
		do {
			list_insert(result_list, temp->key);
			temp = temp->next;
		} while (temp != root->list);
	}
	search_between(root->right, nullnode, year1, year2, result_list);
}

template <typename T>
tree_elem_generic<T>* erase(tree_elem_generic<T>*& root, tree_elem_generic<T>* nullnode, T data, int number) {
	if (root != nullnode && root != nullptr) {
		T key = data;
		tree_elem_generic<T>* temp = root;
		tree_elem_generic<T>* z = nullnode;
		tree_elem_generic<T>* element;
		tree_elem_generic<T>* y;
		while (temp != nullnode) {
			if (temp->data == key) { z = temp; }
			if ((temp->data == key) || (temp->data < key)) { temp = temp->right; }
			else { temp = temp->left; }
		}
		if (z == nullnode) return root;
		if (z->list->next != z->list) remove(z->list, number);
		else {
			y = z;
			bool y_original_color = y->color;
			if (z->left == nullnode) {
				element = z->right;
				replace_node(root, nullnode, z, z->right);
			}
			else if (z->right == nullnode) {
				element = z->left;
				replace_node(root, nullnode, z, z->left);
			}
			else {
				y = left_max(z->left, nullnode);
				y_original_color = y->color;
				element = y->left;
				if (y->parent == z) {
					element->parent = y;
				}
				else {
					replace_node(root, nullnode, y, y->left);
					y->left = z->left;
					y->left->parent = y;
				}
				replace_node(root, nullnode, z, y);
				y->right = z->right;
				y->right->parent = y;
				y->color = z->color;
			}
			remove(z->list, number);
			delete z;
			if (y_original_color == true) erase_balance(root, nullnode, element);
		}
		return root;
	}
	return nullptr;
}

template <typename T>
void delete_list(tree_elem_generic<T>*& root, tree_elem_generic<T>* nullnode) {
	tree_elem_generic<T>* temp = root;
	if (temp != nullnode && temp != nullptr) {
		while (temp->list->next != temp->list) list_erase(temp->list);
		list_erase(temp->list);
		temp->left = nullptr;
		temp->right = nullptr;
		temp->parent = nullptr;
		temp->list = nullptr;
		delete temp;
		temp = nullptr;
	}
}

template <typename T>
void delete_node(tree_elem_generic<T>*& root, tree_elem_generic<T>* nullnode) {
	if (root->left != nullnode) delete_node(root->left, nullnode);
	if (root->right != nullnode) delete_node(root->right, nullnode);
	delete_list(root, nullnode);
}

template <typename T>
tree_elem_generic<T>* delete_tree(tree_elem_generic<T>*& root, tree_elem_generic<T>* nullnode)
{
	delete_node(root, nullnode);
	root = nullptr;
	return nullnode;
}

template <typename T>
void index_update(tree_elem_generic<T>* root, tree_elem_generic<T>* nullnode, int index, int cur_size) {
	if ((root != nullnode) && (root != nullptr)) {
		index_update(root->right, nullnode, index, cur_size);
		if (root->list != nullptr) {
			if (root->list->prev->key == cur_size) {
				root->list->prev->key = index;
			}
		}
		index_update(root->left, nullnode, index, cur_size);
	}
}

template <typename T>
std::string print(tree_elem_generic<T>* root, tree_elem_generic<T>* nullnode, int h, int ln) {
	if (root != nullnode) {
		std::string result = "";

		if (root->left != nullnode || root->right != nullnode || root->list != nullptr) {
			result += print(root->right, nullnode, h + 4, ln);

			for (int i = 1; i <= h; i++)
				result += ' ';

			std::stringstream ss;
			ss << root->data;
			result += ss.str() + print_list(root->list, root->color);

			for (int i = 0; i < ln; i++)
				result += '\n';

			result += print(root->left, nullnode, h + 4, ln);
		}

		return result;
	}
	else {
		return "";
	}
}
