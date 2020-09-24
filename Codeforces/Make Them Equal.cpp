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
	int n;
	cin >> n;
	int a[n];
	rep(i, n) cin >> a[i];
	sort(a, a + n);
	vi b;
	b.pb(a[0]);
	repn(i, 1, n){
		if(a[i] != a[i - 1]) b.pb(a[i]);
	}
	if(b.size() > 3){
		cout << "-1" << endl;
		return 0;
	}
	if(b.size() == 3){
		if((b[2] - b[1]) == (b[1] - b[0])){
			cout << b[2] - b[1] << endl;
		}
		else{
			cout << "-1" << endl;
		}
		return 0;
	}
	if(b.size() == 2){
		if((b[1] - b[0]) % 2 == 0){
			cout << (b[1] - b[0]) / 2 << endl;
		}
		else{
			cout << b[1] - b[0] << endl;
		}
		return 0;
	}
	if(b.size() == 1){
		cout << "0" << endl;
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
