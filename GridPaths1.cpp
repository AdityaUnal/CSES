#include <iostream>
#include <cstdint>
#include<vector>
#include<cstddef>
#define MOD 1000000007

int main(){
    size_t n;
    std::cin>>n;
    std::vector<uint32_t> prev(n,0);
    uint32_t prev_ways = 0;
    for(size_t row = 0;row < n; row +=1){
        prev_ways = 0;
        for(size_t column = 0;column < n; column +=1){
            char num;
            std::cin>>num;
            if(num =='*'){
                prev_ways = 0;
                prev[column] = 0;
            }
            else{
                if(row == 0 and column == 0){
                    prev_ways = 1;
                }
                prev_ways = (prev_ways + prev[column])%MOD;
                prev[column] = prev_ways;
            }
        }
    }
    std::cout<<prev_ways<<"\n";
    return 0;
}