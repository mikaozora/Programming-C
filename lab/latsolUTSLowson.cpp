#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i = 0, n, randI, item;
	char alpha[63] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '0'};
	char id[100][100] = {};
	char name[100][100] = {};
	char type[10][100] = {};
	int price[100] = {};
	do{
		if(i == 0){
		printf("No Products....\n\n");
	}else{
		printf("+------------------------------------------------------------------------------------+\n");
		printf("| No. | Id\t | Name\t\t\t | Type\t\t | Price\t\t |\n");
		printf("+------------------------------------------------------------------------------------+\n");
		for(int j = 0; j < i; j++){
			printf("| %d | %s\t | %s\t\t\t | %s\t\t | %d\t\t |\n", j+1, id[j], name[j], type[j], price[j]);		
		}
	}
		printf("1. Create Product\n");
		printf("2. Update Product\n");
		printf("3. Delete Product\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d", &n); getchar();
		switch(n){
			case 1:
				do{
					printf("product name [not empty]: ");
					scanf("%[^\n]", name[i]); getchar();
				}while(strlen(name[i]) == 0 || name[i][0] == ' ');
				do{
					printf("product type [Food | Beverage | Cosmetic | Others](case sensitive): ");
					scanf("%s", type[i]); getchar();
				}while(strcmp(type[i], "Food") != 0 && strcmp(type[i], "Beverage") != 0 && strcmp(type[i], "Cosmetic") != 0 && strcmp(type[i], "Others") != 0);
				do{
					printf("Product price [more than 0]: ");
					scanf("%d", &price[i]); getchar();
				}while(price[i] <= 0);
				srand(time(NULL));
				for(int j = 0; j < 10; j++){
					randI = rand()%62;
					id[i][j] = alpha[randI];
				}
				i++;
				printf("Create product success!\n");
				break;
			case 2:
				printf("update\n");
				if(i == 0){
					printf("No products....\n");
					printf("Press enter to continue..."); getchar();
				}else{
					printf("+------------------------------------------------------------------------------------+\n");
					printf("| No. | Id\t | Name\t\t\t | Type\t\t | Price\t\t |\n");
					printf("+------------------------------------------------------------------------------------+\n");
					for(int j = 0; j < i; j++){
						printf("| %d | %s\t | %s\t\t\t | %s\t\t | %d\t\t |\n", j+1, id[j], name[j], type[j], price[j]);		
					}
					do{
						printf("input product number[0 to exit] [1..%d]: ", i);
						scanf("%d", &item); getchar();
						if(item == 0){
							break;
						}else{
							do{
								printf("product name [not empty]: ");
								scanf("%[^\n]", name[item-1]); getchar();
							}while(strlen(name[item-1]) == 0 || name[item-1][0] == ' ');
							do{
								printf("product type [Food | Beverage | Cosmetic | Others](case sensitive): ");
								scanf("%s", type[item-1]); getchar();
							}while(strcmp(type[item-1], "Food") != 0 && strcmp(type[item-1], "Beverage") != 0 && strcmp(type[item-1], "Cosmetic") != 0 && strcmp(type[item-1], "Others") != 0);
							do{
								printf("Product price [more than 0]: ");
								scanf("%d", &price[item-1]); getchar();
								}while(price[item-1] <= 0);
								printf("Update product success..\n");
						}
					}while(item < 1 || item > i);
					
					
				}
				break;
			case 3:
				printf("delete\n");
				if(i == 0){
					printf("No products....\n");
					printf("Press enter to continue..."); getchar();
				}else{
					printf("+------------------------------------------------------------------------------------+\n");
					printf("| No. | Id\t | Name\t\t\t | Type\t\t | Price\t\t |\n");
					printf("+------------------------------------------------------------------------------------+\n");
					for(int j = 0; j < i; j++){
						printf("| %d | %s\t | %s\t\t\t | %s\t\t | %d\t\t |\n", j+1, id[j], name[j], type[j], price[j]);		
					}
					do{
						printf("input product number[0 to exit] [1..%d]: ", i);
						scanf("%d", &item); getchar();
						if(item == 0){
							break;
						}else{
							for(int j = item-1; j < i; j++){
								strcpy(id[j], id[j+1]);
								strcpy(name[j], name[j+1]);
								strcpy(type[j], type[j+1]);
								price[j] = price[j+1];
							}
							i--;
							printf("delete succes\n");
						}
					}while(item < 1 || item > i);	
				}
				break;
			case 4:
				break;
			default:
				printf("Please input a valid number\n");
				break;
		}
	}while(n != 4);
	
}
