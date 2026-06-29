#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

int main(){
    int n,m;
    std::cin>>n;
    std::vector<int> arrival(n);//price of each ticket.
    std::vector<int> departure(n);
    for(int i = 0;i < n;i +=1){
        std::cin>>arrival[i]>>departure[i];
    }
    std::sort(arrival.begin(),arrival.end());
    std::sort(departure.begin(),departure.end());
    uint32_t count = 0, res = 0;
    uint32_t i = 0, j = 0;
    while(i < n and j < n){
        if(departure[i] > arrival[j]){
            count +=1;
            j +=1;
        }
        else{
            count--;
            i +=1;

        }
        // std::cout<<i<<" "<<j<<" "<<count<<"\n";
        // std::cout<<arrival[i]<<" "<<departure[j]<<"\n";
        res = std::max(count,res);
    }
    std::cout<<res<<"\n";    
    return 0;
}