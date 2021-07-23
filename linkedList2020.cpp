#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

class Node
{	
	friend bool operator==(const Node &node1, const Node &node2){
		if(node1.data == node2.data && 
		node1.next == node2.next) return true;
		return false;
	}
	public:
		Node(int d)
		{
			data = d;
			next = NULL;
		}
		
		//copy constructor for deep copy
		/*Node(const Node &node){
			this->data = node.data;
			if(node.next != NULL){
				Node *newNode = new Node(*(node.next));
				this->next = newNode;
			}
			else
				this->next = NULL;
		}*/

		int data;
		Node *next;
};

class LinkedList
{
	friend bool operator==(const LinkedList &list1, const LinkedList &list2){
		Node *cNode1 = list1.head;
		Node *cNode2 = list2.head;
		
		while(cNode1 != NULL && cNode2 != NULL){
			if(cNode1->data != cNode2->data) return false;
			cNode1 = cNode1->next;
			cNode2 = cNode2->next;
		}
		
		return cNode1 == NULL && cNode2 == NULL;
	}
	
	public:
		LinkedList(Node *node = NULL)
		{
			head = node;
		}
		
		//copy constructor
	/*	LinkedList(const LinkedList &list){
			if(list.head != NULL){
				Node *newNode = new Node(*(list.head));
				head = newNode;
			}
			else
				head = NULL;
		}*/
		
		void printList() const
		{
			Node *currentNode = head;
			
			while(currentNode != NULL){
				cout << currentNode->data << " --> ";
				currentNode = currentNode->next;
			}
			
			cout << "NULL" << endl;
		}
		
		void insertNode(int value)
		{
			Node *newNode = new Node(value);
			Node *currentNode = head;
			
			if(newNode != NULL){
				if(currentNode == NULL ||
				currentNode->data > value){
					head = newNode;
					head->next = currentNode;
					return;
				}
				while(currentNode->next != NULL){
					if(currentNode->next->data > value){
						newNode->next = currentNode->next;
						currentNode->next = newNode;
						return;
					}
					currentNode = currentNode->next;
				}
				
				currentNode->next = newNode;
			}
		}
		
		void push_front(int value){
			Node *newNode = new Node(value);
			
			if(newNode != NULL){
				if(head == NULL)
					head = newNode;
				else{
					newNode->next = head;
					head = newNode;
				}
			}
		}
		
		void push_back(int value){
			Node *newNode = new Node(value);
			
			if(newNode != NULL){
				if(head == NULL)
					head = newNode;
				else{
					Node *currentNode = head;
					while(currentNode->next != NULL)
						currentNode = currentNode->next;
						
					currentNode->next = newNode;
				}
			}
		}
		
		void deleteNode(int value)
		{
			Node *currentNode = head;
			Node *temp;
			
			if(currentNode->data == value){
				temp = currentNode;
				head = currentNode->next;
				delete temp;
				return;
			}
			
			while(currentNode->next != NULL){
				if(currentNode->next->data == value){
					temp = currentNode->next;
					currentNode->next = currentNode->next->next;
					delete temp;
					return;
				}
				currentNode = currentNode->next;
			}
		}
		
	/*	void reverseList()
		{
			if(head == NULL) return;
			
			Node *prevNode = NULL;
			Node *currentNode = head;
			Node *nextNode = head->next;
			
			while(nextNode != NULL){
				currentNode->next = prevNode;
				prevNode = currentNode;
				currentNode = nextNode;
				nextNode = nextNode->next;
			}
			
			head = currentNode;
			currentNode->next = prevNode;
		}*/
		
		void reverseList(){
			Node *prev = NULL;
			Node *last = NULL;
			
			if(this->head != NULL)
				reverseList(prev, &last);
			else return;
			
			this->head = last;
		}
		
		void reverseList(Node *prev, Node **last)
		{
			if(this->head->next == NULL){
				this->head->next = prev;
				*last = (this->head);
			}
			else{
				LinkedList list(this->head->next);
				list.reverseList(this->head, last);
				this->head->next = prev;
			}
		}
		
		void removeDuplicates(){
			if(head == NULL || head->next == NULL) return;
			
			Node *currentNode = head;
			unordered_set<int> values;
			values.insert(head->data);
			 
			while(currentNode->next != NULL){
				if(values.find(currentNode->next->data) == values.end()){
					values.insert(currentNode->next->data);
					currentNode = currentNode->next;
				}
				else{
					Node *temp = currentNode->next;
					currentNode->next = currentNode->next->next;
					delete temp;
				}
			}
		}
		
		Node* findKthToLast(int k){
			int i = 0;
			return findKthToLast(head, k, i);
		}
		
		bool deleteCentralNode(Node *node){
			if(node == NULL || node->next == NULL)
				return false; //failure
			if(node->next == NULL){
				
			}
		/*	Node *nextNode = node->next;
			node->data = nextNode->data;
			node->next = nextNode->next;
			delete nextNode;*/
			*node = *(node->next);
			delete node->next;
			return true;
		}
		
