#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<string>andy;
    string s;
    while(getline(cin,s))
    {
        if(s=="0")
            break;

        string ss="";
        //cout<<s<<endl;

        for(int i=0;s[i];i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                ss+=s[i]+32;
            else if(s[i]>='a' && s[i]<='z')
                ss+=s[i];
            else if(ss!="")
            {
                andy.insert(ss);
                //cout<<ss<<endl;
                ss="";

            }
            //cout<<s[i];
        }
        if(ss!="")
            andy.insert(ss);
    }

    for(auto j:andy)
        cout<<j<<endl;
}
