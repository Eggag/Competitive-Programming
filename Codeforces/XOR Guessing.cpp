#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
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
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int qry(vi q){
	cout << '?';
	rep(i, q.size()) cout << ' ' << q[i];
	cout << endl;
	int res;
	cin >> res;
	return res;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	vi q1;
	rep(i, 1 << 14){
		int f = 1;
		rep(j, 7){
			if(i & (1 << j)){
				f = 0;
				break;
			}
		}
		if(f) q1.pb(i);
		if(q1.size() == 100) break;
	}
	int a1 = qry(q1); //the first 7 bits of the answer
	int ans = 0;
	rep(i, 7) if(a1 & (1 << i)) ans |= (1 << i);
	q1.clear();
	rep(i, 1 << 14) if(i){
		int f = 1;
		repn(j, 7, 14){
			if(i & (1 << j)){
				f = 0;
				break;
			}
		}
		if(f) q1.pb(i);
		if(q1.size() == 100) break;
	}
	a1 = qry(q1); //the first 7 bits of the answer
	repn(i, 7, 14) if(a1 & (1 << i)) ans |= (1 << i);
	cout << "! " << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
