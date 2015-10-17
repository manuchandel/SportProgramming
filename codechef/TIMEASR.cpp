#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
struct Time{
  int hours,mins;
  Time(): hours(0),mins(0){}
};
Time setTime(int h,int m){
  Time t;
  t.hours=h;
  t.mins=m;
  return t;
}
int main(){
  double minhand=0,hourhand=0;
  unordered_map <int,vector<Time> > mymap;
  int h=0,m=0,i;
  while(h<12){
    int temp=(int)(min(abs(minhand-hourhand),360-abs(minhand-hourhand))*10);
    //printf("%0.2f ",(double)temp/10 );
    if(h<12)
      mymap[temp].push_back(setTime(h,m));
    minhand+=6;
    hourhand+=0.5;
    m+=1;
    if(m==60){
      h+=1;
      m=0;
    }
    if(minhand==360)
      minhand=0;
  }
  int T,b;
  double A;
  scanf("%d",&T);
  while(T--){
    cin>>A;
    double c=(int)A;
    if(c==A)
      b=A*10;
    else{
      if(abs(c+0.5-A)<(float)1/120)
        c=c+0.5;
      else if(A-c<(float)1/120);
      else if(c+1-A<(float)1/120)c++;
      else c=-1;
      c*=10;
      b=(int)c;
    }
    if(b>=0 && mymap.find(b)!=mymap.end())
      for(i=0;i<mymap[b].size();i++)
        printf("%02d:%02d\n",mymap[b][i].hours,mymap[b][i].mins);
  }
}
