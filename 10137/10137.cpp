#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  int N;
  while(1){
    scanf("%d",&N);
    if(N == 0){
      return 0;
    }
    double *val = new double[N];
    double total = 0;
    for(int i=0;i<N;i++){
      scanf("%lf",&val[i]);
      total += val[i];
    }
    double iavg = round(total/N*100)/100.0;
    double itotal = iavg * N;
     
    double gr = 0;
    double le = 0;
    int ct = 0;
    for(int i=0;i<N;i++){
      if(val[i] > iavg){
        gr += val[i] - iavg;
        ct++;
      }else{
        le += iavg - val[i];
      }
    }
    //printf("%.2f-",le);
    if(gr > le){
      if( (gr-le) > ct*0.01){
        le = le + (gr-le-ct*0.01);
      } 
      printf("$%.2f\n",le);
    }else{
      printf("$%.2f\n",gr);
    }
  }
}
