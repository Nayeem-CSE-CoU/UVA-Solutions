#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("G://input.txt","r",stdin);
    //freopen("G://output.txt","w",stdout);
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
       stack<char>s;
       string str;

       getline(cin,str);

       int i;
       for(i=0;str[i];i++)
       {
           if(str[i]=='(' || str[i]=='{' || str[i]=='[')
                s.push(str[i]);
           else if(str[i]==')')
               {
                   if(s.empty() || s.top()!='(')
                   {
                       s.push('f');
                       break;
                   }
                    s.pop();
               }
            else if(str[i]=='}')
                {
                   if(s.empty() || s.top()!='{')
                   {
                       s.push('f');
                       break;
                   }
                    s.pop();
                }
            else if(str[i]==']')
            {
               if(s.empty() || s.top()!='[')
               {
                   s.push('f');
                   break;
               }
                s.pop();
            }
       }

       if(s.empty())
            cout<<"Yes"<<endl;
       else
            cout<<"No"<<endl;

    }
    return 0;

}
