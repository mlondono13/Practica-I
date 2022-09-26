#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedList.h"
using namespace std;
void LinkedList:: add_at_head(char value) {
    Node* new_node = new Node(value); 
    if(this->head == NULL)
    {
      this->head = new_node;
    }
    else
    {
      Node* aux_node = this->head;
      new_node->next = aux_node;
      this->head = new_node;
    }
  }

void LinkedList::traverse() {
    Node* current_node = this->head;
    while (current_node != NULL) {
      cout << current_node->value << endl;
      current_node = current_node->next;
    }
  }
