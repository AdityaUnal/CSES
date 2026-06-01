# include<iostream>
# include<cstdint>


int main(){
    int t;
    std::cin>>t;
    while(t){
        uint64_t x,y;
        std::cin>>y>>x;
        if(y > x){
            std::cout<<(y*y - (x - 1))<<"\n";
            
        }
        else if(x > y){
            std::cout<<(x*x - (y - 1))<<"\n";
            
        }
        else{
            if(x%2){
                std::cout<<(x*x - (x - 1))<<"\n";
            }
            else{
                std::cout<<(y*y - (y - 1))<<"\n";
            }
        }
        // std::cout<<([](uint64_t x,uint64_t y)->uint64_t{return (y > x) ? (y*y - (x - 1)): (x*x - (y - 1));})(x,y)<<"\n";
        t--;
    }
    return 0;
}