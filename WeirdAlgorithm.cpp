#include<iostream>

int main(){
    long long n = 0;
    std::cin>>n;
    while(n!=0){
        std::cout<<n<<" ";
        if(n%2 and n!=1){
            n = 3*n + 1;
        }
        else{
            n = n/2;
        }
    }
    return 0;
}