#include <iostream>

using namespace std;



int main(){
    int n = 8;
    int array[8] = {41,37,10,74,98,22,83,66};

    for(int i = 1; i < n; i++){
        int value = array[i];
        int j = i-1;

        while(j >= 0 && array[j] > value){
            array[j + 1] = array[j];
            j = j-1;
        }

        array[j + 1] = value;
    }

     for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}