#include <iostream>

int main(){
    int i;
    int a[8][8] = {0};
    int pa[6];
    int pb[6];
    int ll =0;
    std::cin >> i;
    for(int i=0;i<36;i++){
        std::cin >> a[i/6][i%6];
        if(a[i/6][i%6]){
            pa[ll] = i/6;
            pa[ll] = i%6;
            l++;
        }
    }

    return 0;
}