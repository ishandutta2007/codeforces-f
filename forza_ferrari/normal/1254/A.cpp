#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,m,k,sum,a,b;
char ans[101][101],tag;
bool mp[101][101],vis[101][101];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(ans,0,sizeof ans);
        memset(vis,0,sizeof vis);
        memset(mp,0,sizeof mp);
        scanf("%d%d%d",&n,&m,&k);
        a=b=sum=0;
        tag='0';
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=m;++j)
            {
                char c=getchar();
                while(c!='.'&&c!='R')
                    c=getchar();
                mp[i][j]=(c=='R');
                sum+=mp[i][j];
            }
        int i=1,j=1,cnt=sum/k,tot=0;
        b=sum-cnt*k,a=k-b;
        while(1)
        {
            while(i<=n&&!vis[i][j])
            {
                tot+=mp[i][j];
                vis[i][j]=1;
                ans[i][j]=tag;
                if(tot==cnt+1)
                {
                    --b;
                    tot=0;
                    if(tag=='9')
                        tag='A'-1;
                    if(tag=='Z')
                        tag='a'-1;
                    ++tag;
                    if(!a&&!b)
                        break;
                }
                if(tot==cnt&&a)
                {
                    --a;
                    tot=0;
                    if(tag=='9')
                        tag='A'-1;
                    if(tag=='Z')
                        tag='a'-1;
                    ++tag;
                    if(!a&&!b)
                        break;
                }
                ++i;
            }
            --i;
            ++j;
            if(!a&&!b)
                break;
            while(j<=m&&!vis[i][j])
            {
                tot+=mp[i][j];
                vis[i][j]=1;
                ans[i][j]=tag;
                if(tot==cnt+1)
                {
                    --b;
                    tot=0;
                    if(tag=='9')
                        tag='A'-1;
                    if(tag=='Z')
                        tag='a'-1;
                    ++tag;
                    if(!a&&!b)
                        break;
                }
                if(tot==cnt&&a)
                {
                    --a;
                    tot=0;
                    if(tag=='9')
                        tag='A'-1;
                    if(tag=='Z')
                        tag='a'-1;
                    ++tag;
                    if(!a&&!b)
                        break;
                }
                ++j;
            }
            --j;
            --i;
            if(!a&&!b)
                break;
            while(i>=1&&!vis[i][j])
            {
                tot+=mp[i][j];
                vis[i][j]=1;
                ans[i][j]=tag;
                if(tot==cnt+1)
                {
                    --b;
                    tot=0;
                    if(tag=='9')
                        tag='A'-1;
                    if(tag=='Z')
                        tag='a'-1;
                    ++tag;
                    if(!a&&!b)
                        break;
                }
                if(tot==cnt&&a)
                {
                    --a;
                    tot=0;
                    if(tag=='9')
                        tag='A'-1;
                    if(tag=='Z')
                        tag='a'-1;
                    ++tag;
                    if(!a&&!b)
                        break;
                }
                --i;
            }
            ++i;
            --j;
            if(!a&&!b)
                break;
            while(j>=1&&!vis[i][j])
            {
                tot+=mp[i][j];
                vis[i][j]=1;
                ans[i][j]=tag;
                if(tot==cnt+1)
                {
                    --b;
                    tot=0;
                    if(tag=='9')
                        tag='A'-1;
                    if(tag=='Z')
                        tag='a'-1;
                    ++tag;
                    if(!a&&!b)
                        break;
                }
                if(tot==cnt&&a)
                {
                    --a;
                    tot=0;
                    if(tag=='9')
                        tag='A'-1;
                    if(tag=='Z')
                        tag='a'-1;
                    ++tag;
                    if(!a&&!b)
                        break;
                }
                --j;
            }
            ++j;
            ++i;
            if(!a&&!b)
                break;
        }
        if(tag=='a')
            tag='Z'+1;
        if(tag=='A')
            tag='9'+1;
        --tag;
        for(register int i=1;i<=n;++i)
        {
            for(register int j=1;j<=m;++j)
                putchar(ans[i][j]? ans[i][j]:tag);
            puts("");
        }
    }
    return 0;
}