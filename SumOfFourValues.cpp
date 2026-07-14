#include <utility>
#include<vector>
#include<algorithm>
#include<iostream>
#include <cstdint>
#include <unordered_map>


int main()
{
    int n,x;
    std::cin>>n>>x;
    std::vector<long long> v(n);
    // std::vector<std::pair<long long,long long>> arr(n);
    for(int i = 0;i < n;i +=1){
        std::cin>>v[i];
        // arr[i] = {v[i],i};
    }
    // std::map<uint64_t,uint64_t> mp;
    // std::sort(arr.begin(),arr.end()); 
    // // After reading a[0..n-1]:
    std::unordered_map<long long, std::pair<int, int>> seen;  // sum -> (i, j)

    for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
        long long need = static_cast<long long>(x) - v[i] - v[j];
        auto it = seen.find(need);
        if (it != seen.end()) {
        auto [p, q] = it->second;
        // indices p,q,i,j are all distinct by construction
        std::cout << p + 1 << " " << q + 1 << " " << i + 1 << " " << j + 1 << "\n";
        return 0;
        }
    }
    // Only add pairs ending at i *after* searching,
    // so we never reuse index i in the same quadruple.
    for (int k = 0; k < i; ++k) {
        seen[v[k] + v[i]] = {k, i};
    }
    }
    std::cout << "IMPOSSIBLE\n";
    // std::cout<<"IMPOSSIBLE\n";
    
}