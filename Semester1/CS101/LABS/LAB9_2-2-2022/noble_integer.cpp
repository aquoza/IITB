#include <iostream>

using namespace std;

int maxi(int *l , int n){
    int acc = 0;
    for( int i = 0; i < n; i++){
        if( l[i]> acc){
            acc = l[i];
        }
    }
 return acc;
}

int checkp( int *l , int n){
    for(int i = 1 ; i <= maxi( l , n) ; i++){      
            int acc = 0;

            for(int j = 0; j < n; j++){
                if (l[j] > i){
                    acc = acc +1;
                }

            }

            if(acc == i){ return 1;}
            
    }
 return 0;
}

int main(){
    
int n; cin >> n;    
int list[n];

for(int i = 0; i < n; i++){
    cin >> list[i];
}

cout << checkp(list , n) << endl;

}