#include <stdio.h>

int errorCheck(){
    int x, test;
    do{
        test=scanf("%d", &x);
        
        if(test!=1){
            printf("Invalid Input! Try Again\n");
            while(getchar()!='\n');
        } else if(x<1){
            printf("Invalid Input! Try Again\n");
            while(getchar()!='\n');
        }
    } while (test!=1);
    return x;
}

int valueCheck(){
    int x, test;
    do{
        test = scanf("%d", &x);

        if (test!= 1){
            printf("Invalid Input! Try Again: ");
            while (getchar()!='\n');
        }
    } while (test!=1);
    return x;
}

int againCheck(){
    int x;
    do{
        scanf("%d", &x);

        if(x!=1 && x!=0){
            printf("Invalid Choice! Try Again!\n");
            while (getchar()!='\n');
        }
    }while(x!=1 && x!= 0);
    return x;
}

void bubbleSort(int arr[], int size){
	int i, j;
    for( i=0;i<size-1;i++){
        for( j=0;j<size-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int row, column;
    int again, again1;
    int i,j;
    
    do{
        printf("Enter number of rows: ");
        row = errorCheck();
        printf("Enter number of columns: ");
        column = errorCheck();
    
        int X[row][column];

        for( i= 0; i<row;i++){
            for( j=0;j<column;j++){
                printf("X[%d][%d]: ", i, j);
                X[i][j]=valueCheck();
            }
        }
        
        printf("UNSORTED 2d ARRAY:\n");

        for( i= 0; i<row;i++){
            for( j=0;j<column;j++){
                printf("%d\t", X[i][j]);
            }
            printf("\n");
        }

        int flat[row*column];
        int index = 0;
        
        // flatten the 2d array and bubblesort
        
        for( i =0; i < row;i++){
            for( j =0; j < column;j++){
                flat[index++] = X[i][j];
            }
        }

        bubbleSort(flat, row*column);


        // from flatten to 2d array again
        index =0;
        for( i=0;i<row; i++){
            for( j=0;j<column;j++){
                X[i][j] = flat[index++];
            }
        }


        printf("SORTED 2d ARRAY:\n");
        //print 2d array
        for( i= 0; i<row;i++){
            for( j=0;j<column;j++){
                printf("%d\t", X[i][j]);
            }
            printf("\n");
        }

        printf("\nDo you want to try again? (1-Yes/0-No)\n");
        again = againCheck();
        if(again==0){
            printf("Are you sure you want to exit the program? (1-Yes/0-No)\n");
            again1 = againCheck();
            if(again1==1){
                printf("Thank you for using my program!");
                break;
            } else {
                again =1;
            }
        }

    } while(again ==1);
    return 0;
}
