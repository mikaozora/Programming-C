#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int n;
	scanf("%d", &n); getchar();
	for(int i = 1; i <= n; i++){
		int result[26] = {};
		int ascii[127] = {};
		char str[10000] = {};
		scanf("%[^\n]", str); getchar();
		strupr(str);
		for(int j = 0; j < strlen(str); j++){
			if(str[j] >= 'A' && str[j] <= 'Z'){
				ascii[str[j]] = 1;
			}
			
		}
		int k = 0;
		int res = 1;
		for(int j = 0; j < 127; j++){
			if(ascii[j] == 1){
				result[k] = 1;
				k++;
			}
		}
		for(int j = 0; j < 26; j++){
			if(result[j] != 1){
				res = 0;
			}
		}
		printf("Case #%d: ", i);
		if(res == 0){
			printf("Not panagram\n");
		}else{
			printf("Its panagram\n");
		}
	}
	
}
