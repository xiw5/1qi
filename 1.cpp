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
char ch[256],*CH[1000000];
map<string,vector<pa> > ind;
map<string,int> x;
int sum,SUM;
void qing()
{
  sum++;
  char ch2[20];
	sprintf(ch2,"text%d",sum);
	creat(ch2,0777);
  ofstream fout(ch2);
	map<string,vector<pa> >::iterator map_it;
  map_it=ind.begin();
//	if(map_it==ind.end())
//	  fout<<"Y"<<"\n";
  for(;map_it!=ind.end();map_it++)
	{
//	     printf("2");
    string ss=map_it->first;
	  fout<<ss<<" ";
	  for(int i=0;i!=ind[ss].size();i++)       
		{
		   fout<<ind[ss][i].first<<":"<<ind[ss][i].second; 
		   if(i!=ind[ss].size()-1)
		     fout<<" ";
		}
	  fout<<"\n";
	}
	ind.clear();
//	fout<<"dsffs";
  fout.close();
}
void chuli(char *cc,int a)
{
	x.clear();
	string s;
	ifstream fin(cc);
	for(;fin>>s;)
	  x[s]++;
  map<string,int>::iterator map_it;
  map_it=x.begin();
  for(;map_it!=x.end();map_it++)
	  {
		  pa pa1;
      pa1=make_pair(a,map_it->second);
		 // printf("1");
      ind[map_it->first].push_back(pa1);
	  }	  
  fin.close();  
	if(ind.size()>2000000)
    qing();  
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
			  SUM++;  
				CH[SUM]=(char *)malloc(strlen(ch3)+1);
        for(int i=0;i<strlen(ch3);i++)
				  CH[SUM][i]=ch3[i];
				CH[SUM][strlen(ch3)]='\0';
//	          printf("%s\n",ch3);
        chuli(ch3,SUM);
	 	  }
	   }
	closedir(dir);

}
void bing(int l,int r)
{
  char ch1[100],ch2[100],cc[10],cc1[10],ch11[MX],ch22[MX],ch3[8]="zhong";
  sprintf(cc,"text%d",l);
  ifstream fin(cc);
	sprintf(cc1,"text%d",(l+r)/2+1);
	ifstream fin1(cc1);
  fin>>ch1;
  fin1>>ch2;
  creat(ch3,0777);
  fin.getline(ch11,MX);
  fin1.getline(ch22,MX);
  ofstream fout(ch3);
	int kg=0;   
  for(;;)
  {
    if(ch1[0]=='\0')
	  {
	    kg=1;
	    break;
	  }
    if(ch2[0]=='\0')
	  {
	    kg=2;
	    break;
	  }
    if(strcmp(ch1,ch2)==0)
    {
      fout<<ch1<<ch11<<ch22<<"\n";
      if(!(fin>>ch1))
	    {
        kg=3;
	      break;
	    }
	    fin.getline(ch11,MX);
	    if(!(fin1>>ch2))
	    {
	      kg=2;
	      break;
	    }
	    fin1.getline(ch22,MX);
	  }
    if(strcmp(ch1,ch2)<0)
	  {
      fout<<ch1<<ch11<<"\n";
	    if(!(fin>>ch1))
      {
	      kg=1;
	      break;
	    }
	    fin.getline(ch11,MX);	
	  }
    if(strcmp(ch1,ch2)>0)
	  {
      fout<<ch2<<ch22<<"\n";
	    if(!(fin1>>ch2))
	    {
	      kg=2;
	      break;
	    }
	    fin1.getline(ch22,MX);	
	  }
  }
  if(kg==2)
    for(;;) 
    {
	    fout<<ch1<<ch11<<"\n";
      if(!(fin>>ch1))
	      break;
	    fin.getline(ch11,MX);
    }
  if(kg==1)
    for(;;) 
    {
	    fout<<ch2<<ch22<<"\n";
	    if(!(fin1>>ch2))
	      break;
	    fin1.getline(ch22,MX);
    }
	if(kg==3)
		for(;fin1>>ch2;)
		{
			fin1.getline(ch22,MX);
			fout<<ch2<<ch22<<"\n";
		}
  fin.close();
  fin1.close();
  remove(cc);
  remove(cc1);
  rename(ch3,cc);
}
void guibing(int l,int r)
{
  if(l==r)
    return;
  if(l==r-1)
  {
    bing(l,r);
    return;
  }
  int mid=(l+r)/2;
  guibing(l,mid);
  guibing(mid+1,r);
  bing(l,r);
}
int main()
{ 
//	freopen("data","w",stdout);
	scanf("%s",ch);
  dfs(ch);
	qing();
  guibing(1,sum);
	char ch[10]="lujing";
	creat(ch,0777);
	freopen("lujing","w",stdout);
	for(int i=1;i<=SUM;i++)
		printf("%s ",CH[i]);
	fclose(stdout);
	return 0;
}
//gui bing 1 hang
//61 
//18 1000000 wenbenshu
//105 1000000 yihang
//105 100 yigedanci
