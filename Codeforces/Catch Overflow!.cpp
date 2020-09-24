#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const ll maxn = ((1LL << 32) - 1);

string s[100005];
int p[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	repn(i, 1, n + 1){
		cin >> s[i];
		if(s[i] == "for") cin >> p[i];
	}
	ll ans = 0;
	vector<ll> e = {1};
	repn(i, 1, n + 1){
		if(s[i] == "for"){
			e.pb(1LL * e[e.size() - 1] * p[i]);
			if(e[e.size() - 1] >= (1LL << 32)) e[e.size() - 1] = (1LL << 32);
		}
		else if(s[i] == "add"){
			ans += e[e.size() - 1];
		}
		else e.pop_back();
	}
	if(ans > maxn) cout << "OVERFLOW!!!" << endl;
	else cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
