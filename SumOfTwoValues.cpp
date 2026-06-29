#include <map>
#include <iostream>
#include <cstdint>

int main(){
    uint32_t n,x;
    std::cin>>n>>x;
    std::map<uint32_t,uint32_t> mp;
    for(uint32_t i = 0;i < n;i +=1){
        uint32_t temp;
        std::cin>>temp;
        if(x > temp){
            if(mp.find(x - temp) != mp.end()){
                std::cout<<mp[x - temp]<<" "<<i + 1<<"\n";
                return 0;
            }
        }
        mp[temp] = i + 1;
        // std::cout<<temp<<" "<<mp[temp]<<"\n";
    }
    std::cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}