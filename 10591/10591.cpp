#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>

using namespace std;

int func(int n){
    if(n==1){
        return 1;
    }else{
        int sum = 0;
        while(n/10 != 0){
            int a = n%10;
            sum+=a*a;
            n /= 10;
        }
        int a = n%10;
        sum+=a*a;
        return sum;
    }
}

int ANS(int N){

    set<int> state;
    do{
        if(N==1){  
            return 0;
        }else{
            state.insert(N);
            N=func(N);
           // cout << N << "->";
        }
    }while(state.find(N) == state.end());
    return 1;
}

int main(){

    int n;
    while(scanf("%d",&n) != EOF){
        int *N = new int[n];
        for(int i=0;i<n;i++)
            scanf("%d",&N[i]);

        for(int i=0;i<n;i++){
            if(!ANS(N[i])){
                printf("Case #%d: %d is a Happy number.\n",i+1,N[i]);
            }else{
                printf("Case #%d: %d is an Unhappy number.\n",i+1,N[i]);
            }
        }
    }
    return 0;

}