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

int n, k;
int a[500005];
int sto[500005];
int m[1000005];

bool check(int len){
	memset(m, 0, sizeof(m));
	int cnt = 0;
	rep(i, len){
		if(!m[a[i]]) cnt++;
		m[a[i]]++;
	}
	if(cnt <= k){
		sto[len] = 0;
		return 1;
	}
	repn(i, len, n){
		if(m[a[i - len]] == 1) cnt--;
		m[a[i - len]]--;
		if(!m[a[i]]) cnt++;
		m[a[i]]++;
		if(cnt <= k){
			sto[len] = i - len + 1;
			return 1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	//scanf("%d%d", &n, &k);
	cin >> n >> k;
	//rep(i, n) scanf("%d", &a[i]);
	rep(i, n) cin >> a[i];
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	//printf("%d %d\n", sto[l] + 1, sto[l] + l);
	cout << sto[l] + 1 << " " << sto[l] + l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
