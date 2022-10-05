#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int n, length;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int index=0;
		char str[501] = {};
		char str2[501] = {};
		char temp[501] = {};
		scanf("%s", str);
//		length = strlen(str);
//		for(int j = 0; j < length/2; j++){
//			temp[j] = str[j];
//			str[j] = str2[length-j-1];
//			str2[length-j-1] = temp[j];
//		}
		for(int j = strlen(str)-1; j >= 0; j--){
			str2[index] = str[j];
			index++;
		}
		printf("Case #%d: ", i);
		if(strcmp(str, str2) == 0){
			printf("Yey, its palindrome\n");
		}else{
			printf("Nah, its not palindrome\n");
		}
		
	}
}
