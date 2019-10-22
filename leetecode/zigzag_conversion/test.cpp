#include<iostream>
#include<string>
using namespace std;


// int caculatenum(int n){
//   int res=1;
//   for(int i=0;i<n;i++){
//     res*=(-1);
//   }
//   return (1-res)/2;
// }

int main(){
  char array_trans[100][100]={0};


  for(int i=0;i<100;i++){
    for (int j = 0; j < 100; j++) {
      cout<<(int)array_trans[i][j];

    }
    // cout<<(i+caculatenum(i))*4<<endl;
    // cout<<(i+caculatenum(i))*4-caculatenum(i)<<endl;
  }

  return 0;
}
