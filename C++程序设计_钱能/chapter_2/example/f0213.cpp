#include<iostream>
using namespace std;

int main(){
  int chick=1;
  for (int cock=1;cock<=13;cock++){ // 条件1 全部大于0，所以公鸡最多98只
    for(int hen=1;hen<=18;hen++){
      chick=100-hen-cock; // 条件2 一共100只
      // cout<<"cock: "<<cock<<" hen: "<<hen<<" chick: "<<chick<<endl;
      if(chick%3!=0) continue; // 条件3 小鸡为3的倍数
      if((7*cock+5*hen+chick/3)==100) { // 条件4 一共100元
        cout<<"cock: "<<cock<<" hen: "<<hen<<" chick: "<<chick<<endl;
      }
    }
  }
}