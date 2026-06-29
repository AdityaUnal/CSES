/*
https://cses.fi/problemset/task/2216
*/

#include <cstddef>
#include<vector>
#include<iostream>
#include<cstdint>

int main(){
    size_t n;
    std::cin>>n;
    std::vector<uint32_t> arr(n);
    std::vector<uint32_t> ind(n + 1);
    ind[0] = n;
    for(int i = 0;i < n;i +=1){
        std::cin>>arr[i];
        ind[arr[i]] = i;
    }
    int l = 0;//Last Index of Curr Sweep
    int res = 1;
    for(int i = 1;i <= n;i +=1){
        if( l > ind[i]){
            res +=1;
        }
        l = ind[i];
    }
    std::cout<<res<<"\n";
    return 0;
}

