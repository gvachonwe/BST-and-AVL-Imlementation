#include "avl-tree.h";
#include <stack>

using namespace std;

typedef BinarySearchTree::DataType DataType;
typedef BinarySearchTree::Node Node;

// check height of the node
int AVLTree::depthBelow(Node *n)
{}


// Helper function created to compute the balance factor
int AVLTree::findBF(Node *n)
{}


bool AVLTree::singleLeftRotation(Node *parentNode, bool isLeftChild)
{}


bool AVLTree::singleRightRotation(Node *parentNode, bool isLeftChild)
{}


bool AVLTree::leftRightRotation(Node *parentNode, bool isLeftChild)
{}


bool AVLTree::rightLeftRotation(Node *parentNode, bool isLeftChild)
{}


std::stack<BinarySearchTree::Node*> *AVLTree::pathToNodeStack(DataType val)
{}


bool AVLTree::updateNodeBalance(std::stack<BinarySearchTree::Node*> *pathToNode, DataType val)
{}


bool AVLTree::insert(DataType val)
{}


bool AVLTree::remove(DataType val)
{}