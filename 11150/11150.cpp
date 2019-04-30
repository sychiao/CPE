#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int N;
    while(scanf("%d",&N) != EOF){
        int Cola = 0, bottle = 0;
        while(N!=0 || bottle > 2){
            Cola += N;
            bottle += N;
            N = bottle/3;
            bottle = bottle%3;
        }

        if(bottle == 2){
            Cola += 1;
            bottle = 0;
        }
        printf("%d\n",Cola);
    }
    return 0;
}
