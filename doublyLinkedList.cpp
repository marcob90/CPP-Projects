#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Node{	
	friend class DoublyLinkedList;
	public:
		Node(int d)
		{
			data = d;
			next = NULL;
			prev = NULL;
		}
	private:
		int data;
		Node *next;
		Node *prev;
};

class DoublyLinkedList
{
	public:
		DoublyLinkedList()
		{
			head = NULL;
		}
		
		void printList() const
		{
			Node *currentNode = head;
			
			cout << "NULL <--> ";
			
			while(currentNode != NULL){
				cout << currentNode->data << " <--> ";
				currentNode = currentNode->next;
			}
			
			cout << "NULL" << endl;
		}
		
		void insertNode(int value)
		{
			Node *newNode = new Node(value);
			Node *currentNode = head;
			
			if(newNode != NULL){
				if(currentNode == NULL){
					head = newNode;
					return;
				}
				else if(currentNode->data > value){
					newNode->next = currentNode;
					head = newNode;
					currentNode->prev = head;
					return;
				}
				while(currentNode->next != NULL){
					if(currentNode->next->data > value){
						newNode->next = currentNode->next;
						newNode->prev = currentNode;
						currentNode->next->prev = newNode;
						currentNode->next = newNode;
						return;
					}
					currentNode = currentNode->next;
				}
				
				currentNode->next = newNode;
				newNode->prev = currentNode;
			}
		}
		
		void deleteNode(int value)
		{
			Node *currentNode = head;
			Node *temp;
			
			if(currentNode->data == value){
				temp = currentNode;
				head = currentNode->next;
				currentNode = NULL;
				delete temp;
				return;
			}
			
			while(currentNode->next != NULL){
				if(currentNode->next->data == value){
					temp = currentNode->next;
					currentNode->next = currentNode->next->next;
					currentNode->next->prev = currentNode;
					delete temp;
					return;
				}
				currentNode = currentNode->next;
			}
		}
		
		void reverseList()
		{
			if(head == NULL) return;
			
			Node *currentNode = head;
			Node *prevNode = NULL;
			
			while(currentNode != NULL){
				prevNode = currentNode;	
				swap(currentNode->prev, currentNode->next);
				currentNode = currentNode->prev;
			}
			
			head = prevNode;
		}
	private:
		Node *head;

};

int main()
{
	DoublyLinkedList list;
	srand(time(NULL));
	
	for(int i = 1; i <= 20; i++){
		list.insertNode(rand() % 50);
	}
	list.insertNode(16);
	list.printList();
	list.reverseList();
	list.printList();
}
