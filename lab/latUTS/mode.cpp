#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int n, length;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int arr[100] = {};
		int index[10000] = {};
		int max = 0;
		scanf("%d", &length);
		for(int j = 0; j < length; j++){
			scanf("%d", &arr[j]);
			index[arr[j]]++;
		}
		max = index[0];
		for(int j = 0; j < length; j++){
			if(max < index[j]){
				max = index[j];
			}
		}
		printf("jummlah : %d\n", max);
		for(int j = 0; j < length; j++){
			if(index[j] == max){
				printf("%d ", j);
			}
		}
		printf("\n");
	}
}
