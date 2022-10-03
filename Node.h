#include <iostream>
#include <string>
using namespace std;
class Node {
public:
  char value;
  string color;
  Node* next;
  Node(char value) {
    this->value = value;
    this->next = NULL;
    this->color = "default";
  }
};
