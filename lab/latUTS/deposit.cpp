#include <stdio.h>
#include <string.h>

int main(){
	double r, t, y;
	int n;
	long long int p;
	
	scanf("%d %lld", &n, &p);
	for(int i = 0; i < n; i++){
		scanf("%lf %lf", &r, &t);
		y = t/12;
		p += ((p * r * y) / 100);
	}
	printf("%lld", p);
}
