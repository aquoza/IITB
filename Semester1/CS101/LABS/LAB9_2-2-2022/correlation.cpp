#include <iostream>
#include <cmath>
using namespace std;

double sum(double *l , int n){
    double acc = 0;
    for(int i = 0; i < n ; i++){
        acc = acc + l[i];
    }
return acc;
}




int main(){



int n;
cin >> n;
double xi[n], yi[n];



for(int i = 0; i < n; i++){
    cin >> xi[i];
}
for(int i = 0; i < n; i++){
    cin >> yi[i];
}


double prod[n];
for(int i = 0; i < n; i++){
    prod[i] = xi[i]*yi[i];
}
double squarx[n];
for(int i = 0; i < n; i++){
    squarx[i] = xi[i]*xi[i];
}
double squary[n];
for(int i = 0; i < n; i++){
    squary[i] = yi[i]*yi[i];
}


double numerato = n*(sum(prod , n)) - (sum(xi , n))*(sum(yi , n));

double denominato =   (sqrt( n*(sum(squarx, n)) - (sum(xi , n)*(sum(xi , n))) )) * (sqrt( n*(sum(squary, n)) - (sum(yi , n)*(sum(yi , n))) )) ;
cout << fixed;
cout.precision(2);
cout << numerato/denominato ;

}

