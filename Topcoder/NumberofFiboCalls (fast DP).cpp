#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int dp0[45];
int dp1[45];

struct NumberofFiboCalls{
	vi fiboCallsMade(int n){
             	ios_base::sync_with_stdio(false);
            	dp0[0] = 1;
            	dp1[0] = 0;
            	dp0[1] = 0;
            	dp1[1] = 1; 	
            	repn(i, 2, n + 1){
            		dp0[i] = dp0[i - 1] + dp0[i - 2];
            		dp1[i] = dp1[i - 1] + dp1[i - 2];
            	}
            	return {dp0[n], dp1[n]};
	}
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/