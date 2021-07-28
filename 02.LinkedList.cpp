01. //First Simple Linked List in C Let us create a simple linked list with 3 nodes.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int x)
};
int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	head = new Node();
	second = new Node();
	third = new Node();
	head->data = 1; // assign data in first node
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3; // assign data to third node
	third->next = NULL;
	return 0;
}
02.//Linked List Traversal, let us write a general-purpose function printList() that prints any given list.
void printList(Node* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
}

03.//(Inserting a node)
In this post, methods to insert a new node in linked list are discussed. A node can be added in three ways 
1) At the front of the linked list 
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

2) After a given node.
void insertAfter(Node** prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		cout << "the given previous node cannot be NULL";
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = *prev_node->next;
	*prev_node->next = new_node;
}
3) At the end of the linked list.
void append(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	Node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

04.//(Deleting a node)
void deleteNode(Node** head_ref, int key)
{
	Node* temp = *head_ref;
	Node* prev = NULL;
	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp->next;
		delete temp;
		return;
	}
	else
	{
	    while (temp != NULL && temp->data != key)
	    {
	        prev = temp;
	        temp = temp->next;
	    }
	    if (temp == NULL)
		    return;
	    prev->next = temp->next;
	    delete temp;
	}
}

05. //Write a function to delete a entire Linked List
void deleteList(Node** head_ref)
{
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

06. //Find Length of a Linked List (Iterative and Recursive) i.e. Write a function to count the number of nodes in a given singly linked list.
int getCount(Node* head)
{
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
....................................................
Recursive
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
int getCount(Node* head)
{
	if (head == NULL) {
		return 0;
	}
	else {
		return 1 + getCount(head->next);
	}
}
int main()
{
	Node* head = NULL;
	push(&head, 1);
	push(&head, 3);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);
	cout << "Count of nodes is " << getCount(head);
	return 0;
}

06.//Given a singly linked list and a position, delete a linked list node at the given position.
#include <bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
};
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void deleteNode(Node **head_ref, int position)
{
	if (*head_ref == NULL)
		return;
	Node* temp = *head_ref;
	if (position == 0)
	{
		*head_ref = temp->next;
		free(temp);			
		return;
	}
	for(int i = 0; temp != NULL && i < position - 1; i++)
		temp = temp->next;
	if (temp == NULL || temp->next == NULL)
		return;
	Node *next = temp->next->next;
	free(temp->next);
	temp->next = next;
}
void printList( Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}
int main()
{
	Node* head = NULL;
	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);
	push(&head, 8);
	cout << "Created Linked List: ";
	printList(head);
	deleteNode(&head, 4);
	cout << "\nLinked List after Deletion at position 4: ";
	printList(head);
	return 0;
}


07. //Write a function that searches a given key ‘x’ in a given singly linked list. The function should return true if x is present in linked list and false otherwise.
..................................................
Iterative
..................................................

bool search(Node* head, int x)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}

.....................
Recursive
.....................

bool search(Node* head, int x)
{
    if (head == NULL)
        return false;
    if (head->key == x)
        return true;
    return search(head->next, x);
}

08.//Write a GetNth() function that takes a linked list and an integer index and returns the data value stored in the node at that index position. 
int GetNth(Node* head, int index)
{
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }
    assert(0);
}
............................................
Method 2- With Recursion 
............................................
int GetNth(struct Node* head, int n)
{
    if (head == NULL)
        return -1;
    if (n == 0)
        return head->data;
    return GetNth(head->next, n - 1);
}


09.//Program for n’th node from the end of a Linked List
...........................................................................
Method 1 (Use length of linked list): 
1) Calculate the length of Linked List. Let the length be len. 
2) Print the (len – n + 1)th node from the beginning of the Linked List.


void printNthFromLast(struct Node* head, int n)
{
    int len = 0, i;
    struct Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    if (len < n)
        return;
 
    temp = head;
    for (i = 1; i < len - n + 1; i++)
        temp = temp->next;
 
    cout << temp->data;
 
    return;
}

......................
Recurssive
......................

void printNthFromLast(Node* head, int n)
{
    static int i = 0;
    if (head == NULL)
        return;
    printNthFromLast(head->next, n);
    if (++i == n)
    	cout<<head->data;
}
...............................................................
Method 2 (Use two pointers) 
...............................................................

void printNthFromLast(Node *head, int n)
{
  Node *main_ptr = head;
  Node *ref_ptr = head;
  int count = 0;
  if(head != NULL)
  {
     while( count < n )
     {
        if(ref_ptr == NULL)
        {
           return;
        }
        ref_ptr = ref_ptr->next;
        count++;
     }    
     if(ref_ptr == NULL)
     {
        head = head->next;
        if(head != NULL)
            cout<<main_ptr->data;
     }
     else
     {
       while(ref_ptr != NULL)
       {
          main_ptr = main_ptr->next;
          ref_ptr  = ref_ptr->next;
       }
       cout<<main_ptr->data;
     }
  }
}

