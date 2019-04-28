#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int Prime[2500] = {0};

int checkPrime(int n){
    for(int k=1;Prime[k] < sqrt(n) || k<2500;k++){
        if(Prime[k] == 0){
            return 1;
        }
        if(n%Prime[k]==0 && n!=Prime[k]){
            return 0;
        }
    }
    return 1;
}

void mkPrime(){
    Prime[0] = 1;
    int N = 1;
    for(int i = 2;i<10010;i++){
        if(checkPrime(i)){
            Prime[N++]=i;
        }
    }
}

int main(){
    mkPrime();
   // printf("%d",Prime[2499]);
    int N;
    while(1){
    scanf("%d",&N);
    if(N==0)
        break;
    int ans = 0;
    int s=1,e=1;
    int sum = 0;
    while(1){
        if(sum < N){
            sum += Prime[e];
            e++;
        }else if(sum > N){
            sum -= Prime[s];
            s++;
        }else{
            ans++;
            sum += Prime[e];
            e++;
        }
        if(Prime[e-1]>N){
            break;
        }
    }
    printf("%d\n",ans);
    }
    return 0;
}