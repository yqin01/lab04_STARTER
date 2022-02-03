// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() : root(0) {}

// destructor deletes all nodes
IntBST::~IntBST()
{
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n)
{
    if (n)
    {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value)
{
    // handle special case of empty tree first
    if (!root)
    {
        root = new Node(value);
        return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n)
{
    if (value == n->info)
        return false;
    if (value < n->info)
    {
        if (n->left)
            return insert(value, n->left);
        else
        {
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
    }
    else
    {
        if (n->right)
            return insert(value, n->right);
        else
        {
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const
{
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const
{
    if (n)
    {
        cout << n->info << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const
{
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const
{
    // IMPLEMENT HERE
    if (!n)
    {
        return;
    }
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const
{
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const
{
    // IMPLEMENT HERE
    if (!n)
    {
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
}

// return sum of values in tree
int IntBST::sum() const
{
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const
{
    if (!n)
    {
        return 0;
    }
    return (n->info + sum(n->left) + sum(n->right)); // REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const
{
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const
{
    int x = 0;
    if (!n)
    {
        return 0;
    }

    x++;

    x += (count(n->left) + count(n->right));

    return x;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node *IntBST::getNodeFor(int value, Node *n) const
{
    if (n)
    {
        if (n->info == value)
        {
            return n;
        }
        else
        {
            Node *temp = getNodeFor(value, n->left);
            if (!temp)
            {
                temp = getNodeFor(value, n->right);
            }
            return temp;
        }
    }
    else
    {
        return NULL;
    }
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const
{
    return getNodeFor(value, root);
}

// returns the Node containing the predecessor of the given value
IntBST::Node *IntBST::getPredecessorNode(int value) const
{
    Node *n = getNodeFor(value, root);
    if (!n)
        return nullptr;
    else if(n->left) {
        Node* result = n->left;
        while(result->right) 
            result = result->right;
        return result;
    }
    else if(n->parent && n->parent->right == n)
        return n->parent;
        
    else if(n->parent && n->parent->left == n) {
        Node* result = n->parent->parent;
        
        if(result && result->info >= value)
            result = nullptr;
        return result;

    }
    
    return nullptr; 
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const
{
    Node* n = getPredecessorNode(value);
    
    if(n)
        return n->info;
    return 0;

}

// returns the Node containing the successor of the given value
IntBST::Node *IntBST::getSuccessorNode(int value) const
{
    Node *n = getNodeFor(value,root); 
    if(!n)
    {
        return nullptr;
    }
    else
    if(n->right)
    {
        Node*result = n->right;
        
        while(result->left)
        {
            result=result->left; 
        }
        return result;  
    }
   else if(n->parent && n->parent->left == n)
        return n->parent;
    else if(n->parent && n->parent->right == n) {
        Node* result = n->parent->parent;
        
        if(result && result->info <=value)
            result = nullptr;
        return result;
    }
    
    return nullptr; 
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const
{
    Node* n=getSuccessorNode(value);
    if(n)
    {
        return n->info;
    } 
    return 0;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value)
{
    
    if(contains(value))
    {
        Node* n = getNodeFor(value,root);
        if(n->parent && n->parent->left == n)
            n->parent->left = nullptr;
        else if(n->parent && n->parent->right == n)
            n->parent->right = nullptr;
        else {
            if(left) 
            {
                root = n->left;
                n->left = nullptr;
            }
            else if(right) 
            {
                root = n->right;    
                n->right = nullptr;
            }                            
        }
        removeHelper(n->left);
        removeHelper(n->right);
        delete n;
        return true;
    }
    return false; 
}

void IntBST::removeHelper(Node* n) 
{
    if (n)
    {
        insert(n->info);
        removeHelper(n->left);
        removeHelper(n->right);
        delete n;
    }
}