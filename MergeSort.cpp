#include <iostream>

using namespace std;

void merge(int a[], int left, int center,int right){
    int i = left, j = center+1 , k=0;

    int b[right-left+1];

    for(int i = 0; i < right-left+1; i++){
        b[i] = 0;
    }

    while((i <= center) && (j <= right)){
        if(a[i] <= a[j]){
            b[k] = a[i]; 
            i++;
        }else{
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= center){
        b[k] = a[i];
        i++;
        k++;
    }

    while(j <= right){
        b[k] = a[j];
        j++;
        k++;
    }

    for(k = left; k <= right; k++){
        a[k] = b[k-left];
    }
}

void mergesort(int a[], int left, int right){
    if(left < right){
        int center = (left+right)/2;
        mergesort(a,left,center);
        mergesort(a,center + 1, right);
        merge(a, left, center,right);
    }
}

int main(){
    int n = 8;
    int array[8] = {41,37,10,74,98,22,83,66};

    mergesort(array,0,n-1);

    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}