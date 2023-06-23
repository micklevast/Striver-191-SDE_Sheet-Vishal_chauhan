
#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	 vector<int> in(n,0);
	 vector<int> out(n,0);
	 for(int i=0;i<n;i++){
		 for(int j=0;j<n;j++){
			 if(i!=j && knows(i,j)){
				 out[i]++;
				 in[j]++;
			 }
		 }
	 }
	 for(int i=0;i<n;i++){
		 if(in[i]==n-1 && out[i]==0)return i;
	 }
	 return -1;
}