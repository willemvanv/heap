#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(int v) {
  value = v;
  Lchild = NULL;
  Rchild = NULL;
  used = false;
}

Node::~Node() {
  //delete &value;
  //delete &used;
  Lchild = NULL;
  Rchild = NULL;
}

void Node::setLchild(Node* child) {
  Lchild = child;
}

void Node::setRchild(Node* child) {
  Rchild = child;
}

Node* Node::getLchild() {
  return Lchild;
}

Node* Node::getRchild() {
  return Rchild;
}

int Node::getValue() {
  return value;
}

bool Node::getUsed() {
  return used;
}

void Node::setUsed(bool a) {
  used = a;
}
