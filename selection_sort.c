#include <stdio.h>

int inputCheck(){
    int x, test;
    do{
        test = scanf("%d", &x);
        if(test!=1){
            printf("Invalid Input! Enter a number: ");
            while(getchar()!='\n');
        } else if(x<=1){
            printf("Invalid Input! Enter a number: ");
            while(getchar()!='\n');
        }
    } while(test!=1);
    return x;
}

int valueCheck(){
    int x, test;
    do{
        test = scanf("%d", &x);
        if(test!=1){
            printf("Invalid Input! Enter an integer value: ");
            while(getchar()!='\n');
        }
    } while(test != 1);
    return x;
}

int againCheck(){
    int x;
    do{
        scanf("%d", &x);
        if(x!=1 && x!=0){
            printf("Invalid Choice! Try Again? (1-Yes/0-No): ");
            while(getchar()!='\n');
        }
    }while(x!=1 && x!=0);
    return x;
}

void selectionSort(int arr[], int size){
	int i, j;
    for ( i=0;i<size-1;i++){
        int min_pos = i;
        for( j=i+1;j<size;j++)
            if (arr[j]<arr[min_pos]) min_pos=j;
        

        if (min_pos!=i){
            int temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;
        }
    }
}

int main(){
    int row, column;
    int again, again1;
    int i,j;

    printf("Welcome to my program!\n");

    do{
        printf("Enter a number of row: ");
        row = inputCheck();
        printf("Enter a number of column: ");
        column = inputCheck();

        int X[row][column];

        for( i=0;i<row;i++){
            for( j=0;j<column;j++){
                printf("Enter a Value: ");
                X[i][j] = valueCheck();
            }
        }

        //unsorted
        printf("UNSORTED ARRAY:\n");
        for( i=0;i<row;i++){
            for( j=0;j<column;j++){
                printf("%d\t", X[i][j]);
            }
            printf("\n");
        }

        //flatten
        int flat[row*column];
        int index = 0;
        for( i =0;i<row;i++){
            for( j=0;j<column;j++){
                flat[index++] = X[i][j];
            }
        }

        selectionSort(flat, row*column);

        index = 0;
        for( i =0;i<row;i++){
            for( j=0;j<column;j++){
                X[i][j] = flat[index++];
            }
        }


        // sorted
        printf("\nSORTED ARRAY:\n");
        for( i=0;i<row;i++){
            for( j=0; j<column;j++){
                printf("%d\t", X[i][j]);
            }
            printf("\n");
        }

        printf("Would you like to try again? (1-Yes/0-No): ");
        again = againCheck();
        if (again == 0){
            printf("Do you want to exit want program? (1-Yes/0-No): ");
            again1 = againCheck();
            if (again1 == 1){
                printf("Thank you for using my program!\n");
                break;
            } else{
                again =1;
            }
        }
    } while (again ==1);

    return 0;
}
