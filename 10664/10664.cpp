#include <iostream>
#include <cstdio>
#include <vector>


bool func(int sum,int value,int index,std::vector<int> list){
    if(list.size() == index){
        return false;
    }
    else if(value == sum){
        return true;
    }
    else if(value > sum){
        return false;
    }
    else{
        return func(sum,value + list[index], index+1 ,list) || func(sum,value, index+1 ,list);
    }
}

int main(){
    int line = 0;

    scanf("%d",&line);
    for(int i=0;i<line;i++){
        std::vector<int> list;
        int c;
        while(1){
            int a;
            char c;
            scanf("%d",&a);
            list.push_back(a);
            scanf("%c",&c);
            if(c=='\n')
                break;
        }
        int sum = 0;
        for(auto e: list){
            sum += e;
        }
        if(sum%2 == 1){
            printf("NO\n");
            continue;
        }
        int ret = func(sum/2,0,0,list);
        if(ret)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}