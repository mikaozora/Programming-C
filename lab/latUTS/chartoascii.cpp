#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		char str[1001] = {};
		int space = 0;
		scanf("%s", str);
		printf("Case #%d: ", i);
		for(int j = 0; j < strlen(str); j++){
			printf("%s%d", (space == 0 ? "" : "-"), str[j]);
			space++;
		}
		printf("\n");
	}
}
