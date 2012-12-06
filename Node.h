#ifndef __NODE_H__
#define __NODE_H__

#include <string>
#include <vector>

template <typename T>
class Node {
 private:
  T value;
  Node<T>* leftChild;
  Node<T>* rightChild;
  int balance;
  std::string key;
  std::vector<Node<T>*> nodes;

 public:
  Node<T>(std::string k, T v);
  T getValue();
  std::string getKey();

  void setBalance(int n);
  int getBalance();

  Node<T>*& getLeftChild();
  void setLeftChild(Node<T>& n);
  
  Node<T>*& getRightChild();
  void setRightChild(Node<T>& n);

  std::vector<Node<T>*> nodeList();
  void append(Node<T>* n);
};
#endif
