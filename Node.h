#pragma once
#include <iostream>
#include <string>
using namespace std;
class Node {
public:
  char value;
  Node *next;
  Node(char value) {
    this->value = value;
    this->next = NULL;
  }
};
