#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define N 100000

bool isPresent(int x, vector<int>v){
    for(int i = 0;i < v.size(); i++)
        if(v[i] == x)
            return true;
    return false;
}

bool dfsHasCycle(int v, set<int>unvisited,set<int>currentVertices,set<int>visited,vector<int>adjList[]){

    unvisited.erase(v);
    currentVertices.insert(v);

    for(int i = 0; i < adjList[v].size();i++){
        //If element has already been visited, we continue
        if(visited.find(adjList[v][i]) != visited.end())
            continue;

        //If element is present in current vertices that implies there is a cycle
        else if(currentVertices.find(adjList[v][i]) != currentVertices.end())
            return true;
        //If neither of the above conditions are true you do a dfs on the other vertex
        else if(dfHasCycle(adjList[v][i],unvisited,currentVertices,visited,adjList) == true)
            return true;
    }
    visited.insert(v);
    currentVertices.erase(v);
    return false;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adjList[N];
        int vert;
        set<int>unvisited,currentVertices,visited;
        bool isPossible = true;
        set<int>::iterator i1;


        for(int i = 0;i < numCourses;i++)
            unvisited.insert(i);

        for(int i = 0;i < prerequisites.size();i++){
            adjList[prerequisites[i][0]].push_back(adjList[[prerequisites[i][1]]]);
        }

        while(unvisited.size() > 0 && isPossible == true){
            i1 = unvisited.begin();
            vert = *i1;
            isPossible = !(dfsHasCycle(vert,unvisited,currentVertices,visited,adjList));
        }
        return isPossible;
    }
};
