#include <iostream>
#include <cstdint>

std::string EmptyPiles(uint32_t& a, uint32_t& b){
    if(a == b){
        if(a % 3 == 0 or a == 0){
            return "YES";
        }
        return "NO";
    }
    if(static_cast<double>((a - 2*(a/2))) == (static_cast<double>((b - a/2)))/2){
        return "YES";
    }
    if(static_cast<double>(b - 2*(b/2)) == (static_cast<double>((a - b/2))/2)){
        return "YES";
    }
    return "NO";
}

int main(){
    uint32_t t;
    std::cin>>t;
    while(t){
        uint32_t a,b;
        std::cin>>a>>b;
        std::cout<<EmptyPiles(a,b)<<"\n";
        t--;
    }
    return 0;
}