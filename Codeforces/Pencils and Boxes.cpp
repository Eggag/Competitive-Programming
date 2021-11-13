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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[mxN];
int bit[mxN];

void add(int ind, int val){
        for(ind++; ind < mxN; ind += (ind & (-ind))){
                bit[ind] += val;
        }
}

int qry(int ind){
        int sum = 0;
        for(ind++; ind > 0; ind -= (ind & (-ind))){
                sum += bit[ind];
        }
        return sum;
}

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        //freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
        int n, k, d;
        cin >> n >> k >> d;
        repn(i, 1, n + 1) cin >> a[i];
        sort(a + 1, a + (n + 1));
        add(0, 1);
        add(1, -1);
        repn(i, 1, n + 1) if(qry(i - 1)){
                int l = i, r = n;
                while(l < r){
                        int mid = (l + r + 1) / 2;
                        if(a[mid] - a[i] <= d) l = mid;
                        else r = mid - 1;
                }
                int le = i + (k - 1), ri = l;
                if(le <= ri){
                        add(le, 1);
                        add(ri + 1, -1);
                }
        }
        cout << (qry(n) ? "YES" : "NO") << '\n';
        return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
