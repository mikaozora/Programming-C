#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		char str1[1000000] = {};
		char str2[1000000] = {};
		char ch1[10000] = {};
		char ch2[10000] = {};
		int res = 1;
		scanf("%s %s", str1, str2); getchar();
		int result[strlen(str1)+1] = {};
		for(int j = 0; j < strlen(str1); j++){
			str1[j] = tolower(str1[j]);
			ch1[j] = str1[j];
		}
		for(int j = 0; j < strlen(str2); j++){
			str2[j] = tolower(str2[j]);
			ch2[j] = str2[j];
		}
		if(strlen(str1) != strlen(str2)){
			printf("No, it's not anagram\n'");
		}
		else{
			for(int j = 0; j < strlen(str1); j++){
				for(int k = 0; k < strlen(str2); k++){
					if(ch2[k] == ch1[j]){
						result[j] = 1;
					}
				}
			}
			for(int j = 0; j < strlen(str1); j++){
				if(result[j] != 1){
					res = 0;
				}
			}
			printf("Case #%d: ", i);
			if(res == 0){
				printf("No, it's not anagram\n");
			}else{
				printf("Yes, it's anagram\n");
			}
		}
		
	}
	
}
