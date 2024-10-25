#include <iostream>

using namespace std;



int main(){
    int n = 8;
    int array[8] = {41,37,10,74,98,22,83,66};

   
    for(int i = n-1; i >= 0; i--){
        int max = i;
        for(int j = i-1; j >= 0; j--){
            if(array[j] > array[max]){
                max = j;
            }
        }
        if(max != i){
            int temp = array[i];
            array[i] = array[max];
            array[max] = temp;
        }
    }

     for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}