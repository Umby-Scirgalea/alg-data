#include <iostream>

using namespace std;

// MAX-HEAP

// Costruisci l'albero HEAP
void heapify(int a[], int sx, int dx){

    int temp = a[sx];
    int i = sx;
    int j = 2*i;

    while(j <= dx){
        if((j < dx) && (a[j+1] > a[j]))
            j++;
        if(temp < a[j]){
            a[i] = a[j];
            i = j;
            j = 2*i;
        }else{
            j = dx + 1;
        }
    }

    if(i != sx)
        a[i] = temp;
}

void heapsort(int a[], int n){

    int tmp, sx, dx;

    // Prima fase: Trasformiamo l'array in uno HEAP
    for(sx = n/2; sx >= 1; sx--){
        heapify(a,sx,n);
    }

    // Seconda fase: Ordinare l'array, mantenendo Organizzazione % HEAP
    for(dx = n; dx > 1; dx--){
        tmp = a[1];
        a[1] = a[dx];
        a[dx] = tmp;
        heapify(a, 1, dx-1);
    }
}

int main(){
    int n = 8;
    // Parte da 1, l'elemento 0 non è significativo
    int array[] = {0,41,37,10,74,98,22,83,66};

    heapsort(array,n);

    // Partiamo da 1 e incrementiamo il limite
    for(int i = 1; i < n+1; i++){
        cout << array[i] << " ";
    }


}