#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

void LIS(int *a,int *l,int N){

    int *small = new int[10000]();
    int MAX = 0;

    for(int i=0;i<N;i++){
        for(int j=MAX;j>=0;j--){
            int v = small[j];
            if(a[i]>a[v]){
                if(j==MAX){
                    if(MAX==10000)
                        break;
                    MAX++;
                    small[MAX] = i;
                }else{
                    small[j+1] = i;
                }
                l[i] = l[v]+1;
                break;
            }
            if(j==0 && a[i]<=a[v]){
                small[0] = i;
                l[i] = 1;
            }
        }
    }
}

int main(){

    int N;
    while(scanf("%d",&N) != EOF){
        int *a = new int[N];
        for(int i=0;i<N;i++){
            scanf("%d",&a[i]);
        }
        
        int *ra = new int[N];

        for(int i=0;i<N;i++){
            ra[N-i-1] = a[i];
        }


        int *l = new int[N]();
        int *r = new int[N]();
        LIS(a,l,N);
        LIS(ra,r,N);

        int m =0;
        for(int i=0;i<N;i++){
            int min = l[i] > r[N-i-1]? r[N-i-1] : l[i];
            m = (min*2-1) > m ? (min*2-1) : m;
        }
        printf("%d\n",m);

    }

    return 0;
}