#include<stdio.h>
#include<cstring>
using namespace std;
char s[1000001],s1[1001],s2[1001],*p,*q,*q1,sp[1000001];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i,pp1,pp2,ps,pd,k,n1,n2,p1,p2,x;
    char c;
    scanf("%s%s%s",&s,&s1,&s2);
    n=strlen(s);
    n1=strlen(s1);
    n2=strlen(s2);
    strcpy(sp,s);
    p=strstr(sp,s1);
    q1=strstr(sp,s2);
    q=q1;
    if(q!=NULL){
        p2=q1-sp;
        sp[p2]='1';
    }
    while(q1!=NULL){
        q1=strstr(sp,s2);
        if(q1!=NULL){
            q=q1;
            p2=q1-sp;
            sp[p2]='1';
        }
    }
    if(p==NULL||q==NULL)
        ps=0;
    else{
        p1=p-sp;
        p2=q-sp;
        if(p1+n1-1>=p2)
            ps=0;
        else
            ps=1;
    }
    for(i=0;i<=(n-1)/2;i++){
        c=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=c;
    }
    p=strstr(s,s1);
    q1=strstr(s,s2);
    q=q1;
    if(q!=NULL){
        p2=q1-s;
        s[p2]='1';
    }
    while(q1!=NULL){
        q1=strstr(s,s2);
        if(q1!=NULL){
            q=q1;
            p2=q1-s;
            s[p2]='1';
        }
    }
    if(p==NULL||q==NULL)
        pd=0;
    else{
        p1=p-s;
        p2=q-s;
        if(p1+n1-1>=p2)
            pd=0;
        else
            pd=1;
    }
    if(ps==1&&pd==1)
        printf("both");
    if(ps==1&&pd==0)
        printf("forward");
    if(ps==0&&pd==1)
        printf("backward");
    if(ps==0&&pd==0)
        printf("fantasy");
    return 0;
}