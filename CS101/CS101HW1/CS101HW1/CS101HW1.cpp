#include <iostream>
#include <ctime>
#include <iomanip>
#include "bits/stdc++.h"

using namespace std;
#define DEBUG

class AVLTree {

private:
	class Node {


	public:
		int data;
		int height;
		int leftSize = 0, RightSize = 0;
		int spys = 1;

		Node* left_child;
		Node* parent;
		Node* right_child;
		// Constructor initializing the data.
		Node(int val);
		// Calculate the balance point.
		int getBalance();

		// Get the height.
		int getHeight();

		// Set the left subtree.
		Node* setLeftChild(Node* newLeft);
		// Set the right subtree.
		Node* setRightChild(Node* newRight);
		// Set the node's height.
		int updateHeight();
	}; // Node

	// A pointer to the top node of the tree.
	Node* root;

	// Balance the subtree.
	void balanceAtNode(Node* n)
	{
		// Get the current balance and if it is bad
	// enough on the left side, rotate it right
	// adjusting the subtree left, if required.
		int bal = n->getBalance();
		if (bal > 1) {
			if (n->left_child->getBalance() < 0)
				rotateLeft(n->left_child);
			rotateRight(n);

			// Otherwise, if the balance is bad enough on
			// the right side, rotate it left adjusting the
			// subtree right, if required.
		}
		else if (bal < -1) {
			if (n->right_child->getBalance() > 0)
				rotateRight(n->right_child);
			rotateLeft(n);
		} // if
	};
	// Find the node containing the data.
	Node* findNode(int val);
	// Print the subtree.
	void printSubtree(Node* subtree, int depth,
		int offset, bool first);
	// Rotate the subtree left.
	void rotateLeft(Node* n);
	// Rotate the subtree left.
	void rotateRight(Node* n);
	// Set the root.
	void setRoot(Node* n);
	// Figure out the default spacing for element.
	int spacing(int offset);

	// - - - - - - - - - - - - - - - - - - - - - - - -
	// Public methods to process the tree.
public:
	// Constructor to create an empty tree.
	AVLTree();
	// Constructor to populate the tree with one node.
	AVLTree(int val);
	// Get the tree's height.
	int getHeight();
	// Insert the value into the tree.
	void insert(int val)
	{
		if (root == nullptr)
		{
			root = new Node(val);
			return;
		}

		else {
			//找插入点
			Node* pivot = findNode(val);
			if (pivot->data == val)pivot->spys++;
			if (val < pivot->data)
			{
				pivot->left_child = new Node(val);
				pivot->left_child->parent = pivot;
				pivot = pivot->left_child;
			}
			if (val > pivot->data)
			{
				pivot->right_child = new Node(val);
				pivot->right_child->parent = pivot;

				pivot = pivot->right_child;

			}

			//往上维护AVL
			Node* temp = pivot->parent;
			//temp = added_node;
			while (temp != nullptr) {
				temp->updateHeight();
				balanceAtNode(temp);
				temp = temp->parent;
			} // while
		} // if
	};
	// Print the tree.
	void print();
	// Remove the value from the tree.
	bool remove(int val);
}; // AVLTree

// **************************************************
// AVLTree's Node subclass methods.

// --------------------------------------------------
// Constructor initializing the data.
AVLTree::Node::Node(int val) {
	data = val;
	height = 0;
	parent = nullptr;
	left_child = nullptr;
	right_child = nullptr;
} // Node

// --------------------------------------------------
// Calculate the balance point. Negative, when the
// right side is deeper. Zero, when both sides are
// the same. Positive, when the left side is deeper.
int AVLTree::Node::getBalance() {

	// If we don't have a left subtree, check the
	// right.
	int result;
	if (left_child == nullptr)

		// If neither subtree exists, return zero.
		if (right_child == nullptr)
			result = 0;

	// Otherwise, the right subtree exists so make
	// it's height negative and subtract one.
		else
			result = -right_child->height - 1;

	// Otherwise, we have a left subtree so if we
	// don't have a right one, return the left's
	// height plus one.
	else if (right_child == nullptr)
		result = left_child->height + 1;

	// Otherwise, both subtrees exist so subtract
	// them to return the difference.
	else
		result = left_child->height - right_child->height;
	return result;
} // getBalance



