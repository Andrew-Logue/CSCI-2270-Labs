#include "LinkedList.h"

using namespace std;

// Add a new node to the list
void LinkedList::insert(Node* prev, int newKey) {
  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;

    }
}


// TODO: SILVER PROBLEM
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n) {
  bool isDeleted = false;
  LinkedList *temp = new LinkedList;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }



  // Special case to delete the head
  if (n == 0) {
      // TODO
      head = temp -> next;   // Change head 
      free(temp);            // free old head 
      return;
  }

  Node *pres = head;
	Node *prev = NULL;

  while(prev->next != NULL && prev->next != n) { 
    prev = prev->next;
  }

  // Find previous node of the node to be deleted 
  for (int i=0; temp != NULL && i < n-1; i++){
       temp = temp->next; 
  }
  
  // If position is more than number of ndoes 
  if (temp == NULL || temp->next == NULL) {
       return isDeleted; 
  }
  
  // Node temp->next is the node to be deleted 
  // Store pointer to the next of node to be deleted 
  struct Node *next = temp->next->next; 
  
  // Unlink the node from linked list 
  free(temp->next);  // Free memory 
  
  temp->next = next;  // Unlink the deleted node from list   

	return isDeleted;
}

// TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values)
bool LinkedList::swapFirstAndLast() {
    bool isSwapped = false;

    if(head == NULL) {
        cout << "List is empty. Cannot swap" << endl;
        return false;
    }

    // TODO (take care of the edge case when your linkedlist has just 2 nodes)

    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) {
    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}
