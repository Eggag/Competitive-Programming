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

int ask(int l, int r){
	cout << "? " << l << " " << r << endl;
	int ret;
	cin >> ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int pos = ask(1, n);
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		if(pos <= mid){
			if(1 == mid){
				l = mid + 1;
				continue;
			}
			int nw = ask(1, mid);
			if(nw == pos) r = mid;
			else l = mid + 1;
		}
		else{
			if((mid + 1) == n){
				r = mid;
				continue;
			}
			int nw = ask(mid + 1, n);
			if(nw == pos) l = mid + 1;
			else r = mid;
		}
	}
	cout << "! " << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
