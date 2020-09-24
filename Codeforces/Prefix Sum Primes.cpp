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
	int ones = 0, twos = 0;
	rep(i, n){
		int x;
		cin >> x;
		if(x == 1) ones++;
		else twos++;
	}
	vi ans;
	if(!ones){
		while(twos--) cout << "2 ";
		cout << endl;
		return 0;
	}
	else if(!twos){
		while(ones--) cout << "1 ";
		cout << endl;
		return 0;
	}
	else{
		ones--, twos--;
		ans.pb(2);
		ans.pb(1);
		while(twos--) ans.pb(2);
		while(ones--) ans.pb(1);
	}
	rep(i, ans.size()) cout << ans[i] << " ";
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
