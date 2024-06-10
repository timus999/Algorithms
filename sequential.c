#include<stdio.h>

int main(){
    int num[] = { 1, 2, 3, 4, 5};
    int keys;

    int found = 0;

    printf("Enter the number to search \n");
    scanf("%d", &keys);

    for ( int i = 0; i < 5; i++){
        if ( num[i] == keys ){
            printf("found the number at index %d \n", i);
            found = 1; 
            break;
        }
    }


        if ( found == 0 ) printf("Number not found \n");

        return 0;

}

