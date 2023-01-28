#include <iostream>
#include <stack>
using namespace std;

// Initializing empty auxiliary stack. Then it assigns the top value from original stack to a variable x.
// If the aux. stack is empty OR the top element of aux stack is greater than x, then x is pushed to the top of aux
// If x is less than top element of stack aux it enters the loop. 
// Where each element from aux pushed to the original stack as long as the x > than aux.top.
// Process is repeated untill the original stack is empty.
// Last loop in merge() push all elements from aux to original stack in a sorted manner.
// Merge two sorted sub-stacks into the original stack
void merge(stack<int> &stk) {
    stack<int> aux;
    while (!stk.empty()) {
        int x = stk.top();
        stk.pop();
		cout << "x:'" << x << "'\t";
		if (!aux.empty())
			cout << "aux.top(" << aux.top() << ")\t";
        if (aux.empty() || x <= aux.top()) {
			cout << "push '" << x << "' to > aux.top" << endl;
            aux.push(x);
        } else {
			cout << "else, push '" << x << "' to aux.top" << endl;
            while (!aux.empty() && x > aux.top()) {
                stk.push(aux.top());
				cout << "\t\tpush back to stk.push(" << aux.top() << ") and pop from aux" << endl;
                aux.pop();
            }
            aux.push(x);
        }
    }
    while (!aux.empty()) {
        stk.push(aux.top());
        aux.pop();
    }
}

// Recursively sort a sub-stack
void sort(stack<int> &stk) {
    if (stk.empty())
        return;
    int x = stk.top();
    stk.pop();
	cout << x << endl;
    sort(stk);
    stk.push(x);
    merge(stk);
}

// Sort the original stack using In-Place Merge Sort
void inPlaceMergeSort(stack<int> &stk) {
    sort(stk);
}

int main() {
    stack<int> stk;
    stk.push(2);
    stk.push(5);
    stk.push(1);
    stk.push(3);
    stk.push(4);
    while (!stk.empty()) {
        cout << stk.top() << ", ";
        stk.pop();
    }
    cout << endl;
    stk.push(2);
    stk.push(5);
    stk.push(1);
    stk.push(3);
    stk.push(4);
    inPlaceMergeSort(stk);
    while (!stk.empty()) {
        cout << stk.top() << ", ";
        stk.pop();
    }
    cout << endl;
    return 0;
}