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
const int MAXN = 200005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int p[MAXN], s[4 * MAXN], s1[4 * MAXN];

void build(int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		s[id] = p[l];
		s1[id] = p[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s[id] = min(s[id * 2], s[id * 2 + 1]);
	s1[id] = max(s1[id * 2], s1[id * 2 + 1]);
}

int minQ(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return 1e9;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return min(minQ(x, y, id * 2, l, mid), minQ(x, y, id * 2 + 1, mid, r));
}

int maxQ(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return -1e9;
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return max(maxQ(x, y, id * 2, l, mid), maxQ(x, y, id * 2 + 1, mid, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int k;
	cin >> n >> k;
	rep(i, n) cin >> p[i];
	memset(s, 0, sizeof(s));
	memset(s1, 0, sizeof(s1));
	build();
	int ans = 0;
	int tot = 0;
	vi vis(n, 0);
	int f = 0;
	rep(i, n){
		if(i && (p[i] < p[i - 1])){
			//creates disorder
			vis[i - 1] = 1;
			tot++;
		}
		if(i >= k){
			if(vis[i - k]) tot--;
			if((tot || (!tot && !f)) && p[i - k] < minQ(i - k + 1, i + 1) && (p[i] >= maxQ(i - k + 1, i + 1))) ans--;
		}
		if(i >= (k - 1)){
			if(!tot && !f) f++; //because if we can't have more than 1 sorted segment
			ans += (tot > 0);
		}
	}
	cout << ans + f << endl; //f is for the one that doesn't change
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
