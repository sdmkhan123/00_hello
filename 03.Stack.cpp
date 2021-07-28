01.//
#include<bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    
    void push(int x) {
        if(top <1000){
            arr[++top] = x;
        }
    }
    int pop()
    { 
        if(top != -1){
            int x =arr[top--];
            return x;
        }
    }
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyStack *sq = new MyStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
}


02.// Implement two stacks in an array
This method efficiently utilizes the available space. It doesn’t cause an overflow if there is space available in arr[]. The idea is to start two stacks from two extreme corners of arr[]. stack1 starts from the leftmost element, the first element in stack1 is pushed at index 0. The stack2 starts from the rightmost corner, the first element in stack2 is pushed at index (n-1). Both stacks grow (or shrink) in opposite direction. To check for overflow, all we need to check is for space between top elements of both stacks. 
...........................................................................................................
#include <bits/stdc++.h>
using namespace std;
class twoStacks {
	int* arr;
	int size;
	int top1, top2;

public:
	twoStacks(int n)
	{
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = size;
	}
	void push1(int x)
	{
		if (top1 < top2 - 1) {
			top1++;
			arr[top1] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}
	void push2(int x)
	{
		if (top1 < top2 - 1) {
			top2--;
			arr[top2] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}
	int pop1()
	{
		if (top1 >= 0) {
			int x = arr[top1];
			top1--;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}
	int pop2()
	{
		if (top2 < size) {
			int x = arr[top2];
			top2++;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}
};
int main()
{
	twoStacks ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
	cout << "Popped element from stack1 is "<< ts.pop1();
	ts.push2(40);
	cout << "\nPopped element from stack2 is "<< ts.pop2();
	return 0;
}

03.//We are given a Queue data structure that supports standard operations like enqueue() and dequeue(). We need to implement a Stack data structure using only instances of Queue and queue operations allowed on the instances.

#include <bits/stdc++.h>
using namespace std;
class Stack {
	queue<int> q1, q2;
	int curr_size;

public:
	Stack()
	{
		curr_size = 0;
	}
	void push(int x)
	{
		curr_size++;
		q2.push(x);
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}
	void pop()
	{
		if (q1.empty())
			return;
		q1.pop();
		curr_size--;
	}
	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front();
	}
	int size()
	{
		return curr_size;
	}
};
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << "current size: " << s.size()<< endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << "current size: " << s.size()<< endl;
	return 0;
}






