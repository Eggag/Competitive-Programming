#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll lon, squ, tri, lle, lri, zri, zle;
	cin >> lon >> squ >> tri >> lle >> lri >> zri >> zle;
	ll tot = squ * 2;
	int sm = (lon & 1) + (lle & 1) + (lri & 1);
	if(lon && lle && lri && sm >= 2) tot += 6, lon--, lle--, lri--;
	tot += 4 * (lle / 2);
	tot += 4 * (lri / 2);
	tot += (lon / 2) * 4;
	cout << tot / 2 << endl;
	return 0;
}
