#include <iostream>
#include <cmath>
using namespace std;

int tiles(int n , int w , int h){
    int r = (w/n) * (h/n);
    return r;
}

int min_tiles(int w, int h){
int total_tiles = 0;

for ( int i = 10; i >= 0 ; i = i - 1){

    total_tiles = total_tiles + tiles(pow(2,i), w , h) - 4*tiles(pow(2,i + 1), w , h);
}
return total_tiles;

}




int main (){

    cout << min_tiles(16 , 17)<< endl;
} 