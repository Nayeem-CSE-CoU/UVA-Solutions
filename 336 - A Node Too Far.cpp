#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("output.txt","w",stdout);
    int cs=1;
    int edge;
    while(cin>>edge)
    {
        if(edge==0)
            break;
        map<int,vector<int>>graph;

        for(int i=0;i<edge;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);

        }

        int src,val;
        while(cin>>src>>val)
            {
                if(src==0 && val==0)
                    break;
                map<int,int>visited;
                queue<int>q;
                q.push(src);
                visited[src]=0;

                while(!q.empty())
                {
                    int temp=q.front();q.pop();
                    for(int u:graph[temp])
                    {

                        if(!visited.count(u))
                        {
                            visited[u]=visited[temp]+1;
                            q.push(u);
                        }
                    }

                }
                int ans=0;
                for(auto m:visited)
                    if(m.second>val)
                        ans++;

                    ans+=graph.size()-visited.size();

            cout<<"Case "<<cs++<<": "<<ans<<" nodes not reachable from node "<<src<<" with TTL = "<<val<<"."<<endl;




            }
    }
}
