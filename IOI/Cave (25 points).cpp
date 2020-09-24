#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "cave.h"
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

void exploreCave(int n){
	int ans[n];
	rep(i, n) ans[i] = 0;
	//we know the ans for each
	//try turning them to one by one and watching which one is triggered
	int ans1[n];
	rep(i, n) ans1[i] = i;
	if(tryCombination(ans)){
		rep(i, n){
			ans[i] = 1; //closing one
			int res = tryCombination(ans);
			ans1[i] = res;
			ans[i] = 0;
		}	
	}
	else{
		rep(i, n){
			int res = tryCombination(ans);
			if(res == i) ans[i] = 1;
		}
	}
	answer(ans, ans1);
}

/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
