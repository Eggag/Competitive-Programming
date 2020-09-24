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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int g = 0;
	int c[n];
	memset(c, 0, sizeof(c));
	for(int i = 1; i < n; i++){
		if(s1[i] != s2[i] && s1[i - 1] != s2[i - 1] && s1[i] != s1[i - 1] && !c[i - 1]){
			g++;
			c[i] = 1;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s1[i] != s2[i]) ans++;
	}
	cout << ans - g << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
