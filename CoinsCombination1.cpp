/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 8 ways:

2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
*/

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include<vector>
#include <iostream>

uint32_t MOD = 1e9 + 7;

int main(){
    uint32_t n,x;
    std::cin>>n>>x;
    // if(x)
    std::vector<uint32_t> coins(n);
    std::vector<uint32_t> arr(x + 1,0);
    for(int i = 0;i < n;i +=1){
        std::cin>>coins[i];
    }
    std::sort(coins.begin(),coins.end());
    arr[0] = 1;
    for(size_t i = coins[0];i <= x;i +=1){
        for(auto c:coins){
            if(c > i){
                break;
            }
            arr[i] = (arr[i] + arr[i - c])%MOD;
        }
        // std::cout<<i<<" "<<arr[i]<<"\n";
    }
    std::cout<<arr[x]<<"\n";
    return 0;
}