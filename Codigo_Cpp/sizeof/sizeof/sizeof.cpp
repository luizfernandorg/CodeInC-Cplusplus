// { Driver Code Starts
#include <iostream>
//#include <cstdio>
//#include <cstdlib>

struct Node
{
    int data;
    Node* next;
}*start;

int insert();
void display(Node* head);
void reverse(Node* head);
void doubleIt(int* n);

int main()
{
    int a = 5;
    int* n = &a;
    std::cout << "Main: " << n << " " << *n << " " << a << std::endl;
    doubleIt(n);
    std::cout << "Main: " << n << " " << *n << " " << a << std::endl;
    delete n;
    //start = NULL;
    
    //int n = insert(); // execute insertion and then return the amount of values inserted;
    //display(start);
    
    //reverse(start);
   // display(start);
 
    //std::cin.get();
    //delete[] start;
    return 0;
}

int insert()
{
    int n, value;
    std::cout << "How many values do you wanna insert? " << std::endl;
    std::cin >> n;
    Node* temp = nullptr;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Give the value? ";
        std::cin >> value;
        if (i == 0)
        {
            start = new Node();
            std::cout << start << std::endl;
            start->data = value;
            start->next = NULL;
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node();
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
    }
    return n;
}

// } Driver Code Ends


/*
  Print elements of a linked list on console
  head pointer input could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     Node *next;
  }
*/
void display(Node* head)
{
    if (head) {
        std::cout << head->data << " "; // In this task we need to print the values in the same line
        display(head->next);
    }
}

//void reverse(Node** head) {
void reverse(Node* head) {
    // In this approach, I invert only the value held on data
    std::cout << std::endl;
    std::cout << head << std::endl;

    Node* prev = nullptr;
    Node* next = nullptr;
    Node* current = head;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
