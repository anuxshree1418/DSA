#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st;

    st.push(5);
    st.push(7);
    st.push(3);

    cout << "Top element: " << st.top() << endl; // Output: 3

    st.pop(); // Removes the top element (3)

    cout << "Top element after pop: " << st.top() << endl; // Output: 7

    cout << st.empty() << endl; // Output: 0 (false, stack is not empty)

    cout << "Size of stack: " << st.size() << endl; // Output: 2

    return 0;
}