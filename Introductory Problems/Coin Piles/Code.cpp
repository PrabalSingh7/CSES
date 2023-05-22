#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()	{
	int n;
	cin>>n;
 
	while(n--)	{
		int a,b;
		cin>>a>>b;
 
		if( (max(a,b)<=min(a,b)*2) && ((a+b)%3==0) )
			cout<<"YES";
		else 
			cout<<"NO";
 
		cout<<"\n";
	}
 
	return 0;
}