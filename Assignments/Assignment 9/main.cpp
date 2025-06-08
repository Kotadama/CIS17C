// This program builds a binary tree with 5 nodes.
// The nodes are displayed with inorder, preorder, 
// and postorder algorithms.

//DO NOT MODIFY THIS FILE!!!

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
  
  BinaryTree tree;
  cout << "Inserting the numbers 5 8 3 12 9.\n\n";
  tree.insert(5);
  tree.insert(8);
  tree.insert(3);
  tree.insert(12);
  tree.insert(9);
  tree.insert(3);

  cout << "Inorder traversal:  ";
  tree.showInOrder();   //Displays 3 5 8 9 12
	
  cout << "\n\nPreorder traversal:  ";
  tree.showPreOrder();  //Displays 5 3 8 12 9
	
  cout << "\n\nPostorder traversal:  ";
  tree.showPostOrder(); //Displays 3 9 12 8 5
  
  cout << "\nSearching for 12\n";  //12 is in the tree
  if(tree.search(12))
    cout << "12 is in the tree." << endl;
  else
    cout << "12 is not in the tree" << endl;

  cout << "\nSearching for 4\n";  //4 is not in the tree
  if(tree.search(4))
    cout << "4 is in the tree." << endl;
  else
    cout << "4 is not in the tree" << endl;
  
  cout << "\nDeleting 8...\n";
  tree.remove(8);
    	 
  cout << "Deleting 12...\n";
  tree.remove(12); 
    
  cout << "Now, here are the nodes:\n";
  tree.showInOrder();  //Displays 3 5 9

  cout << "Now I am destroying the entire tree\n";
  tree.~BinaryTree();
  cout << "See...I am still running\n";

  return 0;
}