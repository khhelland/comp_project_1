#include <math.h>
#include <iostream>
#include <armadillo>
#include <stdlib.h>

using namespace std;
using namespace arma;

int main(int argc, char* argv[]){
  
  int n = atoi(argv[1]); 
  
  mat A = zeros<mat>(n,n);
  vec f(n);
  vec u(n);
  
  double a = -1;
  double b = 2;
    
  double h = 1.0/(n+1);
  
  A(0,0) = b;
  A(1,0) = a;
  
  for(int i=1;i<(n-1);i++){
    A(i-1,i) = a;
    A(i,i) = b;
    A(i+1,i) = a;
  }

  A(n-2,n-1) = a;
  A(n-1,n-1) = b;
    
      
    
  for(int i=1; i<=n; i++){
    f(i) = 100*exp(-10*i*h);
  }

  f = f*pow(h,2);
  
  
  //finn ut om lU-metoden
  
  u.save("data.dat",raw_ascii);
  
  return 0;
}
  

  
