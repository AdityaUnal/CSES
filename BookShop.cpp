/*
You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
Input
The first input line contains two integers n and x: the number of books and the maximum total price.
The next line contains n integers h_1,h_2,\ldots,h_n: the price of each book.
The last line contains n integers s_1,s_2,\ldots,s_n: the number of pages of each book.
Output
Print one integer: the maximum number of pages.
*/

#include <algorithm>
#include <iostream>
#include <cstdint>
#include<vector>
#include<cstddef>
#define MOD 1000000007

int main(){
    size_t n,x;
    std::cin>>n>>x;
    std::vector<uint32_t> prev(x + 1,0);
    // uint32_t prev_ways = 0;
    std::vector<uint32_t> prices(n);
    for(size_t i = 0;i < n;i +=1){
        std::cin>>prices[i];
    }
    
    std::vector<uint32_t> pages(n);
    for(size_t i = 0;i < n;i +=1){
        std::cin>>pages[i];
    }
    
    for(size_t book = 0;book < n; book +=1){
        std::vector<uint32_t> curr(x + 1,0);
        // prev_ways = 0;
        uint32_t curr_book_cost = prices[book];
        uint32_t curr_book_pages = pages[book];
        for(size_t cost = 1;cost <= x; cost +=1){
            curr[cost] = prev[cost];
            if(cost >= curr_book_cost){
                curr[cost] = (std::max(curr[cost],prev[cost - curr_book_cost] + curr_book_pages));
            }
        }
        prev = curr;
    }
    std::cout<<prev[x]<<"\n";
    return 0;
}