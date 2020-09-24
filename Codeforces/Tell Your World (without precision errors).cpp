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

int n;
ll y[1005];

bool test(){
	ld diff = y[1] - y[0];
	repn(i, 2, n) if((y[i] - y[i - 1]) != diff) return 0;
	return 1;
}

bool test1(int a, int b){
	ll dy = (y[b] - y[a]);
	ll dx = (b - a);
	vi vis(n, 0);
	vis[a] = 1, vis[b] = 1;
	repn(i, b + 1, n) if((dx * (y[i] - y[b])) == (dy * (i - b))) vis[i] = 1;
	int st = 0;
	rep(i, n) if(!vis[i]){
		st = i;
		break;
	}
	repn(i, st + 1, n) if(!vis[i]){
		if((dx * (y[i] - y[st])) != (dy * (i - st))) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) cin >> y[i];	
	if(test()){
		cout << "No" << endl;
		return 0;
	}
	if(test1(0, 1) || test1(1, 2) || test1(0, 2)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
