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

string t[105];
int m[105], k[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("traffic.in", "r", stdin);
        freopen("traffic.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t[i] >> m[i] >> k[i];
	}
	int l = -1005, r = 1005;
	for(int i = n - 1; i >= 0; i--){
		if(t[i] == "none") l = max(m[i], l), r = min(r, k[i]);
		if(t[i] == "off") l += m[i], r += k[i];
		if(t[i] == "on") l -= k[i], r -= m[i], l = max(l, 0);
	}
	cout << l << " " << r << endl;
	l = -1005, r = 1005;
        for(int i = 0; i < n; i++){
                if(t[i] == "none") l = max(m[i], l), r = min(r, k[i]);
                if(t[i] == "on") l += m[i], r += k[i];
                if(t[i] == "off") l -= k[i], r -= m[i], l = max(0, l);
        }
        cout << l << " " << r << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
