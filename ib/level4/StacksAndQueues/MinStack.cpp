/*************************************************************************************************
Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack?
A: In this case, return -1.

Q: What should pop do on empty stack?
A: In this case, nothing.

Q: What should top() do on empty stack?
A: In this case, return -1
NOTE : If you are using your own declared global variables, make sure to clear them out
in the constructor.
*************************************************************************************************/
#include <stack>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
class MinStack {
	stack<int> st;
	stack<int> mins;

	MinStack::MinStack() {
		while (!st.empty()) st.pop();
		while (!mins.empty()) mins.pop();
	}

	void MinStack::push(int x) {
		if (!mins.empty() && mins.top() < x) mins.push(mins.top());
		else mins.push(x);
		st.push(x);
	}

	void MinStack::pop() {
		if (!st.empty())
		{
			st.pop();
			mins.pop();
		}
	}

	int MinStack::top() {
		if (st.empty()) return -1;
		return st.top();
	}

	int MinStack::getMin() {
		if (mins.empty()) return -1;
		return mins.top();
	}
};
#else
class MinStack {
private:
	stack<int> elementStack;
	stack<int> minimumStack;
	int minElement = -1;
public:
	void push(int x) {
		elementStack.push(x);
		if (elementStack.size() == 1 || x <= minElement) {
			minimumStack.push(x);
			minElement = x;
		}
	}

	void pop() {
		if (elementStack.top() == minElement) {
			minimumStack.pop();
			if (!minimumStack.empty()) {
				minElement = minimumStack.top();
			}
			else {
				minElement = -1;
			}
		}
		elementStack.pop();
	}

	int top() {
		if (elementStack.empty()) return -1;
		return elementStack.top();
	}

	int getMin() {
		return minElement;
	}
};
#endif