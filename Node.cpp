#include <string>
#include "Node.h"

template <typename T>
Node<T>::Node(std::string k, T v) {
  value = v;
  leftChild = 0;
  rightChild = 0;
  balance = 0;
  key = k;
}

template <typename T>
T Node<T>::getValue() {
  return value;
}

template <typename T>
Node<T>*& Node<T>::getLeftChild() {
  return leftChild;
}

template <typename T>
void Node<T>::setLeftChild(Node<T>& lc) {
  leftChild = &lc;
}

template <typename T>
Node<T>*& Node<T>::getRightChild() {
  return rightChild;
}

template <typename T>
void Node<T>::setRightChild(Node<T>& rc) {
  rightChild = &rc;
}

template <typename T>
int Node<T>::getBalance(){
	return balance;
}

template <typename T>
void Node<T>::setBalance(int n){
	balance = n; 
}

template <typename T>
std::string Node<T>::getKey(){
	return key;
}

template <typename T>
std::vector<Node<T>* > Node<T>::nodeList(){
	return nodes;
}

template <typename T>
void Node<T>::append(Node<T>* n){
	nodes.push_back(n);
}

template class Node<int>;
template class Node<double>;
template class Node<std::string>;

