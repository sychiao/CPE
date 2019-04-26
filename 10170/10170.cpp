#include <stdio.h>
#include <stdlib.h>

int main(){
    long long S,D;
    while(scanf("%lld %lld",&S,&D) != EOF){
        long long d = 0;
        while(d < D){
            d+=S;
            S++;
        }
        printf("%lld\n",S-1); 
    }
    return 0;
}
