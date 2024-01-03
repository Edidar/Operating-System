#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    string s,s1,p;
    stack<char>st;
    int a,b,i,j,c,d;
     cout << "Enter your String :";
    cin>>s;
    s1.pb('(');
    if(s[0]=='-')
    {
        int y=0;
        if(s[1]=='(')
        {
            s1.pb('(');
            s1.pb('0');
            s1.pb('-');
            s1.pb('(');
            for(i=2; i<s.size(); i++)
            {
                if(s[i]==')' && y==0)
                {
                    y=1;
                    s1.pb(')');
                    s1.pb(')');
                }
                else
                {
                    s1.pb(s[i]);
                }
            }
        }
        else
        {
            s1.pb('(');
            s1.pb('0');
            s1.pb('-');
            s1.pb(s[1]);
            s1.pb(')');
            for(i=2; i<s.size(); i++)
            {
                s1.pb(s[i]);
            }
        }
    }
    s1.pb(')');
    cout << "\nBinary Formatted :";
    cout<<s1<<endl;
    for(i=0; i<s1.size(); i++)
    {
        if((s1[i]>='a' && s1[i]=='z')||(s1[i]=='0'))
        {
            p.pb(s1[i]);
        }
        else if(s1[i]=='(')
            st.push('(');
        else if(s1[i]==')')
        {
            while(st.top()!='(')
            {
                p.pb(st.top());
                st.pop();

            }
            st.pop();


        }
        else{
            if(st.top()=='(')
            {
                st.push(s1[i]);
            }
            else if(st.top()=='+' || st.top()=='-')
            {
                if(s1[i]=='+' || s1[i]=='-')
                {
                 p.pb(st.top());
                 st.pop();
                 st.push(s1[i]);
                }
                else{
                    st.push(s1[i]);
                }
            }
            else {

                p.pb(st.top());
                st.pop();
                st.push(s1[i]);

            }
        }
    }
    cout << "\nThe postfix :"<<endl;
    cout<<p<<endl;
    stack<string>ans;
    string s2,s4,s5,s3;
    int ct=49;
    map<string,string>m;
    map<string,string>::iterator it;
    for(i=0; i<p.size(); i++)
    {
        if(p[i]=='0' || (p[i]>='a'&&p[i]<='z'))
        {
            s5.pb(p[i]);
            ans.push(s5);
            s5.clear();
        }
        else{
            s2.clear();
            s4.clear();
            s2.pb('T');
            s3.clear();
            char q=ct;
            s2.pb(q);
            ct++;

            s3=ans.top();//b
            ans.pop();
            s4=(ans.top());//a
            ans.pop();

            s4.pb(p[i]);
            s4=s4+s3;//a+b
            m[s2]=s4;
            ans.push(s2);


        }
    }
    cout << "\nThe three address code :" << endl;
    for(it=m.begin(); it!=m.end();it++)
    {
        cout<<it->first<<"="<<it->second<<endl;
    }
}