// --------------------------------------------------
// Get the height.
int AVLTree::Node::getHeight() {
	return height;
} // getHeight









// --------------------------------------------------
// Set the left subtree.
AVLTree::Node* AVLTree::Node::setLeftChild(
	Node* newLeft) {

	// If there is a left node, set it's parent to
	// be us. In any event, make it our left subtree
	// and update the height.
	if (newLeft != nullptr)
		newLeft->parent = this;
	left_child = newLeft;
	updateHeight();
	return left_child;
} // setLeftChild

// --------------------------------------------------
// Set the right subtree.
AVLTree::Node* AVLTree::Node::setRightChild(
	Node* newRight) {

	// If there is a right node, set it's parent to
	// be us. In any event, make it our right subtree
	// and update the height.
	if (newRight != nullptr)
		newRight->parent = this;
	right_child = newRight;
	updateHeight();
	return right_child;
} // setRightChild

// --------------------------------------------------
// Set the node's height.
int AVLTree::Node::updateHeight() {

	// If we don't have a left subtree, check the
	// right.
	if (left_child == nullptr)

		// If we don't have either subtree, the height
		// is zero.
		if (right_child == nullptr)
			height = 0;

	// Otherwise, we only have the right subtree so
	// our height is one more than it's height.
		else
			height = right_child->height + 1;

	// Otherwise, the left subtree exists so if we
	// don't have a right one, our height is one
	// more than it's height.
	else if (right_child == nullptr)
		height = left_child->height + 1;

	// Otherwise, we have both subtree's so if the
	// left's height is greater than the right, our
	// height is one more than it.
	else if (left_child->height > right_child->height)
		height = left_child->height + 1;

	// Otherwise, the right subtree's height will be
	// used so our height is one more than it.
	else
		height = right_child->height + 1;
	return height;
} // updateHeight

// **************************************************
// AVLTree class methods.

// --------------------------------------------------
// Constructor to create an empty tree.
AVLTree::AVLTree() {
	root = nullptr;
} // AVLTree

// --------------------------------------------------
// Constructor to populate the tree with one node.
AVLTree::AVLTree(int val) {
	root = new Node(val);
} // AVLTree


//找点，找到了就返回本身，找不到就返回最后一个
AVLTree::Node* AVLTree::findNode(int val) {
	Node* pivot = root;

Refind:
	if (pivot->data == val)return pivot;
	if (val < pivot->data)
	{
		if (pivot->left_child == nullptr)return pivot;
		pivot = pivot->left_child;
		goto Refind;
	}
	else
	{
		if (pivot->right_child == 0)return pivot;
		pivot = pivot->right_child;
		goto Refind;
	}
	// While nodes remain, if we found the right
	// node, exit the loop. If the value we want
	// is less than the current, check the left
	// subtree, otherwise, the right.
	Node* temp = root;
	while (temp != nullptr) {
		if (val == temp->data)
			break;
		else if (val < temp->data)
			temp = temp->left_child;
		else
			temp = temp->right_child;
	} // while
	return temp;
} // findNode

// --------------------------------------------------
// Get the tree's height.
int AVLTree::getHeight() {
	return root->getHeight();
} // getHeight


void AVLTree::print() {

	if (root->getHeight() > 10)
		std::cout << "Not currently supported!" <<
		std::endl;

	// Otherwise, set up to display the tree. Get
	// the maximum depth and for each possible
	// level, output that level's elements and
	// finish off the line.
	else {
		int max = root->getHeight();
		for (int depth = 0; depth <= max; depth++) {
			printSubtree(root, depth, max - depth + 1, true);
			std::cout << std::endl;
		} // for
	} // if
} // print

