#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

struct point{
    point(int a,int b):x(a),y(b){}
    int val = 1;
    int x;
    int y;
};

int  cutf(std::vector<point*> &cutset){
    int ret = 0;
    for(point* p: cutset){
        if(p->val == 1){
            p->val = 0;
            ret++;
        }
    }
    return ret;
}

void resetf(std::vector<point*> &cutset){
    for(point* p: cutset){
        p->val = 1;
    }
}

int Ans(int num,int index,int cut,std::vector<std::vector<point*> > &cutline){
    //printf("va %d %d %d %d\n",num,cut,cutline.size(),index);
    if(index >= cutline.size() && num != 0){
        return 1001;
    }

    if(num<=0){
        return cut;
    }

    int sum = 0;
    for(point* p : cutline[index]){
        sum += p->val;
    }

    if(sum == 0){
        return Ans(num,index+1,cut,cutline);
    }else{
        //printf("v");
        int del = cutf(cutline[index]);
        int a = Ans(num-del,index+1,cut+1,cutline);
        resetf(cutline[index]);
        int b = Ans(num,index+1,cut,cutline);
        return a>b?b:a;
    }

}

int Problem(){
    std::vector<point> pos;
    int tree,lst;
    scanf("%d %d",&tree,&lst);
    for(int n = 0;n<tree;n++){
        int a,b;
        scanf("%d %d",&a,&b);
        pos.push_back(point(a,b));
    }

    std::map<int,std::vector<point*> > hcutset;
    std::map<int,std::vector<point*> > vcutset;
    std::map<int,std::vector<point*> > rcutset;
    std::map<int,std::vector<point*> > lcutset;
    for(point &p : pos){
         hcutset[p.x].push_back(&p);
         vcutset[p.y].push_back(&p);
         rcutset[p.x+p.y].push_back(&p);
         lcutset[p.x-p.y].push_back(&p);
    }
    std::vector<std::vector<point*> > allcut;
    for(auto cut:hcutset){
        allcut.push_back(cut.second);
    }
    for(auto cut:vcutset){
        allcut.push_back(cut.second);
    }
    for(auto cut:rcutset){
        allcut.push_back(cut.second);
    }
    for(auto cut:lcutset){
        allcut.push_back(cut.second);
    }
    
    printf("%d %d %d %d ",hcutset.size(),vcutset.size(),rcutset.size(),lcutset.size());
    printf("%d",allcut.size());
    int ans = Ans(lst,0,0,allcut);
    printf("\nans:%d\n",ans);
}



int main(){
    int N;
    scanf("%d",&N);
    while(N!=0){
        Problem();
        N--;
    }
}