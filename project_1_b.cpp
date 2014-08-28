
#include <iostream>
//#include <armadillo>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]){
  int n = atoi(argv[1]); 
  double temp[n];
  
  for(int i = 0; i<=n; i++){
    temp[i]= (double)i;
    }
  cout<<(temp[n-2])<<endl;
  return 0;
}
  

  
