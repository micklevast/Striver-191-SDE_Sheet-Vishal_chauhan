#include <iostream>
#include <string>
#include<vector>
using namespace std;
// good optimimsed but ,failed at one testcase!

int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    int pl=p.length();
    int sl=s.length();
    string ttl=p+"$"+s;
    vector<int> Zarray(n+m+1,0);
    // cout<<"ttl:"<<ttl<<endl;
    for(int i=1;i<(m+n+1);){
        // cout<<"atINdex:"<<i<<" char:"<<ttl[i]<<endl;
        int len=0;
        int ii=i;
        while(i<(m+n+1) && ttl[i]!='$' && ttl[i]==ttl[len]){
            // cout<<"found at:"<<i<<" | ";
            len++;
            i++;
        }
        Zarray[ii]=len;
        i=ii+1;
    }
    int ans=0;
    for(auto val:Zarray){
        // cout<<val<<" ";
        if(val==m)ans++;
    }cout<<endl;
    return ans;
}