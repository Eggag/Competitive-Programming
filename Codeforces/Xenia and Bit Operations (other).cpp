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

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int seg[(1 << 18)];

void update(int pos, int turn){
	if(turn & 1) seg[pos] = seg[pos * 2] ^ seg[pos * 2 + 1];
	else seg[pos] = seg[pos * 2] | seg[pos * 2 + 1];
	if(pos == 1) return;
	else update(pos / 2, turn + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int add = (1 << n) - 1; //# of nodes in the tree without leaves
	repn(i, 1, (1 << n) + 1){
		cin >> seg[i + add];
		update((i + add) / 2, 0);
	}
	rep(i, m){
		int p, b;
		cin >> p >> b;
		//update the segtree
		seg[p + add] = b;
		update((p + add) / 2, 0);
		cout << seg[1] << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
