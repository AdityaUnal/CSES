/*
Time limit: 1.00 s
Memory limit: 512 MB

Given an array of n integers, your task is to calculate the number of subarrays that have at most k distinct values.
Input
The first input line has two integers n and k.
The next line has n integers x_1,x_2,\dots,x_n: the contents of the array.
Output
Print one integer: the number of subarrays.
*/

#include<set>
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <map>
#include <vector>

int main(){
    size_t n,k;
    std::cin>>n>>k;
    uint64_t res = 0;
    std::vector<uint64_t> arr(n);
    std::map<uint64_t,size_t> mp;
    std::set<size_t> lowest_index_set;
    size_t lowest = 0;
    for(int i = 0;i < n;i +=1){
        uint64_t x;
        std::cin>>x;
        arr[i] = x;
        auto itr = mp.find(x);
        if(itr == mp.end()){
            // mp[x] = i;
            if(mp.size() == k){
                auto lowest_index = *lowest_index_set.begin();
                auto num_to_remove = arr[lowest_index];
                mp.erase(num_to_remove);
                lowest_index_set.erase(lowest_index);
                lowest_index_set.insert(i);
                lowest = lowest_index + 1;
            }
            else{
                lowest_index_set.insert(i);

            }
            // lowe
            // lowest = *lowest_index_set.begin();
        }
        else{
            lowest_index_set.erase(mp[x]);
            lowest_index_set.insert(i);
        }
        mp[x] = i;
        // std::cout<<i<<" "<<lowest<<"\n";
        res += i - lowest + 1;
    }
    std::cout<<res<<"\n";
    return 0;
}