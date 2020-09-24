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
	set<int> cnt;
	rep(i, n) cin >> a[i], cnt.insert(a[i]);
	vi ans = {a[0]};
	rep(i, n){
		if(ans.size() == 3) break;
		rep(j, 31){
			if(ans.size() == 1){
				if((INT_MAX - (1 << j) >= a[i]) && cnt.find(a[i] + (1 << j)) != cnt.end()){
					ans = {a[i], a[i] + (1 << j)};
				}
				if((INT_MIN + (1 << j) <= a[i]) && cnt.find(a[i] - (1 << j)) != cnt.end()){
					ans = {a[i], a[i] - (1 << j)};
				}
			}
			if(((INT_MAX - (1 << j) >= a[i]) && (INT_MIN + (1 << j) <= a[i])) && cnt.find(a[i] - (1 << j)) != cnt.end() && cnt.find(a[i] + (1 << j)) != cnt.end()){
				if(ans.size() == 2){
					ans = {a[i], a[i] - (1 << j), a[i] + (1 << j)};
				}
			}
		}
	}
	cout << ans.size() << endl;
	for(int x : ans) cout << x << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
