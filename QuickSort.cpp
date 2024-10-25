#include <iostream>

using namespace std;

void quicksort(int a[], int sx, int dx){
    int i = sx;
    int j = dx;
    int pivot = a[(sx + dx) / 2];

    while(i <= j){
        while(a[i] < pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }

        if(i <= j){
            if(i < j){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    }
    if(sx < j){
        quicksort(a,sx,j);
    }
    if(i < dx){
        quicksort(a,i,dx);
    }
}

int main(){
    int n = 8;
    int array[8] = {41,37,10,74,98,22,83,66};

    quicksort(array,0,n-1);

    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    
}