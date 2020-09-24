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
const int mxN = 105;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int cnt[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i], cnt[a[i]]++;
	sort(all(a));
	if(a[n - 2] != a[n - 1]){
		cout << "Impossible" << endl;
		return 0;
	}
	if(a[n - 1] == 1){
		if(n == 2) cout << "Possible" << endl;
		else cout << "Impossible" << endl;
		return 0;
	}
	int us = cnt[a[n - 1]];
	a[n - 1]--;
	int cur = a[n - 1];
	rep(i, a[n - 1] / 2){
		us += cnt[cur];
		if(cnt[cur] < 2 || ((i == ((a[n - 1] / 2) - 1)) && cnt[cur] > 2 && (a[n - 1] % 2 == 0))){
			cout << "Impossible" << endl;
			return 0;
		}
		cur--;
	}
	if(a[n - 1] & 1){
		us += cnt[cur];
		if(cnt[cur] != 1){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	if(us != n) cout << "Impossible" << endl;
	else cout << "Possible" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
