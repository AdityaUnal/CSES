#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

int main(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<int> a(n);
    std::vector<int> b(m);
    for(int i = 0;i < n;i +=1){
        std::cin>>a[i];
    }
    for(int i = 0;i < m;i +=1){
        std::cin>>b[i];
    }
    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end());
    uint32_t i = 0,j = 0;
    uint32_t res = 0;
    while(i < n and j < m){
        if(abs(a[i] - b[j]) <= k){
            i +=1;
            j +=1;
            res +=1;
        }
        else if(a[i] > b[j]){
            j +=1;
        }
        else{
            i +=1;
        }
    }
    std::cout<<res<<"\n";
    return 0;
}