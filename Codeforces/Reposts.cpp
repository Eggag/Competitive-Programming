#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

map<string, int> res;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int ans = 1;
	res["polycarp"] = 1;
	for(int i = 0; i < n; i++){
		string a, c, b;
		cin >> a >> c >> b;
		transform(a.begin(), a.end(), a.begin(), ::tolower);	
		transform(b.begin(), b.end(), b.begin(), ::tolower);
		res[a] = max(res[a], res[b] + 1);
		ans = max(ans, res[a]);
	}
	cout << ans << endl;	
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
