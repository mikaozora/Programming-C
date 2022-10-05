#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main(){

	char id[50][25] = {};
	char name[50][50] = {};
	double price[50] = {};
	int n, i=0, item = 0, disc;
	char choice[10] = {};
	do{
		printf("Electronics!\n");
		printf("===============!\n");
		printf("1. Insert Electronic Stock!\n");
		printf("2. Update electronic!\n");
		printf("3. Sell elctronic\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d", &n);
		switch(n){
			case 1:
				do{
					printf("input id [must 3 digit number]: ");
					scanf("%s", id[i]); getchar();
				}while(strlen(id[i]) != 3 || isdigit(id[i][0]) == 0 || isdigit(id[i][1]) == 0 || isdigit(id[i][2]) == 0);
				do{
					printf("input name [must beetween 5 and 25]: ");
					scanf("%s", name[i]); getchar();
				}while(strlen(name[i]) < 5 || strlen(name[i]) > 25);
				do{
					printf("input price [not more than 5M]: ");
					scanf("%lf", &price[i]); getchar();
				}while(price[i] > 5000000);
				i++;
				printf("item succesfully inserted!\n");
				printf("press enter to continue..."); 
				getchar();
				break;
			case 2:
				if(i == 0){
					printf("there is no item yet...\n");
					printf("press enter to continue..."); getchar();
				}else{
					printf("update\n");
					printf("=============================================================\n");
					printf("| No. | Id\t | Name\t\t\t | Price\t\t |\n");
					printf("=============================================================\n");
					for(int j = 0; j < i; j++){
						printf("| %d. | ETC%s\t | %s\t\t\t | %.2lf\t\t |\n", j+1, id[j], name[j], price[j]);
					}
					do{
						printf("which item you want to delete [0 to exit] [1..%d]: ", i);
						scanf("%d", &item);
						if(item == 0){
							break;
						}else{
							do{
								printf("input id [must 3 digit number]: ");
								scanf("%s", id[item-1]); getchar();
							}while(strlen(id[item-1]) != 3 || isdigit(id[item-1][0]) == 0 || isdigit(id[item-1][1]) == 0 || isdigit(id[item-1][2]) == 0);
							do{
								printf("input name [must beetween 5 and 25]: ");
								scanf("%s", name[item-1]); getchar();
							}while(strlen(name[item-1]) < 5 || strlen(name[item-1]) > 25);
							do{
								printf("input price [not more than 5M]: ");
								scanf("%lf", &price[item-1]); getchar();
							}while(price[item-1] > 5000000);
							printf("Item successfully updated!\n");
							printf("press enter to continue..."); getchar();
						}
					}while(item < 1 || item > i);
				}
				break;
			case 3:
				printf("delete\n");
				if(i == 0){
					printf("there is no item yet...\n");
					printf("press enter to continue..."); getchar();
				}else{
					printf("update\n");
					printf("=============================================================\n");
					printf("| No. | Id\t | Name\t\t\t | Price\t\t |\n");
					printf("=============================================================\n");
					for(int j = 0; j < i; j++){
						printf("| %d. | ETC%s\t | %s\t\t\t | %.2lf\t\t |\n", j+1, id[j], name[j], price[j]);
					}
					do{
						printf("which item you want to delete [0 to exit][1..%d]: ", i);
						scanf("%d", &item); getchar();
						if(item == 0){
							break;
						}else{
							srand(time(NULL));
							disc = rand()%10 + 1;
							if(disc == 1 || disc == 2 || disc == 3){
								printf("#################\n");
								printf("Customer get discount 25%\n");
								printf("#################\n\n");
								printf("ETC%s Item Detail\n", id[item-1]);
								printf("============================\n");
								printf("item name: %s\n", name[item-1]);
								printf("item price: %.2lf\n", price[item-1] * 0.75);
								
							}else{
								printf("ETC%s Item Detail\n", id[item-1]);
								printf("============================\n");
								printf("item name: %s\n", name[item-1]);
								printf("item price: %.2lf\n", price[item-1]);
							}
						}
					}while(item < 1 || item > i);
					do{
						printf("are you sure to delete this?[yes/no]: ");
						scanf("%s", choice); getchar();
					}while(strcmp(choice, "yes") != 0 && strcmp(choice, "no") != 0);
					if(strcmp(choice, "yes") == 0){
						for(int j = item-1; j < i; j++){
							strcpy(id[j], id[j+1]);
							strcpy(name[j], name[j+1]);
							price[j] = price[j+1];
						}
						i--;
						printf("item succesfully deleted!\n");
						printf("press enter to continur..."); getchar();
					}else{
						printf("cancel selling!\n");
						printf("press enter to continue..."); getchar();
					}
				}
				break;
			case 4:
				printf("Thanks for using this app\n");
				break;
			default:
				printf("please input a valid number\n");
				break;
		}
	}while(n != 4);
}

