#include <algorithm>
#include<iostream>
#include <vector>

int main(){
    int n;
    std::cin>>n;
    std::vector<int> arr(n - 1);
    for(int i = 0;i < n - 1;i +=1){
        std::cin>>arr[i];
    }
    std::sort(arr.begin(),arr.end());
    int l = 0;
    int r = n - 1;
    while(l < r){
        int mid = (l + r)/2;
        // std::cout<<l<<" "<<r<<"\n";
        if(arr[mid] == mid + 1){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    std::cout<<l + 1<<"\n";
    return 0;
}