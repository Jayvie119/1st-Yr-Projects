#include <stdio.h>
#include <ctype.h>

//STRUCT
struct card{
	int rank; // 1 - Ace, ... 10 - Jack, 12 - Queen, 13 - King
	int suit; // H - Heart, D - Diamond, C - Club, S - Spade
}hand[5], *cardptr;

//Minor Process
int isStraight(int count[]){
	int i;

	if(count[14] && count[2] && count[3] && count[4] && count[5]){
		return 1;
	}
		
	for(i=1;i<=10;i++){
		if(count[i] && count[i+1] && count[i+2] && count[i+3] && count[i+4]){
			return 1;
		}				
	}
	return 0;
}

//Main Process of the Poker
// Whole struct to func
void poker(struct card *cSptr, int count[]){
	int one =0, three=0, four=0;
	int flush =1;
	int straight =0;
	char check_suit = cSptr[0].suit;
	int i;
	
	for(i=0;i<5;i++){
		if(cSptr[i].suit != check_suit){
			flush = 0;
			break;
		}
	}
	
	for(i=0;i<=13;i++){
		if (count[i] == 2){
			one++;
		} else if (count[i] == 3){
			three++;
		} else if (count[i] == 4){
			four++;
		} 
	}
	
	count[14] = count [1];
	straight = isStraight(count);
	
	if(straight && flush){
		printf("Straight Flush!\n");
	} else if(four){
		printf("Four of a Kind!\n");
	} else if(three && one){
		printf("Full House!\n");
	} else if(flush){
		printf("Flush!\n");
	} else if(straight){
		printf("Straight!\n");
	} else if(three){
		printf("Three of a Kind!\n");
	} else if(one == 2){
		printf("Two Pairs!\n");
	} else if(one){
		printf("One Pair!\n");
	} else {
		printf("Nothing.\n");
	}
}

//Pass members
void displaySingleCard(struct card h, int index){
    printf("Card %d: %d%c\n", index + 1, h.rank, h.suit);
}

//Pass whole struct
void displayCard(struct card hand[]){
	int i;
	
	for(i=0;i<5;i++){
		displaySingleCard(hand[i], i);
	}
}

//Error Handlers
int valCheck(void){
    int x;
    char c;
    
	do{
        // Prompt the user to enter an integer
        printf("\nEnter Rank of Card (1-13): ");
        // Check if the input is an integer and is greater than zero
        if(scanf("%d", &x)==1 && x>=1 && x<=13){
            // Clear the input buffer (remove any remaining characters)
            while((c=getchar())!='\n' && c!= EOF);
            return x; // Return the valid integer input
        }
        // If invalid, display an error message
        printf("Error! Enter a valid rank (1-13).\n");
        // Clear the input buffer
        while((c=getchar())!='\n' && c!= EOF);
    } while(1);
}

char suitCheck(void){
    char x;
    char c;
    
	do{
		printf("\nEnter a Suit (H, D, S, C): ");
		scanf(" %c", &x);
		
		x = toupper(x);
		
		while((c=getchar())!='\n'&&c!=EOF);
		
		if(x=='H' || x=='D' || x=='S' || x=='C'){
			return x;
		}
		
		printf("Error! Enter a a valid suit (H, D, S, C).\n");
    } while(1);
}

int againCheck(void){
    int x;
    char c;
    while(1){
        // Ask if the user wants to try again
        printf("\nDo you want to try again? 1-Yes / 0-No: ");
        // Check if the input is either 1 or 0
        if(scanf("%d", &x)==1 && (x==0||x==1)){
            // Clear the input buffer
            while((c=getchar())!='\n' && c!= EOF);
            return x; // Return the user's choice (1 or 0)
        }
        // If invalid, display an error message
        printf("Error! Enter 1 for Yes or 0 for No.\n");
        // Clear the input buffer
        while((c=getchar())!='\n' && c!= EOF);
    }
}

int exitCheck(void){
    int x;
    char c;
    while(1){
        // Ask if the user wants to try again
        printf("\nAre you sure you want to exit the program? 1-Yes / 0-No: ");
        // Check if the input is either 1 or 0
        if(scanf("%d", &x)==1 && (x==0||x==1)){
            // Clear the input buffer
            while((c=getchar())!='\n' && c!= EOF);
            return x; // Return the user's choice (1 or 0)
        }
        // If invalid, display an error message
        printf("Error! Enter 1 for Yes or 0 for No.\n");
        // Clear the input buffer
        while((c=getchar())!='\n' && c!= EOF);
    }
}

int main(){
	int i;
	int val;
	char suit;
	struct card *cardptr;
			cardptr = hand;
	int count[15] = {0};
	int again;
	int exit;
	
	do{
		for(i=0;i<15;i++) count[i] = 0;
		
		for(i=0;i<5;i++){
			printf("Card %d:\n", i+1);
			hand[i].rank = valCheck();
			hand[i].suit = suitCheck();
			count[hand[i].rank]++;
		}	
	
		displayCard(hand);
	
		poker(cardptr, count);
	
		again = againCheck();
		if (again == 0) {			
			exit = exitCheck();
			if (exit == 1) {
				printf("Thank you for using the program!\n");
				break;
			}
		continue;
		}

	}while(1);
	
	return 0;
}
