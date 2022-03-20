#include <iostream>
using namespace std;



int main(){

int nu;
cin >> nu;
int nv;
cin >> nv;

int U[30];
for(int i = 0; i <30 ; i++){
U[i] = 0;
}
int V[30];
for(int i = 0; i <30 ; i++){
V[i] = 0;
}


for(int i = 0; i <nu ; i++){
    char j;
    cin >> j;
    U[j - 97] = 1;
}

for(int y = 0; y <nv ; y++){
    char z;
    cin >> z;
    V[z - 97] = 1;

}





for(int k = 0; k < 30; k++){
    if(U[k] == 1 || V[k]==1){
        char u = k + 97;
        cout << u <<" ";
    }

}


}