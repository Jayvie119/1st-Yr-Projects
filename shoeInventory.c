#include <stdio.h>
#include <stdlib.h>

#define STOCK_SIZE 101

struct shoe{
	int style_num;
	int numPairs_perSizes[12];
	float price;
	int avl;
};

void displayRec(struct shoe stock[], int index){
	int i;
	printf("Stock Number: %d\nStyle Number: %d\nPrice: %.2f\n", index, stock[index].style_num, stock[index].price);
	printf("Quantity per Sizes:\n");
	for(i =0;i<12;i++){
		printf("Size %d: %d pairs\n", (i+3), stock[index].numPairs_perSizes[i]);
	}
}

int main() {
	struct shoe stock[STOCK_SIZE] = {0};
	int choice;
	int i;
	int again = 1;
	
	while(again){
	printf("\n---SHOE INVENTORY---\n");
	printf("1. Create New Record\n2. Display Records\n3. Change Price of Stock Item\n4. Change Stock on Hand\n5. Exit\n");
	printf("Enter choice: ");
	scanf("%d", &choice);	
	
	int index, stylenum, size, amount;
	switch(choice){
		case 1:
			printf("\nCreating New Record:\n\n");
			
			printf("Enter Stock Number (0-%d): ", STOCK_SIZE);
			scanf("%d", &index);
			if(index < 0 || index >= STOCK_SIZE){
				printf("Invalid index.");
				break;
			}
			printf("Enter Style Number (1-50): ");
			scanf("%d", &stock[index].style_num);
			if(stock[index].style_num < 1 || stock[index].style_num > 50) {
				printf("Invalid style number. Must be between 1 and 50.\n");
				break;
			}
			
			printf("Enter Price: ");
			scanf("%f", &stock[index].price);
			
			printf("Enter Number of Pairs per Size: \n");
			for (i=0;i<12;i++){
				printf("Size %d: ", i + 3);
				scanf("%d", &stock[index].numPairs_perSizes[i]);
			}
			stock[index].avl =1;
			break;
		case 2:
			printf("\nDisplaying Records:\n\n");
			
			printf("Search Inventory (1)Stock Number (2)Style Number: ");
			scanf("%d", &choice);
			if (choice ==1){
				printf("Enter Stock Number: ");
				scanf("%d", &index);
				if (index >= 0 && index < STOCK_SIZE && stock[index].avl){
					displayRec(stock, index);
				} else {
					printf("Record not Found.");
				}
			} else if (choice == 2){
				printf("Enter Style Number: ");
				scanf("%d", &stylenum);
				int found =0;
				for (i = 0;i<STOCK_SIZE;i++){
					if(stock[i].avl && stock[i].style_num == stylenum){
						displayRec(stock, i);
						found =1;
						break;
					}
				}
				if(!found) {
					printf("Record not found.\n");
				}
			}
			break;
		case 3:
			printf("\nChange Prices of Stock Item\n\n");
			
			printf("Enter Stock Number to change prices: ");
			scanf("%d", &index);
			
			if (index >=0 && index < STOCK_SIZE && stock[index].avl){
				printf("Enter new price: ");
				scanf("%f", &stock[index].price);
			} else {
				printf("Invalid stock number.\n");
			}
			break;
		case 4:
			printf("\nChange Stock on Hand\n\n");
			
			printf("Enter Stock number to change stock: ");
			scanf("%d", &index);
			if (index >= 0 && index < STOCK_SIZE && stock[index].avl){
				printf("Enter shoe size to modify: ");
				scanf("%d", &size);
				if(size<3||size>14){
					printf("Invalid Size.\n");
					break;
				}
				printf("Enter new quantity: ");
				scanf("%d", &amount);
				stock[index].numPairs_perSizes[size - 3] = amount;
			} else {
				printf("Invalid Stock Number.\n");
			}
			break;
		case 5:
			printf("\nDo you really want to exit the program? (1-Yes/0-No): ");
			scanf("%d", &again);
			if (again == 1){
				printf("Thank you for using the program!\nExiting the program.\n");
				again =0;
			} else {
				again =1;
			}
			break;
			
		default:
			printf("Invalid Choice.\n");
		}
	}
	
	return 0;
}
