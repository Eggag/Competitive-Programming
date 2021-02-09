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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[mxN];

int query(int ind){
	if(ind == -1 || ind == n) return 1e9;
	if(a[ind]) return a[ind];
	cout << "? " << ind + 1 << endl;
	int ret;
	cin >> ret;
	a[ind] = ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	if(n == 1){
		cout << "! 1" << endl;
		return 0;
	}
	int l = 0, r = n - 1;
	while(l < r){
		int mid = (l + r) / 2;
		int cur = query(mid);
		int le = query(mid - 1), ri = query(mid + 1);
		if(cur < min(le, ri)){
			cout << "! " << mid + 1 << endl;
			return 0;
		}
		if(cur > le) r = mid - 1;
		else l = mid + 1;
	}
	cout << "! " << l + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
