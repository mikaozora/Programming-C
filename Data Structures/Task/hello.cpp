#include <stdio.h>
#include <string.h>


char *generateId(const char *name){
	char temp[100] = {};
	sprintf(temp, "%05d - %s", 1, name);
//	printf("%s", temp);
	return temp;
}

int main(){
	char *name = "mika";
	
	char *id = generateId(name);
	printf("%s\n", id);
	return 0;
}
