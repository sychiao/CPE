#include <cstdio>

using namespace std;

int main(){
    int size;
    scanf("%d",&size);
    int a=1,b=2;
    int fib[40];
    fib[0] = 1;
    fib[1] = 2;
    for(int k=2;k<40;k++){
        int c = a+b;
        a = b;
        b = c;
        fib[k]=c;
    }
    
    int *input = new int[size];
    for(int i = 0;i<size;i++){
        scanf("%d",&input[i]);
    }

    for(int i=0;i<size;i++){
        int k = 40-1;
        int value = input[i];
        int first = 0;
        printf("%d = ",input[i]);
        while(k >= 0){
            if(value == 0){
                if(first)
                    printf("0");        
            }else{
                if(fib[k]>value){
                    if(first)
                        printf("0");
                }
                else
                {
                    first = 1;
                    printf("1");
                    value-=fib[k];
                }
            }
            k--;
        }
        printf(" (fib)");
        //if(i<size-1)
            printf("\n");
    }
    return 0;
}