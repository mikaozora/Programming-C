#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int n;
	scanf("%d", &n);
	int index[1000] = {};
	int arr[1000] = {};
	for(int i = 0; i < n; i++){
		scanf("%d", &index[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[index[i]]);
	}
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}
