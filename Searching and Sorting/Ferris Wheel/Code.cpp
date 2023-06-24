#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
typedef long long ll;
 
 
int main()	{
 
    int n,wt;
    cin>>n>>wt;
    int cnt = 0;
 
    vector<int> vec;
   	for(int i=0; i<n; i++)	{
   		int x;
   		cin>>x;
   		vec.push_back(x);
   	}
   	sort(vec.begin(), vec.end());
 
   	int i=0, j=n-1;
   	while(i<=j)	{
   		if(vec[i]+vec[j] <= wt)	{
   			cnt++;
   			i++;
   			j--;
   		}
   		else {
   			cnt++;
   			j--;
   		}
   	}
 
    cout<<cnt;
 
    return 0;
}