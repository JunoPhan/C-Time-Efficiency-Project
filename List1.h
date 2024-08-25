#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int value;
  ListNode* next;
};

class List1 {
public:
  List1();

  void PutItem(int num);
  void HasItem(int num, bool& found);
  void Print();
  int GetLength() { return length; }

  ListNode* top; 
  int length;
};

List1::List1() {
  //default constructor
  top = NULL;
  length = 0;
}

void List1::PutItem(int num) {
  ListNode* prev = NULL;
  ListNode* cur = top;
  while( cur != NULL ) {
    if( cur->value > num ) { //found the place to add
      break;
    }
    else {
      prev = cur;
      cur = cur->next;
    }
  }//end while cur
  
  ListNode* newNode = new ListNode;
  newNode->value = num;
  if( prev == NULL ) {
    //add to empty list
    newNode->next = cur;
    top = newNode;
  }
  else {
    //link to previous
    newNode->next = cur;
    prev->next = newNode; 
  }
  length++;
}

void List1::HasItem(int num, bool& found) {
  found = false;
  ListNode* cur = top;
  while( cur != NULL ) {
    if( cur->value == num ) {
      found = true;
      break;
    }
    cur = cur->next;
  }
}

void List1::Print() {
  ListNode* cur = top;
  while( cur != NULL ) {
    cout << cur->value << " ";
    cur = cur->next;
  }
  cout << endl;
}
