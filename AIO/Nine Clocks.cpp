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

int g[10];
int mx = 1e9;
vi ans;

vector<vi> moves = {
{0, 1, 3, 4},
{0, 1, 2},
{1, 2, 4, 5},
{0, 3, 6},
{1, 3, 4, 5, 7},
{2, 5, 8},
{3, 4, 6, 7},
{6, 7, 8},
{4, 5, 7, 8}
};

void solve(int j, vi cnt, vi cur){
	if(j == 9){
		int f = 1;
		rep(i, 9){
			if((cnt[i] + g[i]) % 4 != 0){
				f = 0;
				break;
			}
		}
		if(f){
			if((int)cur.size() < mx){
				mx = cur.size();
				ans = cur;
			}
		}
		return;
	}
	rep(i, 4){
		//add i of this move
		vi cur1 = cur;
		rep(k, i) cur1.pb(j);
		vi cnt1 = cnt;
		rep(k, moves[j].size()) cnt1[moves[j][k]] += i;
		solve(j + 1, cnt1, cur1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
	rep(i, 9) cin >> g[i];
	vi emp(9, 0), emp1;
	solve(0, emp, emp1);
	rep(i, ans.size()){
		cout << ans[i] + 1;
		if(i != (int)(ans.size() - 1)) cout << " ";
	}
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
