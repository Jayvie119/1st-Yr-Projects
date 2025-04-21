// pointer acting as array
#include <stdio.h>

int main(){
	int arr[3][3] = {1,2,3,4,5,6,7,8,9};
	int *ptr = &arr[0][0];
	int i = 0, j=0;
	
	printf("EVEN:\n");	
	printf("\nPointer Acting As Array\n");
	for(i=0; i<9;i++){
		if (*(ptr+i)%2==0){
			printf("%d ", *(ptr+i));
		}
	}
	
	printf("\nArrayAAPointerV1\n");
	for (i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(*(arr[i]+j)%2 == 0)
			printf("%d ", *(arr[i]+j));
		}
	}
	
		printf("\nArrayAAPointerV2\n");
	for (i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(*(*(arr + i)+j) %2==0){
				printf("%d ", *(*(arr + i)+j));
			}
		}
	}
	
	printf("\n--------------------\n");
	printf("ODD:\n");	
	printf("\nPointer Acting As Array\n");
	for(i=0; i<9;i++){
		if (*(ptr+i)%2!=0){
			printf("%d ", *(ptr+i));
		}
	}
	
	printf("\nArrayAAPointerV1\n");
	for (i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(*(arr[i]+j)%2 != 0)
			printf("%d ", *(arr[i]+j));
		}
	}
	
		printf("\nArrayAAPointerV2\n");
	for (i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(*(*(arr + i)+j) %2!=0){
				printf("%d ", *(*(arr + i)+j));
			}
		}
	}
	
	return 0;
}
