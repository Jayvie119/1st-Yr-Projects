#include <stdio.h>

struct book {
	char title[80];
	char author[80];
	float price;
};

int main(){
	int i;
	int cheap = 0, exp = 0;
	struct book bks[3] = {{"The Book", "JHS. Locke", 19.99},{"The Note", "JHS. Khey", 49.99},{"The Pen", "JHS. Ihnk", 29.99}};


	for (i = 1; i<3; i++){
		if(bks[i].price < bks[cheap].price){
			cheap = i;
		}
	
		if(bks[i].price > bks[exp].price){
		exp = i;
		}	
	}
				
	printf("\nThe Cheapest Book:\nTitle: %s\nAuthor: %s\nPrice: $%.2f\n", bks[cheap].title, bks[cheap].author, bks[cheap].price);
	printf("\nThe Most Expensive Book:\nTitle: %s\nAuthor: %s\nPrice: $%.2f\n", bks[exp].title, bks[exp].author, bks[exp].price);
	
	return 0;
}
