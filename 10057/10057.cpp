#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    while(std::cin >> n){
        std::vector<int> block;
        for(int i=0;i<n;i++){
            int a;
            std::cin >> a;
            block.push_back(a);
        }
        int size = block.size();
        std::sort(block.begin(),block.end());
        int mid = block[size/2-1+size%2];
        std::cout << mid << " ";
        int count = 0;
        for(auto e : block){
            if(e == mid || e == block[size/2])
                count++;
        }
        std::cout << count << " ";
        std::cout <<  block[size/2] - mid + 1<< "\n";
    }
    return 0;
}