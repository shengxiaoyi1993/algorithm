#include<iostream>
#include<vector>
#include<string>
#include"solution.hpp"
using namespace std;
int main(){
  int a[6] = {1,2,3,0,0,0} ;
  vector<int> nums1(a, a+6);
  int b[3] = {2,5,6} ;

  vector<int> nums2(b, b+3);
  cout<<"before"<<endl;
  vector<int>::iterator it;
  for (it=nums1.begin();it!=nums1.end();it++)
  {
    cout<<*it<<" "<<'\0';
  }
  cout<<endl;
  Solution tmp;
  tmp.merge(nums1,3,nums2,3);
  cout<<"after"<<endl;
  vector<int>::iterator iter;
	for (iter=nums1.begin();iter!=nums1.end();iter++)
	{
		cout<<*iter<<" "<<'\0';
	}
	cout<<endl;
  // for(){}
  return 0;
}
