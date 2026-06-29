/*
https://cses.fi/problemset/task/2216
*/

#include <cstddef>
#include<vector>
#include<iostream>
#include<cstdint>

int main(){
    size_t n;
    uint32_t m;
    std::cin>>n>>m;
    std::vector<uint32_t> arr(n);
    std::vector<uint32_t> ind(n + 1);
    ind[0] = n;
    for(int i = 0;i < n;i +=1){
        std::cin>>arr[i];
        ind[arr[i]] = i;
    }
    int l = 0;//Last Index of Curr Sweep
    int res = 1;
    for(int i = 1;i <= n;i +=1){
        if( l > ind[i]){
            res +=1;
        }
        l = ind[i];
    }
    // std::cout<<res<<"\n";
    while(m){
        uint32_t i,j,a,b;
        std::cin>>a>>b;
        i = std::min(a,b);
        j = std::max(a,b);
        i = i - 1;
        j = j - 1;
        // std::cout<<arr[i]<<" "<<arr[j]<<"\n";
        if(arr[i] + 1 == arr[j] or arr[j] + 1 == arr[i]){
            if(arr[i] + 1 == arr[j]){
                res +=1;
                // std::cout<<"res + 1 "<<res<<"\n";
            }
            else{
                res +=-1;
                // std::cout<<"res - 1 "<<res<<"\n";
            }
        }
        if(arr[i] != n and (i < ind[arr[i] + 1] and ind[arr[i] + 1] < j)  ){
            // std::cout<<"res arr[i +1] between = "<<res<<"\n";
            // std::cout<<"1. m = "<<m<<"\n";
            res +=1;
        }
        if(arr[i] != 1 and (i < ind[arr[i] - 1] and ind[arr[i] - 1] < j)) {
            // std::cout<<"res arr[i - 1] between = "<<res<<"\n";
            // std::cout<<"2. m = "<<m<<"\n";
            res +=-1;
        }
        if(arr[j] != 1 and (i < ind[arr[j] - 1] and ind[arr[j] - 1] < j) ){
            // std::cout<<"res arr[j - 1] between = "<<res<<"\n";
            // std::cout<<"3. m = "<<m<<"\n";
            res +=1;
        }
        if(arr[j] !=n and (i < ind[arr[j] + 1] and ind[arr[j] + 1] < j) ){
            // std::cout<<"res arr[j + 1] between = "<<res<<"\n";
            // std::cout<<"4. m = "<<m<<"\n";
            res +=-1;
            
        }
        std::swap(ind[arr[i]],ind[arr[j]]);
        std::swap(arr[i],arr[j]);
        std::cout<<res<<"\n";
        // for(int i : arr){
        //     std::cout<<i<<" ";
        // }
        // std::cout<<"\n";
        m--;
    }
    std::cout<<"\n";
    return 0;
}

/*
20 2
14 2 3 10 8 9 1 19 4 15 5 17 13 16 7 11 6 12 18 20
13 13
10 1
*/