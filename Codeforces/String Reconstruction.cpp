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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int st[2000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	memset(st, -1, sizeof(st));
	int mx = 0;
	string s[n];
	rep(i, n){
		cin >> s[i];
		int k;
		cin >> k;
		rep(j, k){
			int x;
			cin >> x;
			x--;
			if(st[x] == -1) st[x] = i;
			else if((int)s[i].length() > (int)s[st[x]].length()) st[x] = i;
			mx = max(mx, (int)(x + (int)s[i].length()));
		}
	}
	int cur = -1;
	int l = -1, r = -1;
	rep(i, mx){
		if(i > r && st[i] == -1) cout << 'a';
		else if(i > r && st[i] == -1){
			cur = st[i];
			l = i, r = i + (int)s[cur].length() - 1;
			cout << s[cur][i - l];
		}
		else{
			if(st[i] != -1 && (i + (int)s[st[i]].length() - 1) > r){
				cur = st[i];
				l = i, r = i + (int)s[cur].length() - 1;
			}
			cout << s[cur][i - l];
		}
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
