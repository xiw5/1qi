#include<cstdio>
#include<iostream>
#include<cstring>
#include<dirent.h>
#include<cstdlib>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<fstream>
#include<fcntl.h>
#define MX 1000000
#define pa pair<int,int>
using namespace std;
char ch2[1000000],*CH[1000000];
pa A[1000000];
int SUM,SUM1;
bool cmp(pa a,pa b)
{
	return a.second<b.second;
}
void chuli()
{
    char ch;
		int n;
    for(;;)
      {
	      scanf("%d",&A[SUM1].first);
				ch=getchar();
				scanf("%d",&A[SUM1].second);
				ch=getchar();
                                SUM1++;
        if(ch=='\n')
					return;
				
      }    
}
int main()
{
    char ch[300],ch1[300];
		scanf("%s",ch);
		freopen("lujing","r",stdin);
		for(;scanf("%s",ch1)!=EOF;)
		{
			SUM++;
			CH[SUM]=(char *)malloc(strlen(ch1)+1);
			for(int i=0;i<strlen(ch1);i++)
        CH[SUM][i]=ch1[i];
			CH[SUM][strlen(ch1)]='\0';
		}
		fclose(stdin);
		int n=strlen(ch);
    freopen("text1","r",stdin);
    for(;scanf("%s",ch1)!=EOF;)
      {
         if(strcmp(ch,ch1))
          {
             cin.getline(ch2,MX);
             continue;
	  			}
      	 else
          {
            chuli();
						sort(A,A+SUM1,cmp);
						for(int i=0;i<SUM1;i++)
							printf("%s:%d\n",CH[A[i].first],A[i].second);
	  			  break;
	 			  }
      }
    fclose(stdin);
    return 0;
}
//ch2,CH
