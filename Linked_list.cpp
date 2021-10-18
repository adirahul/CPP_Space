#include <bits/stdc++.h>
using namespace std;

//linked list insertion 
struct Node{
  int data;
  Node *next;
};

Node *head = NULL;

void insert_at_beg(int p){
  Node *ptr = new Node();
  ptr -> data = p;
  ptr -> next = head;
  head = ptr;
}

void insert_at_end(int p){
  Node *ptr = new Node();
  ptr-> data = p;  
  ptr -> next = NULL;

  if(head == NULL){
    head = ptr;
  }
  else
  {    
    Node *temp = head;
    while(temp -> next != NULL)
    {
      temp = head-> next;
    }
  temp -> next = ptr;
  }
}

void print_LL()
{
  Node *temp = head;
  while(temp != NULL){
    cout << temp -> data << ' ';
    temp = temp -> next;
  }
}

void reverse_LL()
{
  Node *prev, *cur, *nxt;
  prev = NULL;
  cur = head;
  while(cur != NULL)
  {
    nxt = cur -> next;
    cur -> next = prev;
    prev = cur;
    cur = nxt;
  }
  head = prev;
}
int main()
{
  for(int i = 0; i < 4; i++)insert_at_beg(3);
  print_LL();
}