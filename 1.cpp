#include<cstdio>
#include<iostream>
#include<cstring>
#include<dirent.h>
#include<cstdlib>
#include<sys/stat.h>
#include<unistd.h>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<fstream>
#define pa pair<string,int>
using namespace std;
char ch[256];
map<string,vector<pa> > ind;
map<string,int> x;
void chuli(char *cc)
{
	x.clear();
	string s;
	ifstream fin(cc);
	for(;fin>>s;)
	{
           x[s]++;
	 // printf("%d\n",x[s]); 
	}
	map<string,int>::iterator map_it;
        map_it=x.begin();
        for(;map_it!=x.end();map_it++)
	  {
		  pa pa1;
                  pa1=make_pair(cc,map_it->second);
		 // printf("1");
                  ind[map_it->first].push_back(pa1);
	  }	  
          
}
void dfs(char *cc)
{
	struct dirent *wenjian;
	DIR *dir;
        dir=opendir(cc);
	if(dir!=NULL)
	  for(;(wenjian=readdir(dir))!=NULL;)
    	   {
              char ch3[256]; 
	      struct stat s;
	      sprintf(ch3,"%s/%s",cc,wenjian->d_name);			  
	     // printf("%s\n",wenjian->d_name);
	     // printf("%d\n",strncmp(wenjian->d_name,".",1));
	      lstat(ch3,&s);
	      if(S_ISDIR(s.st_mode))
		{
			if(strncmp(wenjian->d_name,".",1))
                                  dfs(ch3);
		}
	      else
		{
//	          printf("%s\n",ch3);
                 chuli(ch3);
		}
	   }
	closedir(dir);

}
int main()
{
	freopen("data","w",stdout);
	scanf("%s",ch);
        dfs(ch);
	map<string,vector<pa> >::iterator map_it;
        map_it=ind.begin();
//	if(map_it==ind.end())
//	  printf("Y");
        for(;map_it!=ind.end();map_it++)
	  {
//	    printf("2");
             string ss=map_it->first;
	     cout<<ss<<" ";
	     for(int i=0;i!=ind[ss].size();i++)       
		cout<<ind[ss][i].first<<":"<<ind[ss][i].second<<" ";
             printf("\n");
	  }
	return 0;
}
