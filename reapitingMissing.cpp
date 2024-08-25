#include<iostream>
#include<map>
using namespace std;

int main(){
      int arr[10] = {1,2,3,3,5,6,7,8,9,10};
      int n = 10;

      map<int,int>mp;

      for(int i = 0; i<n ;i++){
            mp[arr[i]]++;
      }

      int mis = -1;
      int rep = -1;

      for(int i =1; i<=n; i++){
          if(mp.find(i)==mp.end()){
            mis = i;
           // break;
          }
          if(mp[i]>1){
             rep  = i;
           //  break;
          }
      }

      cout<<mis<<" "<<rep<<endl;

      return 0;
}