#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pl;
 
ll mod = 1000000007;
 
// ll dp[1000001] = {-1};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll N;
    cin >> N;
    
    ll dp[6]; 
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 8;
    dp[4] = 16;
    dp[5] = 32;
 
    if(N<6)	{
    	cout<<dp[N-1];
    	return 0;
	}
    
    ll curr = 0;
    for(int ni=6; ni<N; ni++)  {
        curr = dp[0]+dp[1]+dp[2]+dp[3]+dp[4]+dp[5];
        curr %= mod;
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[3];
        dp[3] = dp[4];
        dp[4] = dp[5];
        dp[5] = curr;
    }
    
    cout<<dp[5];
    return 0;
}