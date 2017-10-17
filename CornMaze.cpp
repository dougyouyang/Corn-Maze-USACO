//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <queue>
#include <stdio.h>
#include <ctype.h>

using namespace std;
queue<int> pox;
queue<int> poy;
queue<int> moves;
char mat[350][350];
int n, m;
bool visited[350][350];

int bfs(int row, int col)
{
    pox.push(row), poy.push(col);
    moves.push(1);
    int i, j;
    visited[row][col]=true;
    while(!pox.empty()){
        int x=pox.front(), y=poy.front();
        pox.pop(), poy.pop();
        if(mat[x][y]=='#'){
            moves.pop();
            continue;
        }
        if(mat[x][y]=='='){
            return moves.front();
        }
        if(isalpha(mat[x][y])){
            bool fi=false;
            for(i=0;i<n;i++){
                if(fi)
                    break;
                for(j=0;j<m;j++){
                    if(mat[i][j]==mat[x][y] && (i!=x || j!=y)){
                        x=i, y=j;
                        fi=true;
                        break;
                    }
                }
            }
        }
        if(!visited[x+1][y] || isalpha(mat[x+1][y]))
            pox.push(x+1), poy.push(y), moves.push(moves.front()+1), visited[x+1][y]=true;
        if(!visited[x][y-1] || isalpha(mat[x][y-1]))
            pox.push(x), poy.push(y-1), moves.push(moves.front()+1), visited[x][y-1]=true;
        if(!visited[x][y+1] || isalpha(mat[x][y+1]))
            pox.push(x), poy.push(y+1), moves.push(moves.front()+1), visited[x][y+1]=true;
        if(!visited[x-1][y] || isalpha(mat[x-1][y]))
            pox.push(x-1), poy.push(y), moves.push(moves.front()+1), visited[x-1][y]=true;
        moves.pop();
    }
    return 0;
}

int main()
{
    int x, y;
    int i, j;
    
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >>mat[i][j];
            if(mat[i][j]=='@')
                x=i, y=j;
        }
    }
    
    cout << bfs(x, y)-1 << endl;
    
    return 0;
}
