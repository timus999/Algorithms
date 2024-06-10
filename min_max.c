#include<stdio.h>

typedef struct min_max {
       int min;
       int max;
} m_m;


m_m find_min_max(int arr[],unsigned int l,unsigned int h) {
    m_m tmp, tmp2;
        if ( l == h){
        tmp.min = arr[l];
        tmp.max = arr[h];

        return tmp;
    }

    if ( ( h - l ) == 1) {
        if ( arr[l] < arr[h] ) {
            tmp.min = arr[l];
            tmp.max = arr[h];
        }else
        {
            tmp.min = arr[h];
            tmp.max = arr[l];
        }

        return tmp;
    }
    int mid = ( l + h ) / 2;
    tmp = find_min_max(arr, l, mid);
    tmp2 = find_min_max(arr, mid + 1, h);

    if ( tmp.min > tmp2.min ) {
        tmp.min = tmp2.min;
       }
    if ( tmp.max < tmp2.max){
        tmp.max = tmp2.max;
    }
    return tmp;
}







int main(){
    m_m res;
    int arr[] = { 34, 1, 65,35, 20};
    res = find_min_max(arr, 0, 4);

    printf("min : %d and max : %d \n " , res.min, res.max);


    return 0;
}