		void partition(int val){
			if(head == NULL) return;
			
			LinkedList smallerList;
			LinkedList biggerList;
			Node *smallerListTail = NULL;
			Node *currentNode = head;
			
			while(currentNode != NULL){
				if(currentNode->data < val){
					smallerList.push_front(currentNode->data);
					if(smallerList.head->next == NULL)
						smallerListTail = smallerList.head;
				}
				else{
					biggerList.push_front(currentNode->data);
				}
				currentNode = currentNode->next;
			}
			
			//merge lists
			if(smallerList.head == NULL)
				*this = biggerList;
			else if(biggerList.head == NULL)
				*this = smallerList;
			else{	
				smallerListTail->next = biggerList.head;
				*this = smallerList;
			}
		}
		
		LinkedList sumLists(const LinkedList &list2){
			Node *cList1 = this->head;
			Node *cList2 = list2.head;
			LinkedList newList;
			int carry = 0;
			
			while(cList1 != NULL || cList2 != NULL){
				int digit1 = (cList1 == NULL) ? 0 : cList1->data;
				int digit2 = (cList2 == NULL) ? 0 : cList2->data;
				
				int digitsSum = digit1 + digit2 + carry;
				int newDigit = digitsSum % 10;
				carry = digitsSum / 10;
				newList.push_back(newDigit);
				
				if(cList1 != NULL)cList1 = cList1->next;
				if(cList2 != NULL)cList2 = cList2->next;
			}
			
			if(carry != 0) newList.push_back(carry);
			
			return newList;
		}
		
		LinkedList sumLists2(const LinkedList &list2){
			int carry = 0;
			LinkedList newList = this->sumLists2(list2, carry);
			
			if(carry != 0) newList.push_front(carry);
			return newList;
		}
		
		LinkedList sumLists2(const LinkedList &list2, int &carry){
			if(this->head == NULL && list2.head == NULL){
				LinkedList newList;
				return newList;
			}
			
			LinkedList listA(this->head->next);
			LinkedList listB(list2.head->next);
			LinkedList newList = listA.sumLists2(listB, carry);
			int sum = carry + this->head->data + list2.head->data;
			carry = sum / 10;
			
			newList.push_front(sum % 10);
			return newList;
		}
		
		bool isPalindrome(){
			LinkedList list = this->reverseAndClone();
			return (*this == list);
		}
		
		LinkedList reverseAndClone(){
			LinkedList newList;
			Node *cNode = this->head;
			while(cNode != NULL){
				newList.push_front(cNode->data);
				cNode = cNode->next;
			}
			
			return newList;
		}
		
		/*bool isPalindrome(){
			if(head == NULL) return false;
			LinkedList list1 = *this;
			LinkedList list2(list1);
			list2.reverseList();
			Node *cNode1 = list1.head;
			Node *cNode2 = list2.head;		
			
			while(cNode1 != NULL && cNode2 != NULL){
				if(cNode1->data != cNode2->data) return false;
				
				cNode1 = cNode1->next;
				cNode2 = cNode2->next;
			}
			
			return cNode1 == NULL && cNode2 == NULL;
		}*/
		
		bool isIntersecting(LinkedList list2){
			if(cNode1 == NULL || cNode2 == NULL) 
				return false;
				
			Node *cNode1 = this->head;
			Node *cNode2 = list2.head;
			
			while(cNode1->next != NULL)
				cNode1 = cNode1->next;
			
			while(cNode2->next != NULL)
				cNode2 = cNode2->next;
			
			return cNode1 == cNode2;
		}
	private:
		Node *head;
		
		Node *findKthToLast(Node *node, int k, int &i){
			if(node == NULL) return NULL;
			Node *nd = findKthToLast(node->next, k, i);
			
			if(++i == k) return node;
			return nd;
		}

};

int main()
{
	LinkedList list;
	LinkedList list2;
	srand(time(NULL));
	
	for(int i = 1; i <= 10; i++){
		list.push_front(rand() % 10);
		list2.push_front(rand() % 10);
	}
	/*list.printList();
	list2.printList();
	LinkedList list3 = list.sumLists(list2);
	list3.printList();
	LinkedList list4 = list.sumLists2(list2);
	list4.printList();
	list4.reverseList();
	list4.printList();*/
/*	list.reverseList();
	list.printList();
	Node *node = list.findKthToLast(2);
	list.deleteCentralNode(node);
	list.printList();
	list.partition(5);
	list.printList();
	list2.printList();
	LinkedList list3 = list.sumLists(list2);
	list3.printList();*/
	LinkedList list4;
	list4.push_back(1);
	list4.push_back(6);
	list4.push_back(3);
	list4.push_back(3);
	list4.push_back(6);
	list4.push_back(1);
	list4.printList();
	cout << list4.isPalindrome();
}
