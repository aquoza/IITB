/*

implment new list saying hill type ( 0 if not a hill, 1 if irregular hil, 1a , 1b for 011 cases.)

WRITE AND CHECK ALL CASES from 000 to 111;

*/

#include <iostream>
#include <cmath>
using namespace std;

int checkridge( int *l, int n , int i){
// returns 0 , 1 

if ( ((l[i]> l[i-1])&& (l[i]> l[i+1]) )|| ((l[i] < l[i-1]) && (l[i] < l[i+1]))){
    return 1;

}
else{
    return 0;
}

}


int totalridges ( int *l, int n){
    int acc = 0;
    for (int i = 1 ; i < n-1; i++){
        if(checkridge(l , n , i) == 1){
            acc++;
        }
    }
 return acc;
}

int maxdel( int *l , int n){
// returns how much you should subtract
int acc = 0;

if ( totalridges( l , n) == 0){ 
    return 0;
}

for ( int i = 1; i < n-1 ; i++){
    int p = checkridge( l , n,i - 1 );
    int c = checkridge( l , n,i );
    int f = checkridge( l , n,i + 1 );

    if ( p + c + f == 3){
        acc = 3;
        break;
    }
    else if (( c == 1) && (p + c + f == 2)){
        if ( f == 1 && ((l[i+1] <l[ i - 1] && l[ i - 1] < l[i]) || (l[i+1] > l[ i - 1] && l[ i - 1] > l[i])) && l[i - 1] != l[i - 2]){
           if ( acc < 2){
                acc = 1 ;
                continue;
            } 
        }
        else if (p == 1 && ((l[i-1] <l[ i + 1] && l[ i + 1] < l[i]) || (l[i-1] > l[ i + 1] && l[ i + 1] > l[i])) && l[i + 1] != l[i + 2] ){
            if ( acc < 2){
                acc = 1 ;
                continue;
            }    
        }
        else {
            acc = 2;
            continue;
        }

    }



}

if ( acc > 1){
    return acc;
}
else {
    return 1;
}

}

int main(){
    int n ; cin >> n;

    int arr[n];

    for ( int i = 0; i < n ; i++ ){
        cin >> arr[i];
    }


    cout << totalridges(arr , n) - maxdel( arr , n) << endl;

}