// --------------------------------------------------
// Print the subtree.  The leftmost branch will have
// first true. The level counts up from the bottom
// for the line we are doing. The depth is how
// many layers to skip over.
void AVLTree::printSubtree(Node* subtree, int depth,
	int level, bool first) {

	// If we need to go deeper in the subtree, do so.
	// If the subtree is empty, pass it down, otherwise
	// pass both left and right subtrees.
	if (depth > 0) {
		if (subtree == nullptr) {
			printSubtree(subtree, depth - 1, level, first);
			printSubtree(subtree, depth - 1, level, false);
		}
		else {
			printSubtree(subtree->left_child, depth - 1,
				level, first);
			printSubtree(subtree->right_child, depth - 1,
				level, false);
		} // if

	  // Otherwise, if the subtree is empty, display
	  // an empty element. The leftmost element only
	  // needs half the spacing.
	}
	else if (subtree == nullptr)
		std::cout << std::setw((first) ?
			spacing(level) / 2 : spacing(level)) << "-";

	// Otherwise, we have a live element so display
	// it. Once more, use half spacing for the
	// leftmost element.
	else
		std::cout << std::setw((first) ?
			spacing(level)/2 : spacing(level)) <<
		subtree->data;
} // printSubtree

// --------------------------------------------------
// Remove the value from the tree.
// Returns:
//		 true: If removal is successful
//		 false: If item is not found in the tree
//
bool AVLTree::remove(int val) {

	// Find the node to delete and if none, exit.
	Node* toBeRemoved = findNode(val);
	if (toBeRemoved == nullptr)
		return false;

	// Get the parent and set the side the node is
	// on of the parent.
	enum { left, right } side;
	Node* p = toBeRemoved->parent;
	if (p != nullptr &&
		p->left_child == toBeRemoved)
		side = left;
	else
		side = right;

	// If the node to be removed doesn't have a left
	// subtree, check it's right subtree to figure
	// out our next move.
	if (toBeRemoved->left_child == nullptr)

		// If we don't have any subtrees, we are the
		// leaf so our parent doesn't need us.
		if (toBeRemoved->right_child == nullptr) {

			// If we don't have a parent, the tree is now
			// empty so change the root to null and delete
			// our node.
			if (p == nullptr) {
				setRoot(nullptr);
				delete toBeRemoved;

				// Otherwise, change the parent so it doesn't
				// point to us, delete ourself, update the
				// parent's height, and rebalance the tree.
			}
			else {
				if (side == left)
					p->setLeftChild(nullptr);
				else
					p->setRightChild(nullptr);
				delete toBeRemoved;
				p->updateHeight();
				balanceAtNode(p);
			} // if

		  // Otherwise, there is a right subtree so use
		  // it to replace ourself.
		}
		else {

			// If we don't have a parent, the tree is now
			// the right subtree and delete our node.
			if (p == nullptr) {
				setRoot(toBeRemoved->right_child);
				delete toBeRemoved;

				// Otherwise, change the parent so it doesn't
				// point to us, delete ourself, update the
				// parent's height, and rebalance the tree.
			}
			else {
				if (side == left)
					p->setLeftChild(toBeRemoved->
						right_child);
				else
					p->setRightChild(toBeRemoved->
						right_child);
				delete toBeRemoved;
				p->updateHeight();
				balanceAtNode(p);
			} // if
		} // if

	  // Otherwise, we have a left subtree so check the
	  // right one of the node being removed to decide
	  // what is next. If there isn't a right subtree,
	  // the left one will replace ourself.
	else if (toBeRemoved->right_child ==
		nullptr) {

		// If we don't have a parent, the tree is now
		// the left subtree and delete our node.
		if (p == nullptr) {
			setRoot(toBeRemoved->left_child);
			delete toBeRemoved;

			// Otherwise, change the parent so it doesn't
			// point to us, delete ourself, update the
			// parent's height, and rebalance the tree.
		}
		else {
			if (side == left)
				p->setLeftChild(toBeRemoved->
					left_child);
			else
				p->setRightChild(toBeRemoved->
					left_child);
			delete toBeRemoved;
			p->updateHeight();
			balanceAtNode(p);
		} // if

	  // Otherwise, the node to remove has both subtrees
	  // so decide the best method to remove it.
	}
	else {

		// Check the balance to see which way to go.
		// If the left side is deeper, modify it.
		Node* replacement;
		Node* replacement_parent;
		Node* temp_node;
		int bal = toBeRemoved->getBalance();
		if (bal > 0) {

			// If the right subtree of the node's
			// left subtree is empty, we can move the
			// node's right subtree there.
			if (toBeRemoved->left_child->
				right_child == nullptr) {
				replacement = toBeRemoved->left_child;
				replacement->setRightChild(
					toBeRemoved->right_child);
				temp_node = replacement;

				// Otherwise, find the right most empty subtree
				// of our node's left subtree and it's
				// parent. This is our replacement. Make it's
				// parent point to it's left child instead
				// of itself. It is now free to replace the
				// deleted node. Copy both of the deleted
				// nodes subtrees into the replacement leaving
				// fixing up the parent below.
			}
			else {
				replacement = toBeRemoved->
					left_child->right_child;
				while (replacement->right_child !=
					nullptr)
					replacement = replacement->right_child;
				replacement_parent = replacement->parent;
				replacement_parent->setRightChild(
					replacement->left_child);
				temp_node = replacement_parent;
				replacement->setLeftChild(
					toBeRemoved->left_child);
				replacement->setRightChild(
					toBeRemoved->right_child);
			} // if

		  // Otherwise, we are going to modify the right
		  // side so, if the left subtree of the node's
		  // right subtree is empty, we can move the
		  // node's left subtree there.
		}
		else if (toBeRemoved->right_child->
			left_child == nullptr) {
			replacement = toBeRemoved->right_child;
			replacement->setLeftChild(
				toBeRemoved->left_child);
			temp_node = replacement;

			// Otherwise, find the left most empty subtree
			// of our node's right subtree and it's
			// parent. This is our replacement. Make it's
			// parent point to it's right child instead
			// of itself. It is now free to replace the
			// deleted node. Copy both of the deleted
			// nodes subtrees into the replacement leaving
			// fixing up the parent below.
		}
		else {
			replacement = toBeRemoved->
				right_child->left_child;
			while (replacement->left_child !=
				nullptr)
				replacement = replacement->left_child;
			replacement_parent = replacement->parent;
			replacement_parent->setLeftChild(
				replacement->right_child);
			temp_node = replacement_parent;
			replacement->setLeftChild(
				toBeRemoved->left_child);
			replacement->setRightChild(
				toBeRemoved->right_child);
		} // if

		// Fix the parent to point to the new root.
		// If there isn't a parent, update the actual
		// tree root. Otherwise, there is a parent so
		// if we were the left subtree, update it,
		// otherwise, the right. In all cases, delete
		// the node and rebalance the tree.
		if (p == nullptr)
			setRoot(replacement);
		else if (side == left)
			p->setLeftChild(replacement);
		else
			p->setRightChild(replacement);
		delete toBeRemoved;
		balanceAtNode(temp_node);
	} // if
	return true;
} // remove

