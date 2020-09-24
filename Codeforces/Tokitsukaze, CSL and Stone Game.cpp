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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	map<int, int> cnt;
	rep(i, n) cin >> a[i], cnt[a[i]]++;
	int num = 0;
	for(pi x : cnt){
		if(x.fi == 0 && x.se > 1){
			cout << "cslnb" << endl;
			return 0;
		}
		if(x.se > 2){
			cout << "cslnb" << endl;
			return 0;
		}
		if(x.se == 2 && cnt[x.fi - 1] > 0){
			cout << "cslnb" << endl;
			return 0;
		}
		if(x.se == 2) num++;
	}
	if(num > 1){
		cout << "cslnb" << endl;
		return 0;
	}
	sort(all(a));
	int ans = 0, cur = 1;
	ans += a[0];
	repn(i, 1, n){
		ans += max(0, a[i] - cur);
		cur++;
	}
	cout << (ans & 1 ? "sjfnb" : "cslnb") << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
