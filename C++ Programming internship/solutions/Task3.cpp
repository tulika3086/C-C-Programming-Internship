// Sudoku solver using backtracking
#include <iostream>
#include <array>
#include <string>
#include <sstream>
using namespace std;

bool find_empty(const array<array<int,9>,9> &g, int &r, int &c){
    for(r=0;r<9;++r) for(c=0;c<9;++c) if(g[r][c]==0) return true;
    return false;
}

bool valid(const array<array<int,9>,9> &g, int r, int c, int val){
    for(int i=0;i<9;++i) if(g[r][i]==val) return false;
    for(int i=0;i<9;++i) if(g[i][c]==val) return false;
    int br = (r/3)*3, bc=(c/3)*3;
    for(int i=0;i<3;++i) for(int j=0;j<3;++j) if(g[br+i][bc+j]==val) return false;
    return true;
}

bool solve(array<array<int,9>,9> &g){
    int r,c;
    if(!find_empty(g,r,c)) return true;
    for(int v=1;v<=9;++v){
        if(valid(g,r,c,v)){
            g[r][c]=v;
            if(solve(g)) return true;
            g[r][c]=0;
        }
    }
    return false;
}

void print_grid(const array<array<int,9>,9> &g){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j) cout << g[i][j] << ' ';
        cout << '\n';
    }
}

int main(){
    cout << "Sudoku Solver — enter 9 lines with 9 numbers (0 for blank), or press Enter to use a sample puzzle."<<"\n";
    array<array<int,9>,9> grid{};
    string line;
    // try reading first line; if empty, use sample
    getline(cin,line);
    if(line.empty()){
        // sample puzzle
        int sample[9][9] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
        };
        for(int i=0;i<9;++i) for(int j=0;j<9;++j) grid[i][j]=sample[i][j];
    } else {
        // parse first line and remaining 8 lines
        stringstream ss(line);
        for(int j=0;j<9;++j) ss >> grid[0][j];
        for(int i=1;i<9;++i){
            getline(cin,line);
            stringstream s2(line);
            for(int j=0;j<9;++j) s2 >> grid[i][j];
        }
    }

    cout << "Input puzzle:\n"; print_grid(grid);
    if(solve(grid)){
        cout << "\nSolved puzzle:\n"; print_grid(grid);
    } else cout << "No solution found.\n";
    return 0;
}
