#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int> > &mat, vector <string> &ans, int x, int y, int row, int col, vector<vector<int> > &vis, string move){
    if(x == row-1 && y == col-1){
        ans.push_back(move);
        return;
    }
    if(x+1 < row && mat[x+1][y] && !vis[x+1][y]){
        vis[x][y] = 1;
        solve(mat, ans, x+1, y, row, col, vis, move+"D");
        vis[x][y] = 0;
    }
    if(y-1 >= 0 && mat[x][y-1] && !vis[x][y-1]){
        vis[x][y] = 1;
        solve(mat, ans, x, y-1, row, col, vis, move+"L");
        vis[x][y] = 0;
    }
    if(y+1 < col && mat[x][y+1] && !vis[x][y+1]){
        vis[x][y] = 1;
        solve(mat, ans, x, y+1, row, col, vis, move+"R");
        vis[x][y] = 0;
    }
    if(x-1 >= 0 && mat[x-1][y] && !vis[x-1][y]){
        vis[x][y] = 1;
        solve(mat, ans, x-1, y, row, col, vis, move+"U");
        vis[x][y] = 0;
    }
    
}

int main(){
    int row, col;
    cin>>row>>col;
    vector<vector<int> > mat(row, vector<int> (col, 0));
    vector<vector<int> > vis(row, vector<int> (col, 0));
    vector<string> ans;
    for(int i=0; i<row ;i++){
        for(int j=0; j<col ;j++){
            cin>>mat[i][j];
        }
    }
    solve(mat, ans, 0, 0, row, col, vis, "");
    cout<<ans[0]<<endl;
    cout<<ans[1];
    return 0;
}