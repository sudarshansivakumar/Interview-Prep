#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>

using namespace std;
#define N 100

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int dr[] = {-1,-1,-1,0,1,1,1,0};
        int dc[] = {-1,0,1,1,1,0,-1,-1};
        int visited[N][N];
        queue<int> qx;
        queue<int> qy;

        vector<vector<pair<int,int>>> prev;
        vector<pair<int,int> >buffer;
        for(int i = 0; i < n;i++){
            buffer.clear();
            for(int j = 0;j < n;j++)
                buffer.push_back(make_pair(-1,-1));
            prev.push_back(buffer);
        }
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                visited[i][j] = 0;

        int distance = 0,startx = 0,starty = 0, endx = n-1, endy = n-1,reached = 0,currx,curry,rr,cc;
        qx.push(startx);
        qy.push(starty);

        if(grid[startx][starty] == 1)
                return -1;
        int numNodes = 1;
        visited[startx][starty] = 1;
        while( !(qx.empty() || qy.empty())&& reached == 0){
            currx = qx.front();
            curry = qy.front();
            //visited[currx][curry] = 1;
            cout<<"Current X : "<<currx<<"\t"<<"Current Y : "<<curry<<endl;
            qx.pop();
            qy.pop();
            for(int i = 0; i < 8;i++){
                rr = currx + dr[i];
                cc = curry + dc[i];
                if( rr < 0 || cc < 0)
                    continue;
                else if(rr >= n || cc >= n)
                    continue;

                else if(grid[rr][cc] == 0 && visited[rr][cc] == 0){
                    qx.push(rr);
                    qy.push(cc);
                    visited[rr][cc] = 1;
                    if(rr == endx && cc == endy)
                        reached = 1;
                    prev[rr][cc] = make_pair(currx,curry);
                    cout<<"Previous of ("<<rr<<","<<cc<<") is "<<"("<<currx<<","<<curry<<")"<<endl;
                }
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++)
                cout<<get<0>(prev[i][j])<<' '<<get<1>(prev[i][j])<<'\t';
            cout<<endl;

        }

        if(reached == 0)
            return -1;
       else{
            currx = endx;
            curry = endy;
            while( !(currx == 0 && curry == 0)){
                numNodes++;
                currx = (prev[currx][curry]).first;
                curry = (prev[currx][curry]).second;
            }
            return numNodes;
        }
        return 4;
    }
};
int main(){

}
