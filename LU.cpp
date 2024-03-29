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
  
  mat A = zeros<mat>(n,n);
  vec f(n);
  
  
  double a = -1;
  double b = 2;
    
  double h = 1.0/(n+1);
  
    
  //Filling  in the matrix
  A(0,0) = b;
  A(1,0) = a;
  
  for(int i=1;i<(n-1);i++)
  {
    A(i-1,i) = a;
    A(i,i) = b;
    A(i+1,i) = a;
  }

  A(n-2,n-1) = a;
  A(n-1,n-1) = b;
    
      
  for(int i=0; i<n; i++)
  {
    f(i) = 100*exp(-10*(i+1)*h);
  }

  f = f*pow(h,2);
    
  clock_t start, mid, end;
  
  //starting time including LU-decomposition
  start = clock();

  mat L, U, P;
  
  lu(L,U,P,A);
  
  //Time excluding decomposition
  mid = clock();

  //Solving equations in two steps
  vec y = solve(P.t()*L,f);
  vec u = solve(U,y);
  
  end = clock();

  u.save("LU.dat",raw_ascii);
  
  double lu_time = (end - start)/(double)CLOCKS_PER_SEC;
  double solve_time = (end - mid)/(double)CLOCKS_PER_SEC;
  
  FILE *outfile;
  outfile = fopen("lu_time.dat","a+");
  fprintf(outfile,"%12.5e %12.5e \n", lu_time, solve_time );
  fclose(outfile);

  return 0;
}
  

  
