#include "binary-search-tree.h"
#include <iostream>
#include <queue>

typedef BinarySearchTree::DataType DataType;
typedef BinarySearchTree::Node Node;

using namespace std;


BinarySearchTree::Node::Node(DataType newval)
{
    val = newval;
    left = NULL;
    right = NULL;
}


// Optional function
int BinarySearchTree::getNodeDepth(Node* n) const
{}


BinarySearchTree::BinarySearchTree()
{
    root_ = NULL;
    size_ = 0;
}


BinarySearchTree::~BinarySearchTree()
{
    delete root_;
}


unsigned int BinarySearchTree::size() const
{
    return size_;
}


DataType BinarySearchTree::max() const
{
    Node* current = root_;

    // If root is the only node in BST
    if(current == NULL)
    {
        return root_->val;
    }

    // Traverse until largest value is found
    while(current->right != NULL)
    {
        current = current->right;
    }

    return current->val;
}


DataType BinarySearchTree::min() const
{
    Node* current = root_;

    // Traverse until smallest value is found
    while(current->left != NULL)
    {
        current = current->left;
    }

    return current->val;
}

// Use queue to find BST depth non-recursively
unsigned int BinarySearchTree::depth() const
{
    int depth = 0;

    if(size() == 1)
    {
        return depth;
    }
    else
    {
        queue<Node*> nodes;

        nodes.push(root_);
        int numNodes = 0;

        while(nodes.size() != 0)
        {
            numNodes = nodes.size();

            // Repeats for every node a row
            for(int count = 0; count < numNodes; count++)
            {
                Node* current = nodes.front();

                if(current->left == NULL && current->right == NULL)
                {
                    break;
                }
                else if(current->left != NULL)
                {
                    nodes.push(current->left);
                }
                else if(current->right != NULL)
                {
                    nodes.push(current->right);
                }
            }

            nodes.pop();

            depth++;
        }

        return depth-1;
    }
}

// Optional function
void BinarySearchTree::print() const
{}


bool BinarySearchTree::exists(DataType val) const
{
    Node* current = root_;

    // Repeats until node is found
    while(current != NULL)
    {
        if(val == current->val)
        {
            return true;
        }
        else if(val > current->val)
        {
            current = current->right;
        }
        else if(val < current->val)
        {
            current = current->left;
        }
    }

    return false;
}


Node* BinarySearchTree::getRootNode()
{
    return root_;
}


Node** BinarySearchTree::getRootNodeAddress()
{
    return &root_;
}


bool BinarySearchTree::insert(DataType val)
{
    // Cannot add a value that already exists
    if(exists(val) == true)
    {
        return false;
    }
    // Create root node if BST is empty
    else if(root_ == NULL && size_ == 0)
    {
        root_ = new Node(val);
    }
    else
    {
        Node* current = root_;

        while(current != NULL)
        {
            if(val < current->val)
            {
                if(current->left == NULL)
                {
                    current->left = new Node(val);
                    break;
                }

                current = current->left;
            }
            else if(val > current->val)
            {
                if(current->right == NULL)
                {
                    current->right = new Node(val);
                    break;
                }

                current = current->right;
            }
        }
    }

    size_++;

    return true;
}

// Optional function
Node *BinarySearchTree::findPredecessor(Node *ptr)
{}


bool BinarySearchTree::remove(DataType val)
{
    // Cannot remove a node that does not exist
    if(exists(val) == false || root_ == NULL)
    {
        return false;
    }
    else
    {
        Node* current = root_;
        Node* parent = NULL;

        while(current->val != val)
        {
            parent = current;

            if(val < current->val)
            {
                current = current->left;
            }
            else if(val > current->val)
            {
                current = current->right;
            }
        }

        // Case 1: delete leaf node
        if(current->right == NULL && current->left == NULL)
        {
            if(current == root_)
            {
                root_ = NULL;
                delete root_;

                size_--;

                return true;
            }

            delete current;

            if(parent->left != NULL)
            {
                parent->left = NULL;
            }
            else if(parent->right != NULL)
            {
                parent->right = NULL;
            }

            size_--;

            return true;
        }
        // Case 2: delete node with 1 child
        else if(current->right == NULL || current->left == NULL)
        {
            if(current->right != NULL)
            {
                if(parent->left == current)
                {
                    parent->left = current->right;
                }
                else
                {
                    parent->right = current->right;
                }
            }
            else if(current->left != NULL)
            {
                if(parent->left == current)
                {
                    parent->left = current->left;
                }
                else
                {
                    parent->right = current->left;
                }
            }

            delete current;

            size_--;

            return true;
        }
        // Case 3: delete node with 2 children
        else
        {
            Node* predecessor = current->left;
            parent = current;

            while(predecessor->right != NULL)
            {
                parent = predecessor;
                predecessor = predecessor->right;
            }

            if(parent->val == val)
            {
                parent->val = predecessor->val;
                parent->left = predecessor->right;
                predecessor = NULL;
            }
            else
            {
                parent->right = predecessor->left;
                current->val = predecessor->val;

                predecessor = NULL;
                parent = NULL;
            }

            delete predecessor;

            size_--;

            return true;
        }
    }
}