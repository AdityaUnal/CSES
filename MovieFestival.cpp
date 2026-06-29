#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

int main(){
    int n,m;
    std::cin>>n;
    std::vector<int> start(n);//price of each ticket.
    std::vector<int> end(n);
    for(int i = 0;i < n;i +=1){
        std::cin>>start[i]>>end[i];
    }
    std::sort(start.begin(),start.end());
    std::sort(end.begin(),end.end());
    // std::vector<std::pair<int,int>> movies(n);//price of each ticket.
    uint32_t count = 1;
    uint32_t i =0; 
    uint32_t j = 0;
    while(i < n and j < n){
        if(end[j] >= start[i]){
            count +=1;
            i +=1;
        }
    }
    for(uint32_t i = 1;i < n;i +=1){
    }
    std::cout<<count<<"\n";    
    return 0;
}