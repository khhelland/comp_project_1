#include <math.h>
#include <iostream>
#include <armadillo>
#include <stdlib.h>

using namespace std;
using namespace arma;

int main(int argc, char* argv[]){
  int n = atoi(argv[1]); 
  
  vec u = zeros<vec>(n+2);
  vec f = zeros<vec>(n+2);
  vec bv = zeros<vec>(n+2);
  
  vec sol = zeros<vec>(n+2);
  
  double a = -1;
  double b = 2;
  double ac = 1;
  
  bv.fill(b);

  double h = 1.0/(n+1);
  
  
  
  for(int i=0; i<(n+2); i++){
    f(i) = 100*exp(-10*i*h);
  }

  f = f*pow(h,2);
  
  for(int i=1; i<n;i++){
    bv(i+1) -= ac/bv(i);
    f(i+1) = f(i+1) - a*f(i)/bv(i);
  }
  
  u(n) = f(n)/bv(n-1);
  
  for(int i= (n-1); i>0 ; i--){
    u(i) = (f(i) - a*u(i+1))/bv(i);
  }
  
  
  for(int i=0;i<(n+2);i++){
    sol(i) = 1 - (1 - exp(-10))*i*h - exp(-10*i*h);
  }


  cout << max(abs(u-sol))<<endl;
  
  
  
  return 0;
}
  

  
