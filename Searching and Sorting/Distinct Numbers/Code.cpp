#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
typedef long long ll;
 
 
int main()	{
 
    int n;
    cin>>n;
 
    set<int> st;
    for(int i=0; i<n ;i++)	{
    	int x;
    	cin>>x;
    	st.insert(x);
    }
 
    cout<<st.size();
 
    return 0;
}