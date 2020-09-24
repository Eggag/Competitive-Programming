#include <cstdio>
#include <float.h>
#include <vector>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		float k;
		scanf("%d%f", &n, &k);
		vector<float> w(n);
		float sum = 0;
		for(int i = 0; i < n; i++) scanf("%f", &w[i]), sum += w[i];
		for(int i = 0; i < n; i++){
			printf("%f ", (w[i] + ((k * w[i]) / sum)));
		}
		printf("\n");
	}
	return 0;
}
