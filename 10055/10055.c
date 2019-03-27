#include <cstdio>
#include <stdint.h>

int main(){
    long long a,b;
    int64_t a,b;
    while(scanf("%lld %lld",&a,&b) != -1){
        if(b>a){
            printf("%lld\n",b-a);
        }else{
            printf("%lld\n",a-b);
        }
    }
    return 0;
}