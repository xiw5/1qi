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
#define pa pair<string,int>
using namespace std;
char ch2[1000000];
void chuli()
{
    char ch;
    for(;;)
      {
	 ch=getchar();
	 if(ch=='\n')
           return;
	 else if(ch==32)
		 printf("\n");
	      else
		 putchar(ch);
          
      }    
}
int main()
{
    char ch[300],ch1[300];
    scanf("%s",ch);
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
	   break;
	  }
      }
    fclose(stdin);
    return 0;
}
