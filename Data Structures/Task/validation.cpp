#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(){
//	char email[100] = "mika";
//	char *res;
//	res = strrchr(email, '@');
//	if(strcmp(res, "@gmail.com") == 0){
//		printf("lolos\n");
//	}else{
//		printf("tidak lolos");
//	}
	// YYXXX
	srand(time(NULL));
	for(int i = 0; i < 20; i++){
		int a = (rand() % (90 - 65 + 1)) + 65;
	int b = (rand() % (90 - 65 + 1)) + 65;
	int c = (rand() % (999 - 100 + 1)) + 100;
	char id[100] = {};
	sprintf(id, "%c%c%d", a, b, c);
	printf("%s\n", id);
	}
	
	return 0;
}