10.//Find the middle of a given linked list

Method 1: Traverse the whole linked list and count the no. of nodes. Now traverse the list again till count/2 and return the node at count/2. 

....................................................................
Method 2: 
Traverse linked list using two pointers. Move one pointer by one and
the other pointers by two. When the fast pointer reaches the end
slow pointerwill reach the middle of the linked list.
....................................................................
Node* printMiddle(Node *head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;
    if (head)
    {
        while (fast_ptr && fast_ptr->next)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        return slow_ptr;
    }
}

11.//Given a singly linked list and a key, count the number of occurrences of the given key in the linked list
Method 1- Without Recursion:

int count(Node* head, int search_for)
{
    Node* current = head;
    int count = 0;
    while (current) {
        if (current->data == search_for)
            count++;
        current = current->next;
    }
    return count;
}

.........................................
Method 2- With Recursion:
.........................................
int count(Node* head, int key)
{
    if (head == NULL)
        return 0;
    if (head->data == key)
        return 1 + count(head->next, key);
    return count(head->next, key);
}


12.//Given a linked list, check if the linked list has loop or not. Below diagram shows a linked list with a loop.
.................................
Solution 1: Hashing Approach
Time complexity: O(n)
Auxiliary Space: O(n)
.................................
bool detectLoop(struct Node* h)
{
    unordered_set<Node*> s;
    while (h != NULL) {
        if (s.find(h) != s.end())
            return true;
        s.insert(h);
        h = h->next;
    } 
    return false;
}

.............................................
Solution 2: Floyd’s Cycle-Finding Algorithm
Time complexity: O(n).
Auxiliary Space:O(1). 
.............................................

int detectLoop(Node* head)
{
    Node *slow_p = head, *fast_p = head;
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}



13.//Find length of loop in linked list
.........................................................................................................................
1. Find the common point in the loop by using the Floyd’s Cycle detection algorithm
2. Store the pointer in a temporary variable and keep a count = 0
3. Traverse the linked list until the same node is reached again and increase the count while moving to next node.
4. Print the count as length of loop
..........................................................................................................................
int countNodes(struct Node *n)
{
    int res = 1;
    struct Node *temp = n;
    while (temp->next != n)
    {
        res++;
        temp = temp->next;
    }
    return res;
}
int countNodesinLoop(Node *list)
{
    Node *slow_p = list, *fast_p = list;
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
            return countNodes(slow_p);
    }
    return 0;
}

14. //Check if Linked List is Palindrome
#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* slow= head;
        stack <int> s;
        while(slow != NULL){
                s.push(slow->data);
                slow = slow->next;
        }
        while(head != NULL ){
             int i=s.top();
             s.pop();
            if(head -> data != i){
                return false;
            }
           head=head->next;
        }
    return true;
    }
};
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

15.// Remove duplicates from a sorted linked list
Node *removeDuplicates(Node *head)
{
 	Node* current = head;
	Node* next_next;
	if (current == NULL)
	    return head;
	while (current->next != NULL)
	{
	    if (current->data == current->next->data)
	    {
	        next_next = current->next->next;
	        free(current->next);
	        current->next = next_next;
	    }
	    else
	    	current = current->next;
	}
	return head;
}

16. //Remove duplicates from an unsorted linked list
void removeDuplicates(struct Node *head)
{
	unordered_set<int> map;
	struct Node *curr = head;
	struct Node *prev = NULL;
	while (curr != NULL)
	{
		if (map.find(curr->data) != map.end())
		{
		    prev->next = curr->next;
		    delete (curr);
		}
		else
		{
		    map.insert(curr->data);
		    prev = curr;
		}
		curr = prev->next;
	}
}

17. //Swap nodes in a linked list without swapping data
void swapNodes(Node** head_ref, int x, int y)
{
	if (x == y)
		return;
	Node *prevX = NULL, *currX = *head_ref;
	while (currX && currX->data != x) {
		prevX = currX;
		currX = currX->next;
	}
	Node *prevY = NULL, *currY = *head_ref;
	while (currY && currY->data != y) {
		prevY = currY;
		currY = currY->next;
	}
	if (currX == NULL || currY == NULL)
		return;
	if (prevX != NULL)
		prevX->next = currY;
	else
		*head_ref = currY;
	if (prevY != NULL)
		prevY->next = currX;
	else
		*head_ref = currX;
	Node* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

18. //Pairwise swap elements of a given linked list
void pairWiseSwap(Node* head)
{
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        swap(temp->data, temp->next->data);
        temp = temp->next->next;
    }
}

19. //Move last element to front of a given Linked List

void moveToFront(Node **head_ref) 
{
    if (*head_ref == NULL || (*head_ref)->next == NULL) 
        return;
    Node *secLast = NULL;
    Node *last = *head_ref;
    while (last->next != NULL) 
    { 
        secLast = last; 
        last = last->next;
    }
    secLast->next = NULL;
    last->next = *head_ref;
    *head_ref = last; 
}





