#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
 
// int main()	{
 
//     int n;
//     cin>>n;
 
//     vector<int> vec;
//     for(int i=1; i<=n; i++)	{
//         int x;
//     	cin>>x;
//     	vec.push_back(x);
//     }
 
//     int rounds = 0;
//     int tf = 1;
 
//     while(tf!=n+1)  {
//         rounds++;
//         for(int i=0; i<vec.size(); i++) {
//             if(vec[i]==tf)  {
//                 tf++;
//                 vec.erase(vec.begin()+i);
//                 i--;
//             }
//         }
//     }
 
//     cout<<rounds;
//     return 0;
// }
 
 
 
 
 
int main()	{
 
    int n;
    cin>>n;
 
    vector<pi> vec;
    for(int i=1; i<=n; i++)	{
        int x;
    	cin>>x;
    	vec.push_back({x,i});
    }
    sort(vec.begin(), vec.end());
 
    int count=1, mx_idx_yet=0;
    for(int i=1; i<n; i++)  {
        if(vec[i-1].second > vec[i].second )    {
            count++;
        }
    }
 
    cout<<count;
    return 0;
}