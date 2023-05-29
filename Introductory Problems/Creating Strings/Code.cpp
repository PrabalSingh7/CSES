#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
 
 
void fun(int n, string s, string util, set<string> &st, vector<string> &res)	{
	if(s.size()==0)	{
		if(st.find(util)==st.end() )	{
			res.push_back(util);
			st.insert(util);
		}
		return;
	}
 
	for(int i=0; i<s.size(); i++)	{
		string temp_s = s;
		char ch = s[i];
		temp_s.erase(temp_s.begin()+i);
		string temp_u = util;
		temp_u += ch;
		fun(n,temp_s,temp_u,st,res);
	}
 
	return;
}
 
 
int main()	{
	
	string s;
	cin>>s;
	set<string> st;
 
	int n = s.size();
	sort(s.begin(), s.end());
 
    vector<string> res;
 
	string t;
	fun(n,s,t,st,res);
 
    cout<<res.size()<<"\n";
    for(auto it:res)    cout<<it<<"\n";
 
	return 0;
}