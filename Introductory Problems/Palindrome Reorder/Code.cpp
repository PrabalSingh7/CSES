#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()	{
	string s;
	cin>>s;
    
	vector<int> vec(26,0);
 
	for(auto it : s)
		vec[it-'A']++;
 
	int ch = -1;
	for(int i=0; i<26; i++)	{
		if(vec[i]%2!=0)	{
			if(ch!=-1)	{
				cout<<"NO SOLUTION";
				return 0;
			}
			else {
				ch = i;
			}
		}
	}
 
	for(int i=0; i<26; i++)	{
		if(i!=ch && vec[i]!=0)	{
			int freq = vec[i]/2;
			char alpha = 'A'+i;
			for(int k=0; k<freq; k++)	
				cout<<alpha;
		}
	}
 
	if(ch!=-1)	{
		int freq = vec[ch];
		char alpha = 'A'+ch;
			for(int k=0; k<freq; k++)	
				cout<<alpha;
	}
	
	for(int i=25; i>=0; i--)	{
		if(i!=ch && vec[i]!=0)	{
			int freq = vec[i]/2;
			char alpha = 'A'+i;
			for(int k=0; k<freq; k++)	
				cout<<alpha;
		}
	}
 
 
	return 0;
}