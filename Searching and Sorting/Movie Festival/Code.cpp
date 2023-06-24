#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
 
 
int main()	{
 
    int n;
    cin>>n;
 
    vector<pi> vec (n);
    for(int i=0; i<n; i++)	{
    	cin>>vec[i].first>>vec[i].second;
    }
    sort(vec.begin(), vec.end());
 
    int ans = 0, curr = 0;
    for(int i=0; i<n; i++)	{
    	if(i==0)	{
    		curr = vec[i].second;
    		ans++;
    	}	
    	else {
    		if(vec[i].first >= curr)	{
    			ans++;
    			curr = vec[i].second;
    		}
    		else {
    			curr = min(vec[i].second,curr);
    		}
    	}
    }
 
    cout<<ans;
 
    return 0;
}