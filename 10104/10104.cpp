#include <cstdio>

int X,Y;

int gcd(int A,int B,int a,int b,int x,int y){
    int m = a*A+b*B;
    int n = x*A+y*B;
    if(m%n==0){
        X = x;
        Y = y;
        return n;
    }
    else if (n==1){
        X = x;
        Y = y;
        return 1;
    }else{
        return gcd(A,B,x,y,a-(m/n)*x,b-(m/n)*y);
    }

}

int main(){
    int A,B;
    while(~scanf("%d %d",&A,&B)){
        int D = gcd(A,B,1,0,0,1);
        printf("%d %d %d\n",X,Y,D);
    }
}