// CODE 360: Reverse Linked List 
#include <bits/stdc++.h>
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
   LinkedListNode<int>* temp=head;
   LinkedListNode<int>* prev=nullptr;
   while(temp)
   { LinkedListNode<int>* front=temp->next;
   temp->next=prev;
   prev=temp;
   temp=front;
        
   }
   return prev;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
