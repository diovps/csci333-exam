#ifndef __BST_H__
#define __BST_H__

#include "Node.h"
#include <string>

template <typename T>
class BST {
 private:
  Node<T>* root;
  void traversalPrint(Node<T>* root);
  Node<T>* findOutsourced(Node<T>* head,T v);

 public:
  BST<T>();
  ~BST<T>();
  
  void treePrint(); 
  bool find(T v);
  void remove(T v);
  void insert(std::string k,T v);
  void print();
};


#endif