// --------------------------------------------------
// Rotate the subtree left.
void AVLTree::rotateLeft(Node* n) {

	// Get the node's parent and if it exists and the
	// node was it's left subtree, remember we are
	// processing the left, otherwise, the right.
	enum { left, right } side;
	Node* p = n->parent;
	if (p != nullptr && p->left_child == n)
		side = left;
	else
		side = right;

	// Get the node's right subtree as the new root
	// and that subtree's left subtree. Make that
	// left subtree the node's new right. Put our
	// original node as the left subtree of our
	// new root.
	Node* temp = n->right_child;
	n->setRightChild(temp->left_child);
	temp->setLeftChild(n);

	// Fix the original parent to point to the new
	// root. If there isn't a parent, update the
	// actual tree root. Otherwise, there is a
	// parent so if we were the left subtree, update
	// it, otherwise, the right.
	if (p == nullptr)
		setRoot(temp);
	else if (side == left)
		p->setLeftChild(temp);
	else
		p->setRightChild(temp);
} // rotateLeft

// --------------------------------------------------
// Rotate the subtree left.
void AVLTree::rotateRight(Node* n) {

	// Get the node's parent and if it exists and the
	// node was it's left subtree, remember we are
	// processing the left, otherwise, the right.
	enum { left, right } side;
	Node* p = n->parent;
	if (p != nullptr && p->left_child == n)
		side = left;
	else
		side = right;

	// Get the node's left subtree as the new root
	// and that subtree's right subtree. Make that
	// right subtree the node's new left. Put our
	// original node as the right subtree of our
	// new root.
	Node* temp = n->left_child;
	n->setLeftChild(temp->right_child);
	temp->setRightChild(n);

	// Fix the original parent to point to the new
	// root. If there isn't a parent, update the
	// actual tree root. Otherwise, there is a
	// parent so if we were the left subtree, update
	// it, otherwise, the right.
	if (p == nullptr)
		setRoot(temp);
	else if (side == left)
		p->setLeftChild(temp);
	else
		p->setRightChild(temp);
} // rotateRight

