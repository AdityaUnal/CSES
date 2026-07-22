#include <bitset>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <iostream>

void DFS(std::vector<std::vector<char>>& arr,  std::vector<std::vector<std::string>>&  paths,
    size_t row,size_t column,std::string curr_path,const size_t& starting_row,const size_t& starting_col,
    const size_t& rows,const size_t& columns){
        // std::cout<<row<<" "<<column<<"\n";
    if(arr[row][column] == '#'){
        return ;
    }

    if(row == starting_row and column == starting_col and curr_path!=""){
        return ;
    }

    if(paths[row][column] != ""){
        if(paths[row][column].length() <= curr_path.length() ){
            return ;
        }
    }

    paths[row][column] =  curr_path;

    if(arr[row][column] == 'B'){
        return ;
    }

    // arr[row][column] = true;
    if(row != 0){
        DFS(arr,paths,row - 1,column,curr_path + 'U',starting_row,starting_col,rows,columns);                
    }
    
    if(column != 0){
        DFS(arr,paths,row,column - 1,curr_path + 'L',starting_row,starting_col,rows,columns);                
        // DFS(arr,row ,column - 1,rows,columns);                
    }
    
    if(row != rows - 1){
        DFS(arr,paths,row + 1,column,curr_path + 'D',starting_row,starting_col,rows,columns);                
        // DFS(arr,row + 1,column,rows,columns);                
    }
    
    if(column != columns - 1){
        DFS(arr,paths,row,column + 1,curr_path + 'R',starting_row,starting_col,rows,columns);                
        // DFS(arr,row ,column + 1,rows,columns);                
    }
}

int main(){
    size_t n,m;
    std::cin>>n>>m;
    // std::vector<std::vector<char>> arr(n,std::vector<char>(m,0));
    std::vector<std::vector<char>> arr(n,std::vector<char>(m));
    std::vector<std::vector<std::string>> paths(n,std::vector<std::string>(m,""));
    size_t start_row , start_col;
    size_t end_row , end_col;
    for(size_t i = 0;i < n;++i){
        for(size_t j = 0;j < m;++j){
            std::cin>>arr[i][j];
            if(arr[i][j] == 'A'){
                start_row = i;
                start_col = j;
            }
            if(arr[i][j] == 'B'){
                end_row = i;
                end_col = j;
            }
        }
    }
    // std::cout<<arr[356][43]<<" "<<paths[356][43]<<"\n";
    // std::cout<<arr[354][43]<<" "<<paths[354][43]<<" |"<<"\n";

    DFS(arr, paths, start_row, start_col, "", start_row, start_col, 
        n, m) ; 

    if(paths[end_row][end_col] == ""){
        std::cout<<"NO"<<"\n";
        return 0;
    }
    else{
        std::cout<<"YES"<<"\n";
    }
    std::cout<<paths[end_row][end_col].length()<<"\n";
    std::cout<<paths[end_row][end_col]<<"\n";
    // for(auto i:paths[end_row][end_col]){
    //     std::cout
    // }
    // const uint32_t cols = m;

    return 0;
}