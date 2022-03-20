#include <iostream>
#include <cmath>
using namespace std;



int main(){

int n ; cin >> n;

int arr[n];
 
for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
}

int listS[n];
for(int i = 0 ; i < n ; i++){
  listS[i] = 0;
}


int listE[n];
for(int i = 0 ; i < n ; i++){
    listE[i] = 0;
}






for(int i = n-1 ; i >=0 ; i--){
    listS[arr[i]] = i;
}


for(int i = 0 ; i < n ; i++){
    listE[arr[i]] = i;
}

int acc = 0;
for(int i = 0 ; i < n ; i++){
    if ( listE[i] - listS[i] > acc){
        acc = listE[i] - listS[i];
    }
}



cout << acc;


}


