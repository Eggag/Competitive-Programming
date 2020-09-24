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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, x, y;
	cin >> n >> x >> y;
	n--;
	x--, y--;
	ll a1 = min(x, y);
	ll a2 = a1 + max((x - a1), 0LL) + max((y - a1), 0LL);
	ll b1 = min(n - x, n - y);
	ll b2 = b1 + max(((n - x) - b1), 0LL) + max(((n - y) - b1), 0LL);
	if(!b2){
		cout << "Black" << endl;
		return 0;
	}
	if(a2 <= b2) cout << "White" << endl;
	else cout << "Black" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
