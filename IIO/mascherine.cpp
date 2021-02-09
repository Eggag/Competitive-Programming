#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void riprogramma(int n, int k, vi &c){
	if(k == 2){
		int tot = 0, tot1 = 0;
		rep(i, n){
			if(i & 1) tot += (c[i] != 1);
			else tot += (c[i] == 1);
		}
		rep(i, n){
			if(i % 2 == 0) tot1 += (c[i] != 1);
			else tot1 += (c[i] == 1);
		}
		if(tot < tot1){
			rep(i, n){
				if(i & 1) c[i] = 1;
				else c[i] = 2;
			}
		}
		else{
			rep(i, n){
				if(i & 1) c[i] = 2;
				else c[i] = 1;
			}
		}
	}
	else{
		rep(i, n){
			int l = i;
			while(i < (n - 1) && c[i + 1] == c[i]) i++;
			int af = (i < (n - 1) ? c[i + 1] : -1);
			repn(j, 1, 4) if(j != af && j != c[l]){
				for(int k = l + 1; k <= i; k += 2) c[k] = j;
				break;
			}
		}	
	}
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
