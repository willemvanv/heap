/* Willem van Veldhuisen
   11/29*/
#include <iostream>
#include <cstring>
#include "Node.h"
#include <fstream>

using namespace std;

//Main
int main() {
  //Variables
  Node* head = NULL;
  int numInput[101];
  int place = 0;
  //Get input type
  cout << "File or Console Entry?(file/console)" << endl;
  char input[8];
  cin.getline(input, 8);
  if (input[0] == 'f' && input[1] == 'i' && input[2] == 'l' && input[3] == 'e') {
    cout << "What is the file name?" << endl;
    char inputa[30];
    cin.getline(inputa, 30);
    fstream file;
    file.open (inputa);
    while(!file.eof()) {
      file >> numInput[place];
      place++;
    }
    
  }
  else if (input[0] == 'c' && input[1] == 'o' && input[2] == 'n' && input[3] == 's' &&
	   input[4] == 'o' && input[5] == 'l' && input[6] == 'e') {
    cout << "How many numbers are you inputing?" << endl;
    int no;
    cin >> no;
    cout << "Enter numbers, hit enter after each" << endl;
    for (int i = 0; i < no; i++) {
      cin >> numInput[place];
      place++;
    }
    /*for (int a = 0; a < place; a++) {
      cout << numInput[a];
    }*/
  }
  //Once we have the numbers from input, we put them in the heap and feed back the data
  head = new Node(numInput[0]);
  for (int i = 1; i < place; i++) {
    Node* node = new Node(numInput[i]);
    if (node->getValue() > head->getValue()) {
      node->setRchild(head);
      head = node;
    }
    else {
      Node* temp;
      Node* current = head;
      while (1) {
	if (current->getLchild() == NULL) {
	  current->setLchild(node);
	  break;
	}
	else if (current->getRchild() == NULL) {
	  current->setRchild(node);
	  break;
	}
	else if (current->getRchild()->getValue() < node->getValue()) {
	  temp = current->getRchild();
	  current->setRchild(node);
	  node->setRchild(temp);
	  break;
	}
	else {
	  current = current->getRchild();
	}
      }
    }
  }
  //visual representation
  cout << "visual representation:" << endl;
  if (head != NULL) {
    int spaces = 0;
    Node* current = head;
    cout << "   " << head->getValue() << endl;
    spaces = spaces + 2;
    while (1) {
      if (current->getRchild() == NULL && current->getLchild() == NULL) {
	break;
      }
      for (int i = 0; i < spaces; i++) {
	cout << ' ';
      }
      if (current->getLchild() != NULL) {
	cout << current->getLchild()->getValue();
      }
      if (current->getRchild() == NULL) {
	cout << endl;
	break;
      }
      else if (current->getLchild() != NULL && current->getRchild() != NULL) {
	int w = current->getLchild()->getValue();
	if (w = 1000) {
	  cout << "    ";
	}
	else if (w > 99) {
	  cout << "     ";
	}
	else if (w > 9) {
	  cout << "      ";
	}
	else {
	  cout << "       ";
	}
	cout << current->getRchild()->getValue() << endl;
	current = current->getRchild();
      }
      spaces = spaces + 3;
    }
  }
  //Showing numbers greatest to least
  cout << "Greatest to Least:" << endl;
  int output[101];
  for (int i = 0; i < place; i++) {
    Node* current = head;
    Node* g = NULL;
    int great = 0;
    if (current->getUsed() != true) {
      great = current->getValue();
      g = current;
    }
    else {
      while (1) {
	if ((current->getLchild() != NULL) && (current->getLchild()->getValue() > great) &&
	    (current->getLchild()->getUsed() == false)) {
	  great = current->getLchild()->getValue();
	  g = current->getLchild();
	}
	if ((current->getRchild() != NULL) && (current->getRchild()->getValue() > great) &&
	    (current->getRchild()->getUsed() == false)) {
	  great = current->getRchild()->getValue();
	  g = current->getRchild();
	}
	if (current->getRchild() == NULL) {
	  break;
	}
	current = current->getRchild();
      }
    }
    if (g != NULL) {
      output[i] = great;
      g->setUsed(true);
    }
  }
  for (int i = 0; i < place; i++) {
    cout << output[i] << ' ';
  }
  for (int i = 0; i < place; i++) {
    Node* current = head;
    while (1) {
      if (current->getLchild() == NULL && current->getRchild() == NULL) {
	current->~Node();
	break;
      }
      else {
	if (current->getRchild() == NULL && current->getLchild() != NULL) {
	  current->getLchild()->~Node();
	  current->setLchild(NULL);
	  break;
	}
	else if (current->getRchild() != NULL && current->getRchild()->getRchild() == NULL &&
	    current->getRchild()->getLchild() == NULL) {
	  current->getRchild()->~Node();
	  current->setRchild(NULL);
	  break;
	}
	current = current->getRchild();
      }
    }
  }

  return 0;
}
