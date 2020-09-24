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
const int MOD = 1e9 + 7;
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll a[mxN];
vector<ll> pos, neg;
int n, k;

void solveNeg(){
	reverse(all(pos));
	reverse(all(neg));
	int st = 0;
	for(int i = k; i >= 0; i--) if((k - i) & 1){
		if(pos.size() >= i){
			st = i;
			break;
		}
	}
	int cur = pos.size() - st;
	int negInd = k - st;
	for(int i = st; i >= 0; i -= 2){
		if(cur < (int)(pos.size() - 1) && negInd < (int)(neg.size() - 1) && (neg[negInd] * neg[negInd + 1]) < (pos[cur] * pos[cur + 1])){
			cur += 2;
			negInd += 2;
		}
	}
	ll ans = 1LL;
	rep(i, negInd) ((ans *= neg[i]) += MOD) %= MOD;
	repn(i, cur, pos.size()) ((ans *= pos[i]) += MOD) %= MOD;
	cout << (ans + 2 * MOD) % MOD << endl;
	exit(0);
}

void solvePos(){
	int st = 0;
	for(int i = k; i >= 0; i--) if((k - i) % 2 == 0){
		if(pos.size() >= i){
			st = i;
			break;
		}
	}
	int cur = (int)pos.size() - st;
	int negInd = k - st;
	for(int i = st; i >= 0; i -= 2){
		if(cur < (int)(pos.size() - 1) && negInd < (int)(neg.size() - 1) && (neg[negInd] * neg[negInd + 1]) > (pos[cur] * pos[cur + 1])){
			cur += 2;
			negInd += 2;
		}
	}
	ll ans = 1LL;
	rep(i, negInd) ((ans *= -neg[i]) %= MOD) %= MOD;
	repn(i, cur, pos.size()) ((ans *= pos[i]) += MOD) %= MOD;
	cout << (ans + MOD) % MOD << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	rep(i, n){
		cin >> a[i];
		if(a[i] < 0) neg.pb(a[i]);
		else pos.pb(a[i]);
	}
	sort(all(pos));
	sort(all(neg));
	if((int)pos.size() >= k) solvePos();
	for(int i = 2; i <= (int)neg.size(); i += 2) if(k >= i && (int)pos.size() >= (k - i)) solvePos();	
	solveNeg();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
