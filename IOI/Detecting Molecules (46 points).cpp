#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "molecules.h"
//#include "grader.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi dp[500005];

vi find_subset(int l, int r, vi w) {
	int n = w.size();
	rep(i, n){
		for(int j = r - w[i]; j >= 0; j--) if(!j || dp[j].size()){
			dp[j + w[i]] = dp[j];
			dp[j + w[i]].pb(i);
			if((j + w[i]) <= r && (j + w[i]) >= l){
				return dp[j + w[i]];
			}
		}
	}
	return vi(0);
}

/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
