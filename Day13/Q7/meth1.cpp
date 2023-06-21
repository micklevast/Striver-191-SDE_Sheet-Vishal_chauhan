#include<bits/stdc++.h>
// O(n^2)
void insertAtRightPlace(stack<int> &st,int val){
	if(st.empty() || st.top()<=val){
		st.push(val);
		return;
	}
	int tp=st.top();
	st.pop();
	insertAtRightPlace(st,val);
	st.push(tp);
}
void sorting(stack<int> &st){
	if(st.empty())return;

	int tp=st.top();
	st.pop();

	sorting(st);

	insertAtRightPlace(st,tp);

}
void sortStack(stack<int> &stack)
{
	// Write your code here
	sorting(stack);
}