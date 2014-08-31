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
  vec ft = zeros<vec>(n);
  vec bv = zeros<vec>(n);
  
  
  double a = -1;
  double b = 2;
  double ac = 1;
  
  bv.fill(b);

  double h = 1.0/(n+1);
  
  
  
  for(i=0; i<(n+2); i++){f[i] = 100*exp(-10*i*h);}

  ft[0] = f[1];

  for(i=0; i<n?;i++){
    bv[i+1] -= ac/bv[i];
    ft[i+1] = f[i+1] - a*ft[i]/bv[i];
  }
    
  

  // for(int i = 0; i<=n; i++){
  //   temp[i]= (double)i;
  //   }
  // cout<<(temp[n-2])<<endl;
  return 0;
}
  

  
