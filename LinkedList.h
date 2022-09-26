#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class LinkedList {
public:
  Node* head = NULL;
  void add_at_head(char value); 
  void traverse(); 
};
