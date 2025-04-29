#include <stdio.h>

// Define a structure to store book details
struct book {
	char title[80];    // Title of the book
	char author[80];   // Author of the book
	float price;       // Price of the book
};

int main(){
	int i;                     // Loop variable
	int cheap = 0, exp = 0;    // Indexes to track the cheapest and most expensive books

	// Initialize an array of 3 books
	struct book bks[3] = {
		{"The Book", "JHS. Locke", 19.99},
		{"The Note", "JHS. Khey", 49.99},
		{"The Pen", "JHS. Ihnk", 29.99}
	};

	// Loop through the book array starting from the second book
	for (i = 1; i < 3; i++) {
		// If the current book is cheaper than the currently recorded cheapest book
		if (bks[i].price < bks[cheap].price) {
			cheap = i;  // Update the index of the cheapest book
		}

		// If the current book is more expensive than the currently recorded most expensive book
		if (bks[i].price > bks[exp].price) {
			exp = i;    // Update the index of the most expensive book
		}	
	}
				
	// Print the details of the cheapest book
	printf("\nThe Cheapest Book:\nTitle: %s\nAuthor: %s\nPrice: $%.2f\n", 
		bks[cheap].title, bks[cheap].author, bks[cheap].price);

	// Print the details of the most expensive book
	printf("\nThe Most Expensive Book:\nTitle: %s\nAuthor: %s\nPrice: $%.2f\n", 
		bks[exp].title, bks[exp].author, bks[exp].price);

	return 0;  // End of program
}
