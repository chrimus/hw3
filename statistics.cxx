#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

void randomize(double* arr, const int N){
  for(int i=0; i<N; i++){
      arr[i] = rand() / (double) RAND_MAX;
  }
}

void calc_moments(double* arr, double& mean, double& var, const int N) {
  mean = 0;
  for(int i=0; i<N; i++){
    mean += arr[i];  
  }
  mean /= (double) N;
  
  var=0;
  for(int i=0; i<N; i++){
    var += (arr[i]-mean) * (arr[i]-mean);
  }
  var/= (double) N;
}

void calc_moments_pointers(double* arr, double* mean, double* var, const int N) {
  *mean = 0;
  for(int i=0; i<N; i++){
    *mean += *(arr+ i);
  }
  *mean /= (double) N;
  
  *var=0;
  for(int i=0; i<N; i++){
    *var += (arr[i]- *mean) * (arr[i]- *mean);
  }
  *var/= (double) N;
}

int main(){
   const int N = 100;
   double p[N];
   double mean, var;
   double mean2, var2;
   
   srand(time(NULL));

   randomize(p, N);
   calc_moments(p, mean, var, N);
   
   double* pp = p;
   calc_moments_pointers(pp, &mean2, &var2, N);

   cout << "Mean = " << mean << endl;
   cout << "Mean2= " << mean2<< endl;
   cout << "Variance = " << var << endl;
   cout << "Variance2= " << var2<< endl;

   return 0;
}
