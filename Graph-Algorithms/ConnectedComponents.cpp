#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define N 200000

vector<vector<int> >connectedComponents;
vector<int>adjList[N];
vector<int>currComponents;
int visited[N];
int connCount = 0;

void dfs(int v){
    visited[v] = 1;
    currComponents.push_back(v);
    for(int adjVertex : adjList[v])
        if(visited[adjVertex] == 0)
            dfs(adjVertex);
}
int main(){
    int v,e,v1,v2;
    cout<<"Enter the number of vertices and edges : "<<endl;
    cin>>v;
    cin>>e;
    cout<<"Enter the "<<e<<" edges"<<endl;
    for(int i = 0;i < e;i++){
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    for(int i = 0;i < v;i++){
        if(visited[i] == 0){
            currComponents.clear();
            connCount++;
            dfs(i);
            connectedComponents.push_back(currComponents);
        }
    }
    cout<<"Number of connected components : "<<connCount<<endl;
    for(int i = 0; i < connCount;i++){
        cout<<"Connected component "<<i+1<<endl;
        for(int j = 0;j < connectedComponents[i].size();j++)
            cout<<connectedComponents[i][j]<<"\t";
        cout<<endl<<"-----------------------------------------"<<endl;

    }
}
