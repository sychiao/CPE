#include <cstdio>

using namespace std;

int prime[10000] = {1};
int max;
int  min;

int checkPrime(int num){
        int ch = 1;
        for(int k=0;num>=prime[k]*prime[k];k++){
            if(num%prime[k] == 0){
                return 0;
            }
        }
        return 1;
}

int ans[500001];

int main(){
    prime[0] = 2;
    prime[1] = 3;
    int n = 2;
    for(int i = 5;i<2147483647;i+=2){
        int ch = 1;
        for(int k=0;i>=prime[k]*prime[k];k++){
            if(i%prime[k] == 0){
                ch = 0;
                break;
            }
        }
        if(ch){
            prime[n++]=i;
            if(n>=10000){
                break;
            }
        }
    }

    

    int L,U;
    int first = 0;
    while(scanf("%d %d",&L,&U) != EOF){
        n = 0;
        if(L==1)
            L=L+1;

        for(long long i = L;i<=U;i++){
            int ch = 0;
            for(int k=0;(long long)i>=(long long)prime[k]*(long long)prime[k] && k<5000 ;k++){
                //printf("%d %d %d\n",i,k,prime[k]);
                if(i%prime[k] == 0){
                    ch = 1;
                    break;
                }
            }
            if(!ch){
                //printf("%d-%d\n",i,n);
                ans[n++]=i;
            }
        }
        int count = n;
        int max=0,min=1000000;
        int mina,minb,maxa,maxb;
        for(int k=0;k<count-1;k++){
            if((ans[k+1]-ans[k]) > max){
                max = ans[k+1]-ans[k];
                maxa = ans[k];
                maxb = ans[k+1];
            }

            if((ans[k+1]-ans[k]) < min){
                min = (ans[k+1]-ans[k]);
                mina = ans[k];
                minb = ans[k+1];
            }
        }
        //printf("%d %d",count,n);
        if(count <= 1){
            printf("There are no adjacent primes.\n");
        }else{
            printf("%d,%d are closest, %d,%d are most distant.\n",mina,minb,maxa,maxb);
        }        
    }
   return 0;
}