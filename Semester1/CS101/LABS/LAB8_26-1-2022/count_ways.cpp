#include <iostream>
using namespace std;
long int count_ways(int n){
    if (n == 0){
        return 1;
    }
    else if ( n >= 0){
        long int r = (count_ways( n - 6) + count_ways( n - 5) + count_ways( n - 4) + count_ways( n - 3) + count_ways( n - 2) + count_ways( n - 1)) ;
        return r;
    }
    else { return 0 ;}

}

