#include <cstddef>
#include <utility>
#include<vector>
#include<algorithm>
#include<iostream>
#include <cstdint>
#include <stack>


int main()
{
    size_t n;
    std::cin>>n;
    std::vector<uint64_t> v(n);
    // std::vector<std::pair<long long,long long>> arr(n);
    for(int i = 0;i < n;i +=1){
        std::cin>>v[i];
        // arr[i] = {v[i],i};
    }
    std::stack<std::pair<uint64_t, size_t>> st;
    std::vector<size_t> res(n,0);
    for(int i = n - 1;i >= 0;i--){
        while(!st.empty() and st.top().first > v[i]){
            // std::cout<<st.top().second<<"\n";
            res[st.top().second] = i + 1;
            st.pop();
        }
        st.push({v[i],i});
    }
    for(auto i : res){
        std::cout<<i<<" ";
    }
    std::cout << "\n";
    // std::cout<<"IMPOSSIBLE\n";
    
}