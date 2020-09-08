//
//  main.cpp
//  Doubly Linked List
//
//  Created by yuteng Wu on 9/8/20.
//  Copyright © 2020 Yuteng Wu. All rights reserved.
//

#include <iostream>
using namespace std;

template<class T>
class Node
{
private:
   T data;
   Node<T> *head;
   Node<T> *pre;
   Node<T> *next;

public:
   Node();
   void inserAtHead(T x);
   void inserAtTail(T x);
   void print();
   void reversePrint();
   Node<T> *getNewNode(T x);


};




int main()
{
   Node<int> node;

   node.inserAtHead(2);
   node.inserAtHead(4);
   node.inserAtHead(6);
   node.print();
   node.reversePrint();
}



template<class T>
Node<T>::Node():head(NULL){}

template<class T>
void Node<T>::inserAtHead(T x)
{
   Node<T> *newNode = getNewNode(x); //getNewNode method header without *

   if(head == NULL)
   {
      head = newNode;
      return;
   }

   head->pre = newNode;
   newNode->next = head;
   head = newNode;



}


template<class T>
void Node<T>::inserAtTail(T x)
{

}


template<class T>
void Node<T>::print()
{
   Node<T> *temp = head;

   while(temp != NULL)
   {
      cout << temp->data;
      temp = temp->next;
   }
   cout << endl;
}



template<class T>
void Node<T>::reversePrint()
{
   Node<T> *temp = head;

   if(temp == NULL)
   {
      return;
   }

   while(temp->next != NULL)
   {
      temp = temp->next;
   }

   cout << "Reverse: ";

   while(temp != NULL)
   {
      cout << temp->data;
      temp = temp->pre;
   }

   cout << endl;
}



template<class T>
Node<T> *Node<T>::getNewNode(T x)
{
   Node<T> *newNode = new Node();

   newNode->data = x;
   newNode->next = NULL;
   newNode->pre = NULL;

   return newNode;

}
