#include "intbst.h"
#include <iostream>

using namespace std;

int main()
{

    IntBST bst1;

    // insert data to bst1
    bst1.insert(4);
    bst1.insert(8);
    bst1.insert(3);
    bst1.insert(5);
    bst1.insert(7);
    bst1.insert(9);
    bst1.insert(1);
    bst1.insert(216);
    bst1.insert(21);
    bst1.insert(420);
    bst1.insert(69);

    // print and test methods for bst1
    cout << "BST: " << endl
         << "  pre-order: ";
    bst1.printPreOrder();
    cout << endl;
    cout << "  in-order: ";
    bst1.printInOrder();
    cout << endl;

    cout << "  post-order: ";
    bst1.printPostOrder();
    cout << endl;

    cout << "  sum: " << bst1.sum() << endl;
    cout << "  count: " << bst1.count() << endl;
    cout << "  contains 420? " << (bst1.contains(420) ? "Y" : "N") << endl;
    cout << "  contains 4? " << (bst1.contains(4) ? "Y" : "N") << endl;
    cout << "  contains 21? " << (bst1.contains(21) ? "Y" : "N") << endl;
    cout << "  contains 69? " << (bst1.contains(69) ? "Y" : "N") << endl;
    cout << "  contains 9? " << (bst1.contains(9) ? "Y" : "N") << endl;
    cout << "  contains 11? " << (bst1.contains(11) ? "Y" : "N") << endl;

    cout << "  predecessor of 420 is: " << bst1.getPredecessor(420) << endl;
    cout << "  predecessor of 21 is: " << bst1.getPredecessor(21) << endl;
    cout << "  predecessor of 4 is: " << bst1.getPredecessor(4) << endl;
    cout << "  successor of 64 is: " << bst1.getSuccessor(64) << endl;
    cout << "  successor of 512 is: " << bst1.getSuccessor(512) << endl;
    cout << "  successor of 11 is: " << bst1.getSuccessor(11) << endl;

    cout << "  removing 11" << endl;
    bst1.remove(11);
    cout << "  removing 420" << endl;
    bst1.remove(420);
    cout << "  removing 128" << endl;
    bst1.remove(128);
    cout << "  contains 420? " << (bst1.contains(420) ? "Y" : "N") << endl;
    cout << "  contains 11? " << (bst1.contains(4) ? "Y" : "N") << endl;
    cout << "  contains 69? " << (bst1.contains(69) ? "Y" : "N") << endl;
    cout << "  contains 21? " << (bst1.contains(21) ? "Y" : "N") << endl;
    cout << "  contains 17? " << (bst1.contains(17) ? "Y" : "N") << endl;
    cout << "  contains 9 " << (bst1.contains(9) ? "Y" : "N") << endl;
    cout << "  pre-order: ";
    bst1.printPreOrder();
    cout << endl;

    return 0;
}