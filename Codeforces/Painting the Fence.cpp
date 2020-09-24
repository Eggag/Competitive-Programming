#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
vi p;
int b[5005];
int cnt1[5005], cnt2[5005];

int calc1(int l, int r){
	return cnt1[r] - cnt1[l - 1];
}

int calc2(int l, int r){
	return cnt2[r] - cnt2[l - 1];
}

bool intersect(int a, int b, int c, int d){
	if(a >= c && a <= d) return 1;
	if(b >= c && b <= d) return 1;
	if(c >= a && c <= b) return 1;
	if(d >= a && d <= b) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	int sum = 0;
	vi cnt(n + 1, 0);
	vector<pi> p(q);
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		p[i] = mp(l, r);
		for(int a = l; a <= r; a++){
			if(cnt[a] == 0) sum++;
			cnt[a]++;
		}
	}

	for(int i = 1; i <= n; i++) cnt1[i] = cnt1[i - 1] + (cnt[i] == 1);
	for(int i = 1; i <= n; i++) cnt2[i] = cnt2[i - 1] + (cnt[i] == 2);
	int ans = 0;
	for(int i = 0; i < q; i++){
		for(int j = i + 1; j < q; j++){
			if(!intersect(p[i].fi, p[i].se, p[j].fi, p[j].se)){
				ans = max(ans, sum - (calc1(p[i].fi, p[i].se) + calc1(p[j].fi, p[j].se)));
			}
			else{
				//calculate 1 for the whole range
				//then, subtract if for the intersection
				//and add the 2 for the intersection
				int l = max(p[i].fi, p[j].fi);
				int r = min(p[i].se, p[j].se);
				int l1 = min(p[i].fi, p[j].fi);
				int r1 = max(p[i].se, p[j].se);
				assert(l <= r);
				//[l, r] is the intersection range
				ans = max(ans, sum - (calc1(l1, r1) - calc1(l, r)) - calc2(l, r));
			}
        	}
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
