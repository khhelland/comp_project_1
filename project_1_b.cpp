#include <math.h>
#include <iostream>
#include <armadillo>
#include <stdlib.h>
#include <time.h>
#include <cstdio>

using namespace std;
using namespace arma;

int main(int argc, char* argv[])
{
  
  int n = atoi(argv[1]); 
  
  //Vectors are size n+2 just because I thought it would 
  //make the indices easier to read
  vec u = zeros<vec>(n+2);
  vec f(n+2);
  vec bv(n+2);
  
  //Values for matrix
  double a = -1;
  double b = 2;
  double ac = 1;
  
  double h = 1.0/(n+1);
  
  bv.fill(b);
  
  //Filling in f  
  for(int i=1; i<(n+1); i++)
  {
    f(i) = 100*exp(-10*i*h);
  }

  f = f*pow(h,2);
 
  clock_t  start, end;
  
  //timing algorithm
  start = clock();
  
  //Algorithm: bv is a vector representing the main
  //diagonal of the matrix, with all elements set to b
  
  //First: make the matrix upper diagonal:
  for(int i=1; i<n; i++)
  {
    bv(i+1) -= ac/bv(i);
    f(i+1)  -= a*f(i)/bv(i);
  }
  
  //Backward substitution to obtain u
  u(n) = f(n)/bv(n);
  
  for(int i= (n-1); i>0 ; i--)
  {
    u(i) = (f(i) - a*u(i+1))/bv(i);
  }

  end = clock();

  u.save("data.dat",raw_ascii);
  
  double mytime = (end-start)/(double)CLOCKS_PER_SEC;

  FILE *out;
  out = fopen("myalg_time.dat","a+");
  fprintf(out,"%12.5e \n",mytime);
  fclose(out);
  
  return 0;
}
  

  
