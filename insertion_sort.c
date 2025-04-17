#include <stdio.h>

int inputCheck(){
    int x, test; 
    do{
        test = scanf("%d", &x);

        if(test!=1){
            printf("Invalid Input! Enter a number: ");
            while(getchar()!='\n');
        } else if(x<1){
            printf("Invalid Input! Please Try Again: ");
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
            printf("Invalid Input! Please Try Again: ");
            while(getchar()!='\n');
        }
    }while(test!= 1);
    return 0;
}

int againCheck(){
    int x;
    do{
        scanf("%d", &x);
        
        if(x!=1 && x!=0){
            printf("Invalid Choice! (1-Yes/0-No): ");
            while(getchar()!='\n');
        }
    } while(x!=1 && x!=0);
    return x;
}

void insertionSort(int arr[], int size){
	int i;
    for ( i=1;i<size;i++){
        int key = arr[i];
        int j = i - 1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1]=key;
    }
}

int main(){
    int row, column;
    int again, again1;
    int i,j;

    printf("Welcome to my program!\n");

    do{
        printf("Enter number of rows: ");
        row = inputCheck();
        printf("Enter number of column: ");
        column = inputCheck();

        int X[row][column];

        for( i =0; i <row;i++){
            for( j =0; j<column;j++){
                printf("Enter a Value: ");
                X[i][j] = inputCheck();
            }
        }

        printf("\nUNSORTED ARRAY:\n");
        for( i = 0; i<row;i++){
            for( j=0;j<column; j++){
                printf("%d\t", X[i][j]);
            }
            printf("\n");
        }

        //flatten 2d
        int flat[row*column];
        int index =0;

        for ( i=0; i<row;i++){
            for ( j=0; j< column; j++){
                flat[index++] = X[i][j];
            }
        }

        insertionSort(flat, row*column);
        
        //flat -> 2d
        index = 0;
        for ( i=0; i<row;i++){
            for ( j=0; j< column; j++){
                X[i][j] = flat[index++];
            }
        }

        //sorted
        printf("\nSORTED ARRAY:\n");
        
        for( i=0;i<row;i++){
            for( j=0;j<column;j++){
                printf("%d\t", X[i][j]);
            }
            printf("\n");
        }
        
        //try again
        printf("Would you like to try again?\n(1-Yes/0-No): ");
        again = againCheck();
        if (again == 0){
            printf("Are you sure you want to exit my program?\n(1-Yes/0-No): ");
            again1 = againCheck();
            if (again1 == 1){
                printf("Thank you for using my program!\n");
                break;
            } else {
                again = 1;
            }
        }


    } while (again ==1);
    return 0;
}
