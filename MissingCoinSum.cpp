#include<vector>
#include<iostream>
#include<cstdint>
#include <algorithm>
int main(){
    uint32_t n;
    std::cin>>n;
    std::vector<uint32_t> arr(n);
    for(int i = 0;i < n;i +=1){
        std::cin>>arr[i];
    }
    std::sort(arr.begin(),arr.end());
    uint64_t R = 0;
    for(uint32_t c :arr){
        if(R + 1 < c){
            break;
        }
        R +=c;
    }
    std::cout<<R + 1 <<"\n";
    return 0;
}