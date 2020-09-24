#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	pi a[m];
	rep(i, m){
		cin >> a[i].fi >> a[i].se;
	}
	int f = a[0].fi;
	int s = 0;
	rep(i, m){
		if(a[i].fi != f && a[i].se != f){
			if(a[i].fi != s && a[i].se != s){
				if(s == 0) s = a[i].fi;
				else break;
			}
		}
		if(i == m - 1){
			cout << "YES" << endl;
			return 0;
		}
	}
	f = a[0].fi;
	s = 0;
	rep(i, m){
		if(a[i].fi != f && a[i].se != f){
			if(a[i].fi != s && a[i].se != s){
				if(s == 0) s = a[i].se;
				else break;
			}
		}
		if(i == m - 1){
			cout << "YES" << endl;
			return 0;
		}
	}
	f = a[0].se;
	s = 0;
	rep(i, m){
		if(a[i].fi != f && a[i].se != f){
			if(a[i].fi != s && a[i].se != s){
				if(s == 0) s = a[i].fi;
				else break;
			}
		}
		if(i == m - 1){
			cout << "YES" << endl;
			return 0;
		}
	}
	f = a[0].se;
	s = 0;
	rep(i, m){
		if(a[i].fi != f && a[i].se != f){
			if(a[i].fi != s && a[i].se != s){
				if(s == 0) s = a[i].se;
				else break;
			}
		}
		if(i == m - 1){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
