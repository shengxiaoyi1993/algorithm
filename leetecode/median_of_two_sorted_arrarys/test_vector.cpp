#include<iostream>
#include<vector>

using namespace std ;

int main()
{
    vector<int> a(10, 0) ;      //大小为10初值为0的向量a

    //对其中部分元素进行输入
    cin >>a[2] ;
    cin >>a[5] ;
    cin >>a[6] ;

    //全部输出
    int i ;
    for(i=0; i<a.size(); i++)
        cout<<a[i]<<" " ;

    cout<<endl<<"a.size():"<<a.size()<<endl;

    return 0 ;
  }
