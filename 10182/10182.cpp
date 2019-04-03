#include <cstdio>

int main(){
    int M;
    while(~scanf("%d",&M)){
        if(M==1){
            printf("0 0\n");
            continue;
        }
        int i=0;
        for(i=0;i<10000;i++){
            if(3*i*(i+1)+1 >= M)
                break;
        }
        i--;
        int var = M-(3*i*(i+1)+1);
        int loop = i+1;
        int edge = var/(i+1)%6;
        int pos = (var%(i+1));
        //printf("%d %d %d\n",loop,edge,pos);
        if(edge == 0){
            printf("%d %d\n",loop-pos,pos);
        }else if (edge == 1){
            printf("%d %d\n",-pos,loop);
        }else if (edge == 2){
            printf("%d %d\n",-loop,loop-pos);
        }else if (edge == 3){
            printf("%d %d\n",-loop+pos,-pos);
        }else if (edge == 4){
            printf("%d %d\n",pos,-loop);
        }else if (edge == 5){
            printf("%d %d\n",loop,-loop+pos);
        }
        //printf("\n%d/%d",M-(3*i*(i+1)+1),6*(i+1));
    }
}