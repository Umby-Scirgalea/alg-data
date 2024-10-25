#include <iostream>

using namespace std;

int main(){
    int n = 8;
    int array[8] = {41,37,10,74,98,22,83,66};

    bool scambio = true;

    while(scambio == true){
        scambio = false;

        for(int i = 0; i < n; i++){
            if(array[i] > array[i+1]){
                int temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
                scambio = true;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}