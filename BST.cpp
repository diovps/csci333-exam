#include "BST.h"
#include <iostream>
#include <list>
#include <vector>
#include <iomanip>
#include <math.h>

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
  
  Node<T>* goal = findOutsourced(root,v);
  
  if(goal!=0)
  	return goal->getValue()==v;
  return false;
}

template <typename T>
Node<T>* BST<T>::findOutsourced(Node<T>* head, T v){
	
	if(head == 0) return head;

	if(head->getValue()<v){
		return findOutsourced(head->getRightChild(),v);
	}else if(head->getValue()>v){
		return findOutsourced(head->getLeftChild(),v);
	}else{
		return head;
	}
}

template <typename T>
void BST<T>::insert(std::string k,T v) {
  Node<T>* temp = new Node<T>(k,v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }else if(v==(*curr)->getValue()){
      (*curr)->append(temp);
      return;
    }
  }
  *curr = temp;
}


template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::vector<Node<T>* > nodes = root->nodeList();
    
    for(int i = 0; i < (int)nodes.size(); i++){
	std::cout << nodes[i]->getKey() << " " << nodes[i]->getValue()
		<< std::endl;
    }
    std::cout << root->getKey() << " " << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
