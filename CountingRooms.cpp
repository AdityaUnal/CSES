#include <bitset>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <iostream>

void DFS(std::vector<std::vector<bool>>& arr, size_t row,size_t column,size_t& rows,size_t& columns){
    if(arr[row][columns]){
        return;
    }
    arr[row][column] = true;
    if(row != 0){
        DFS(arr,row - 1,column,rows,columns);                
    }
    
    if(column != 0){
        DFS(arr,row ,column - 1,rows,columns);                
    }
    
    if(row != rows - 1){
        DFS(arr,row + 1,column,rows,columns);                
    }
    
    if(column != columns - 1){
        DFS(arr,row ,column + 1,rows,columns);                
    }
}

int main(){
    size_t n,m;
    std::cin>>n>>m;
    // std::vector<std::vector<char>> arr(n,std::vector<char>(m,0));
    std::vector<std::vector<bool>> mark(n,std::vector<bool>(m,true));
    for(size_t i = 0;i < n;++i){
        for(size_t j = 0;j < m;++j){
            char c;
            std::cin>>c;
            if(c == '.'){
                mark[i][j] = false;
            }
        }
    }
    uint32_t res = 0;
    for(size_t i = 0;i < n;++i){
        for(size_t j = 0;j < m;++j){
            if(mark[i][j] == false){
                DFS(mark,i,j,n,m);  
                ++res;              
            }
        }
    }
    std::cout<<res<<"\n";
    // const uint32_t cols = m;

    return 0;
}