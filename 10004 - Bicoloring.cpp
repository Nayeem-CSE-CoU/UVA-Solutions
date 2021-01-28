#include<bits/stdc++.h>
using namespace std;
bool biColor(vector<vector<int>>graph)
{
    vector<bool>visited(graph.size(),0),color(graph.size(),0);
    queue<int>q;
    visited[0]=1;
    q.push(0);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int i:graph[temp])
        {
            if(visited[i]==0)
                {
                    visited[i]=1;
                    color[temp]==0?color[i]=1:color[i]=0;
                    q.push(i);
                }
            else if(visited[i])
                if(color[i]==color[temp])
                    return 0;
        }
    }
    return 1;
}
int main()
{
    int node,edge;
    while(cin>>node)
    {
        if(node==0)
            break;
        cin>>edge;
        vector<vector<int>>graph(node);
        for(int i=0;i<edge;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        (biColor(graph)==1)?cout<<"BICOLORABLE.":cout<<"NOT BICOLORABLE.";
        cout<<endl;

    }
}
