#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
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

int f1[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi fl(m);
	rep(i, m){
		cin >> fl[i];
		int c;
		cin >> c;
		f1[fl[i]] = c;
	}
	sort(all(fl));
	set<int> ans;
	repn(i, 1, 101){
		int f = 1;
		rep(j, m){
			int cur = (fl[j] + i - 1) / i;
			if(f1[fl[j]] != cur){
				f = 0;
				break;
			}
		}
		if(f){
			ans.insert((n + i - 1) / i);
		}
	}
	if(ans.size() > 1) cout << -1 << endl;
	else cout << *ans.begin() << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