// --------------------------------------------------
// Set the root. Change the tree root to the node
// and if it exists, remove it's parent.
void AVLTree::setRoot(Node* n) {
	root = n;
	if (root != nullptr)
		root->parent=nullptr;
} // setRoot

// --------------------------------------------------
// Figure out the default spacing for element. Each
// higher level doubles the preceeding. The bottom
// level is one.
int AVLTree::spacing(int level) {
	int result = 6;
	for (int i = 0; i < level; i++)
		result += result;
	return result;
} // spacing

#pragma region Given
/* PLEASE DO NOT CHANGE BELOW*/
int A, B, C, lfsr;
double P[4][4];
int lfsr_generator() {
	auto ret = lfsr;
	return (lfsr ^= lfsr << 13, lfsr ^= lfsr >> 17, lfsr ^= lfsr << 5, ret);
}
tuple<int, int> command() {
	auto imm = lfsr_generator();
	static int state = 0;
	auto p = double(lfsr_generator() & 0x7fffffff) / INT32_MAX;
	for (int i = 0; i < 4; i++)
		if ((p -= P[state % 4][i]) < 0) {
			state += 4 - state % 4 + i;
			break;
		}
	return tuple<int, int>(state % 4, (imm * A + state * B + C) & 0x7fffffff);
}
///* PLEASE DO NOT CHANGE ABOVE*/
#pragma endregion


int main() {
	AVLTree tree;

	int m;

#ifndef DEBUG
	cin >> m >> lfsr >> A >> B >> C;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) cin >> P[i][j];
#endif // !DEBUG
#ifdef DEBUG
	m = 10;lfsr = 123;A = 1;B = 2;C = 3;
	P[0][0] = P[0][1] = P[0][2] = P[0][3] = .25;
	P[1][0] = 1;P[1][1] = P[1][2] = P[1][3] = 0;
	P[2][0] = 1;P[2][1] = P[2][2] = P[2][3] = 0;
	P[3][0] = 1;P[3][1] = P[3][2] = P[3][3] = 0;
	//tree.insert(75);
	//tree.insert(72);
	//tree.insert(81);
	//tree.insert(78);
	//tree.insert(84);
	//tree.insert(77);
	//tree.print();
	//cout << tree.rank(75)<<endl;
	//cout << tree.rank(72)<<endl;
	//cout << tree.rank(81)<<endl;
	//cout << tree.rank(78)<<endl;
	//cout << tree.rank(84)<<endl;
	//cout << tree.rank(77)<<endl;
#endif // DEBUG
    int tans = 0;
	for (int i = 1; i <= m; i++)
	{
		int op, imm;
		tie(op, imm) = command();
		if (op == 0)
		{
			tree.insert(imm);
			tree.print();
			cout << "==================" << endl;
		}
		//     if (op == 1)
		//     {
		//         //auto re = tree.kth(imm % tree.size());
				 //int re = 0;
		//         tree.remove(re);
		//     }
	   //      if (op == 2)
	   //          tans ^= tree.rank(imm);
	   //      if (op == 3)
	   //      {
	   //          auto  re = imm % tree.size();
	   //          tans ^= tree.kth(re);
	   //      }
	   //  }
	   //  cout << tans << "\n";
	}
}