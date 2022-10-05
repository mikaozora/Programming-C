#include <stdio.h>
#include <string.h>

int main(){
	char str[1000000] = {};
	int ascii[150] = {};
	int vocal = 0, cons = 0;
	scanf("%[^\n]", str);
	for(int i = 0; i < strlen(str); i++){
		ascii[str[i]] = 1;
	}
	for(int i = 0; i < 150; i++){
		if(ascii[i] == 1){
			if(i == 'a' || i == 'i' || i == 'u' || i == 'e' || i == 'o'){
				vocal++;
			}else if(i == ' '){
				continue;
			}else{
				cons++;
			}
		}
	}
	printf("vocal: %d\nconsonant: %d", vocal, cons);
}
