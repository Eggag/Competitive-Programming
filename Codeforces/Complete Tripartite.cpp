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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int col[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	//we make 0, and everything NOT adjacent to it color 1
	set<int> st(all(g[0]));
	int f = 0;
	int num1 = 0, num2 = 0, num3 = 0;
	rep(i, n) if(st.find(i) == st.end()){
		col[i] = 1;
		f |= 1;
		num1++;
	}
	int gd = -1;
	rep(i, n) if(!col[i]) gd = i;
	set<int> st1(all(g[gd]));
	rep(i, n) if(st1.find(i) == st1.end()){
		if(col[i]){
			cout << -1 << endl;
			return 0;
		}
		col[i] = 2;
		num2++;
		f |= 2;
	}
	rep(i, n) if(!col[i]) col[i] = 3, f |= 4, num3++;
	if(f < 7){
		cout << -1 << endl;
		return 0;
	}
	rep(i, n){
		int nm1 = 0, nm2 = 0, nm3 = 0;
		for(int j : g[i]){
			if(col[j] == 1) nm1++;
			if(col[j] == 2) nm2++;
			if(col[j] == 3) nm3++;
		}
		if(col[i] == 1){
			if(nm1 || nm2 != num2 || nm3 != num3){
				cout << -1 << endl;
				return 0;
			}
		}
		if(col[i] == 2){
			if(nm1 != num1 || nm2 || nm3 != num3){
				cout << -1 << endl;
				return 0;
			}
		}
		if(col[i] == 3){
			if(nm1 != num1 || nm2 != num2 || nm3){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	rep(i, n) cout << col[i] << " ";
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
