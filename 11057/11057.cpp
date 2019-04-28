#include <iostream>
#include <cstdio>

using namespace std;

#include <set>

int main(){
    int N;
    while(scanf("%d",&N) != EOF){
        int *p = new int[N];
        for(int i=0;i<N;i++){
            scanf("%d",&p[i]);
        }
        int M = 0;
        scanf("%d",&M);

        set<int> hash;

        long long a=M,b=0;
        long long x,y;
        for(int i=0;i<N;i++){
            if(hash.find(M-p[i]) != hash.end()){
                //printf("found\n");
                x = (M-p[i]) > p[i]? (M-p[i]) : p[i];
                y = (M-p[i]) <= p[i]? (M-p[i]) : p[i];
                if((x - y) < (a - b)){
                    a = x;
                    b = y;
                }
                if((a-b)==0)
                    break;
            }else{
                hash.insert(p[i]);
            }
        }
        printf("Peter should buy books whose prices are %lld and %lld.\n\n",b,a);
    }
}