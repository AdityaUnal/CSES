#include <cstdint>
#include <iostream> 
#include <set>

int main(){
    uint32_t n;
    std::cin>>n;
    uint32_t count = 0;
    std::set<uint32_t> s;
    for(int i = 0;i < n;i +=1){
        uint32_t x;
        std::cin>>x;
        s.insert(x);
    }
    std::cout<<s.size()<<"\n";
    return 0;
}