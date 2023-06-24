#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
typedef long long ll;
 
 
int main()	{
 
    int n,m,k;
    cin>>n>>m>>k;
 
    if(k==0)    {
        int cnt = 0;
        
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)	{
            int x;
            cin>>x;
            mp[x]++;
        }
 
        vector<int> apartment;
        for(int i=0; i<m; i++)	{
            int x;
            cin>>x;
            if(mp.find(x)!=mp.end())    {
                cnt++;
                mp[x]--;
                if(mp[x]==0)    {
                    mp.erase(x);
                }
            }
        }
 
        cout<<cnt;
        return 0;
    }
 
    vector<int> people;
    for(int i=0; i<n; i++)	{
    	int x;
    	cin>>x;
    	people.push_back(x);
    }
    sort(people.begin(),people.end());
 
    int mn_p = people[0];
    int mx_p = people[n-1];
 
    vector<int> apartment;
    for(int i=0; i<m; i++)	{
    	int x;
    	cin>>x;
    	if(x>=mn_p-k && x<=mx_p+k)
    		apartment.push_back(x);
    }
    sort(apartment.begin(), apartment.end());
 
    // for(auto i : people)    cout<<i<<" ";
    // cout<<"\n";
    // for(auto i : apartment) cout<<i<<" ";
    // cout<<"\n";
 
    int i=0, j=0;
    int cnt = 0;
 
    while(i<people.size() && j<apartment.size())	{
        // cout<<i<<" "<<j<<"\n";
    	if(abs(people[i]-apartment[j]) <= k)	{
            // cout<<" yes \n";
    		cnt++;
    		i++;
    		j++;
    	}
    	else {
    		if(i+1<n && j+1<m)	{
	    		if(abs(people[i+1]-apartment[j]) < abs(people[i]-apartment[j+1]) )	{
		    		i++;
		    	}
		    	else {
		    		j++;
		    	}
	    	}
	    	else {
	    		if(i+1<n)	{
	    			i++;
	    		}
	    		if(j+1<m)	{
	    			j++;
	    		}
                else {
                    i++;
                    j++;
                }
	    	}
    	}
    }
 
    cout<<cnt;
 
    return 0;
}
