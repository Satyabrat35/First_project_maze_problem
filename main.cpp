/***************maze problem*************Satyabrat's solution**************/
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define sz size
#define pb push_back
#define mp make_pair
#define bg begin
#define nd end
using namespace std;
bool chk(int x,int y,int n,int m)
{if(x>=1 && x<=n)
{if(y>=1 && y<=m)
    return true;
}
  return false;
}
int main()
{ int n,m,p;
cout<<"enter the size of the matrix and the no blocks present in it\n";
cin>>n>>m>>p;
int a[n+1][m+1];
vector<pair<int,int> > v;
map<pair<int,int>,int> m1,m2;
memset(a,0,sizeof(a));
cout<<"the location of the blocked cell\n";
for(int i=0;i<p;i++)
{int x,y;
 cin>>x>>y;
 a[x][y]=-1;
}
pair<int,int> px,py;
cout<<"enter starting and ending points";
for(int i=0;i<2;i++)
{int r,w;
cin>>r>>w;
if(i==0)
{px.first=r;
 px.second=w;
}
else
{py.first=r;
 py.second=w;
}
a[r][w]=2;
}
for(int i=1;i<=n;i++)
{for(int j=1;j<=m;j++)
{m1[pair<int,int>(i,j)]=0;
 m2[pair<int,int>(i,j)]=0;
}
}
for(int i=1;i<=n;i++)
{for(int j=1;j<=m;j++)
    {if(a[i][j]==0)
        {if((a[i-1][j]==0 ||a[i-1][j]==2) &&(chk(i-1,j,n,m)))
        m1[pair<int,int>(i,j)]+=1;
        if((a[i+1][j]==0 ||a[i+1][j]==2) && (chk(i+1,j,n,m)))
        m1[pair<int,int>(i,j)]+=1;
        if((a[i][j-1]==0 ||a[i][j-1]==2) && (chk(i,j-1,n,m)))
        m1[pair<int,int>(i,j)]+=1;
        if((a[i][j+1]==0 || a[i][j+1]==2) && (chk(i,j+1,n,m)))
        m1[pair<int,int>(i,j)]++;
        if(a[i-1][j]==2 && chk(i-1,j,n,m))
            m2[pair<int,int>(i,j)]++;
        if(a[i+1][j]==2 && chk(i+1,j,n,m))
            m2[pair<int,int>(i,j)]++;
        if(a[i][j-1]==2 && chk(i,j-1,n,m))
            m2[pair<int,int>(i,j)]++;
        if(a[i][j+1]==2 && chk(i,j+1,n,m))
            m2[pair<int,int>(i,j)]++;

        }
    }
}
for(int i=1;i<=n;i++)
{for(int j=1;j<=m;j++)
{if(a[i][j]==0)
{if(m2[pair<int,int>(i,j)]==1 && m1[pair<int,int>(i,j)]==1)
    a[i][j]=-1;
}
}}
for(int i=1;i<=n;i++)
{for(int j=1;j<=m;j++)
{if(a[i][j]==0)
{if(m1[pair<int,int>(i,j)]>=2 || m2[pair<int,int>(i,j)]>=1)
    {pair<int,int> p;
    p.first=i;
    p.second=j;
    v.push_back(p);
    }
}}
}

/*for(unsigned int i=0;i<v.size();i++)
cout<<v[i].first<<","<<v[i].second<<endl;*/
unsigned int l=v.size()+2;
pair<int,int> p1[l];
p1[0].first=px.first;
p1[0].second=px.second;
p1[l-1].first=py.first;
p1[l-1].second=py.second;
for(unsigned int i=0;i<v.size();i++)
{
    p1[i+1].first=v[i].first;
    p1[i+1].second=v[i].second;
}
for(int j=1;j<l-1;j++)
{ if(p1[0].first==p1[j].first && p1[0].second==p1[j].second-1)
    {p1[1].first=p1[j].first;
     p1[1].second=p1[j].second;
    }
  if(p1[0].first==p1[j].first && p1[0].second==p1[j].second+1)
    {p1[1].first=p1[j].first;
     p1[1].second=p1[j].second;
    }
    if(p1[0].first==p1[j].first+1 && p1[0].second==p1[j].second)
    {p1[1].first=p1[j].first;
     p1[1].second=p1[j].second;
    }
    if(p1[0].first==p1[j].first-1 && p1[0].second==p1[j].second)
    {p1[1].first=p1[j].first;
     p1[1].second=p1[j].second;
    }
    if(p1[l-1].first==p1[j].first && p1[l-2].second==p1[j].second-1)
    {p1[l-2].first=p1[j].first;
     p1[l-2].second=p1[j].second;
    }
    if(p1[l-1].first==p1[j].first && p1[l-2].second==p1[j].second+1)
    {p1[l-2].first=p1[j].first;
     p1[l-2].second=p1[j].second;
    }
    if(p1[l-1].first==p1[j].first+1 && p1[l-2].second==p1[j].second)
    {p1[l-2].first=p1[j].first;
     p1[l-2].second=p1[j].second;
    }
    if(p1[l-1].first==p1[j].first-1 && p1[l-2].second==p1[j].second)
    {p1[l-2].first=p1[j].first;
     p1[l-2].second=p1[j].second;
    }
}

for(unsigned int i=1;i<l-1;i++)
{for(unsigned int j=i+1;j<l-1;j++)
{if(p1[i].first==p1[i-1].first && p1[i].second==p1[i-1].second-1)
        continue;
 else if(p1[i].first==p1[i-1].first && p1[i].second==p1[i-1].second+1)
        continue;
 else if(p1[i].first==p1[i-1].first+1 && p1[i].second==p1[i-1].second)
        continue;
 else if(p1[i].first==p1[i-1].first-1 && p1[i].second==p1[i-1].second)
        continue;
else {if(p1[i].first==p1[j].first && p1[i].second==p1[j].second+1)
    {swap(p1[i].first,p1[j].first);
     swap(p1[i].second,p1[j].second);}
     else if(p1[i].first==p1[j].first && p1[i].second==p1[j].second-1)
     {swap(p1[i].first,p1[j].first);
     swap(p1[i].second,p1[j].second);}
     else if(p1[i].first==p1[j].first+1 && p1[i].second==p1[j].second)
     {swap(p1[i].first,p1[j].first);
     swap(p1[i].second,p1[j].second);}
      else if(p1[i].first==p1[j].first-1 && p1[i].second==p1[j].second)
     {swap(p1[i].first,p1[j].first);
     swap(p1[i].second,p1[j].second);}
     else
        continue;
}}
}
//if(p1[l-1].second==p1[l-2].second && p1[l-1].first==p1[l-2].first+1)
    p1[l-2].first=v[l-3].first;
    p1[l-2].second=v[l-3].second;
    if(abs(p1[l-1].second-p1[l-2].second)>1 || abs(p1[l-1].first-p1[l-2].first)>1)
        {swap(p1[l-2].first,p1[l-3].first);
        swap(p1[l-2].second,p1[l-3].second);}
cout<<endl;
cout<<"PATH SHOWN BELOW\n";
for(unsigned int i=0;i<l;i++)
    cout<<p1[i].first<<","<<p1[i].second<<endl;
    return 0;
}
