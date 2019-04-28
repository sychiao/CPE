#include <iostream>
#include <cstdio>
using namespace std;


void func(int *s){
        if(s[0] >= s[2]){
            int tmp = s[0];
            s[0] = s[2];
            s[2] = tmp;
        }
        if(s[1] >= s[3]){
            int tmp = s[1];
            s[1] = s[3];
            s[3] = tmp;
        }
}

int main(){
    int N;
    scanf("%d",&N);
    int n = 1;
    while(N){
        N--;
        int A = 1,B;
        int s1[4];
        int s2[4];
        for(int i=0;i<4;i++)
            scanf("%d",&s1[i]);
        for(int i=0;i<4;i++)
            scanf("%d",&s2[i]);

        func(s1);
        func(s2);

        //printf("%d %d %d %d\n",s1[0],s1[1],s1[2],s1[3]);
        //printf("%d %d %d %d\n",s2[0],s2[1],s2[2],s2[3]);
        if(s1[0] <= s2[0]){
            if(s2[0] <= s1[2]){
              //  printf("H%d",A);
                int m = s1[2] < s2[2] ? s1[2] : s2[2];
                A *= (m - s2[0]);
            }else{
                A *= 0;
            }
        }else{
            if(s1[0] <= s2[2]){
                int m = s1[2] < s2[2] ? s1[2] : s2[2];
                A *= (m - s1[0]);
            }else{
                A *= 0;
            }
        }

        if(s1[1] <= s2[1]){
            if(s2[1] <= s1[3]){
               // printf("L%d",A);
                int m = s1[3] < s2[3] ? s1[3] : s2[3];
                A *= (m - s2[1]);
            }else{
                A *= 0;
            }
        }else{
            if(s1[1] <= s2[3]){
                int m = s1[3] < s2[3] ? s1[3] : s2[3];
                A *= (m - s1[1]);
            }else{
                A *= 0;
            }
        }
        
        B = (s1[2]-s1[0])*(s1[3]-s1[1])+
            (s2[2]-s2[0])*(s2[3]-s2[1]);

        printf("Night %d: %d %d %d\n",n++,A,B-2*A,10000-B+A);
    }
    return 0;
}