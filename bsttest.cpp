#include <iostream>
#include "BST.h"

int main(){
	
	BST<int>* h = new BST<int>();
	h->insert("Hello",2);
	h->insert("wtf",5);
	h->print();
	
	return 0;
}
