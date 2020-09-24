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

struct HASH{
	size_t operator () (const pair<int, int> &x) const {
		return hash<long long>()(((long long)(x.first)) ^ (((long long)(x.second)) << 32));
	}
};

vi st;
unordered_map<pair<int, int>, int, HASH> vis;

void solve(int num, int sum){
	vis[mp(num, sum)] = 1;
	if(num == 1){
		st.pb(sum);
		return;
	}
	for(int i = 1; (i * i) <= num; i++){
		if(num % i == 0){
			if(i != 1){
				if(!vis[mp(num / i, sum + i - 1)]){
					solve(num / i, sum + i - 1);
				}
			}
			if(num / i != i && (num / i) != 1){
				if(!vis[mp(num / (num / i), sum + num / i - 1)]){
					solve(num / (num / i), sum + num / i - 1);
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	solve(n, 0);
	sort(all(st));
	vi b = {st[0]};
	repn(i, 1, st.size()) if(st[i] != st[i - 1]) b.pb(st[i]);
	cout << b.size() << endl;
	for(int x : b) cout << x << " ";
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
