#include <iostream>
#include "SinglyLL.h"

using namespace std;


int main() {
  SinglyLL myLL;
  myLL.insert(20);
  myLL.insert(56);
  myLL.insert(10);
  cout << "Sorted Singly Linked List: ";
  myLL.display();
  myLL.reverse();
  cout << endl << "Reversed Singly Linked List: ";
  myLL.display();
  cout << "\nNumber at front of the list: " << myLL.front() << endl << "Number at the end of the list: " << myLL.back() << endl;
  cout << "Adding number at the front of the list: ";
  myLL.insertFront(334);
  myLL.display();
  cout << "\nRemoving number at the end of the list: ";
  myLL.popBack();
  myLL.display();
  cout << "\nAdding number at the end of the list: ";
  myLL.insertEnd(4);
  myLL.display();
  cout << "\nRemoving number at the front of the list: ";
  myLL.popFront();
  myLL.display();
  cout << "\nChecking with the list is empty (0 False | 1 True): " << myLL.isEmpty() << endl;
  cout << "Check the size of the list: " << myLL.size();
  cout << "\nMerge this list with another, they both have to be sorted so I will reverse this again " << endl;
  myLL.reverse();
  SinglyLL newLL;
  newLL.insert(334);
  newLL.insert(50);
  newLL.insert(80);
  newLL.insert(9);
  cout << "Old list: ";
  myLL.display();
  cout << "\nNew list: ";
  newLL.display();
  cout << "\nMerged list: ";
  newLL.merge(myLL.head, newLL.head);
  myLL.display();
  cout << endl;
  myLL.deleteNode(400);
  cout << endl;
  myLL.deleteNode(56);
  myLL.display();

  
  return 0;
}