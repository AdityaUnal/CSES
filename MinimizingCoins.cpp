/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.

*/

#include <algorithm>
#include <cstdint>
#include<vector>
#include <iostream>

uint32_t MOD = 1e9 + 7;

int main(){
    uint32_t n,x;
    std::cin>>n>>x;
    // if(x)
    std::vector<uint32_t> coins(n);
    std::vector<uint32_t> arr(x + 1,INT32_MAX);
    for(int i = 0;i < n;i +=1){
        std::cin>>coins[i];
        if(coins[i] <= x)
        arr[coins[i]] = 1;
    }
    std::sort(coins.begin(),coins.end());
    if(coins[0] > x){
        std::cout<<-1<<"\n";
        return 0;
    }

    for(int i = 1;i <= x;i +=1){
        for(auto c:coins){
            if(c > i){
                break;
            }
            arr[i] = std::min(1 + arr[i - c],arr[i]);
        }
        // std::cout<<arr[i]<<"\n";
    }
    if(arr[x] == INT32_MAX){
        std::cout<<-1<<"\n";
        return 0;
    }
    std::cout<<arr[x]<<"\n";
    return 0;
}