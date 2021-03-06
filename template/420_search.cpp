#include<iostream>
#include<cmath>
using namespace std;
template<typename T> int search(T *a, T v, int n);
class complexCls{
  double r = 0, i = 0;
  //explicit complexCls(double m=0 , double n=0) {r=m;i=n;}
  public:
  complexCls(double m = 0, double n = 0) {
    r = m; 
    i = n;
  }
  //complexCls(int m=0 , int n=0) {r=m;i=n;}
  void Show(){
    cout << '(' << r << ',' << i << ')' << '\t' << endl;
  }
  double Magnitude(){
    return sqrt(r * r + i * i );
  }
  //operator bool() const {cout<<"aaa:::: "<<endl;return r==0 && i==0 ? false : true;}
  bool operator!() const {
    cout << "aaa:::: " << endl;
    return !(r == 0 && i == 0 ? false : true);
  }
  complexCls operator++(void){   // ++a
    cout << "not int";
    i++; 
    r++;    
    return *this;  
  }
  complexCls operator++(int dummy){ // a++
    cout<<"int";    
    complexCls result = *this;    
    r++;    
    i++;    
    return result;  
  }
  friend complexCls operator +(const complexCls& a, const complexCls& b);
  friend complexCls operator -(const complexCls& a,const complexCls& b);
  friend complexCls operator *(const complexCls& a, const complexCls& b);
  friend bool operator ==(const complexCls& a, const complexCls& b);
  friend ostream& operator << (ostream& o1, const complexCls& a);
};
bool operator ==(const complexCls& a, const complexCls& b){
  return a.r == b.r && a.i == b.i;
}
ostream& operator << (ostream& o1, const complexCls& a){
   o1 << '(' << a.r << ", " << a.i << ')' ;
   return o1;
}
complexCls operator +(const complexCls& a, const complexCls& b){
  complexCls result ;
  result.r = a.r + b.r;
  result.i = a.i + b.i;
  return result;
}
complexCls operator -(const complexCls& a,const complexCls& b){
  complexCls result ;
  result.r = a.r - b.r;
  result.i = a.i - b.i;
  return result;
}
complexCls operator *(const complexCls& a, const complexCls& b){
  complexCls result;
  result.r = a.r * b.r;
  result.i = a.i * b.i;
  return result;
}
int main(){
  double ae[20]={3, 4, 5, 6, 8, 9};
  cout << search<double>(ae, 3, 6) << endl;
  cout << search<double>(ae, 33, 6) << endl;
  string am[] = {"ali", "reza", "kamran", "hamid"};
  cout << search<string>(am, "reza", 4) << endl;
  cout << search<string>(am, "rahman", 4) << endl;
  complexCls cmar[] = { {2, 3},  {4, 5}, {6, 7}};
  cout << search<complexCls>(cmar, complexCls(4, 6), 3) << endl;
  cout << search<complexCls>(cmar, complexCls(8, 12), 3) << endl;
  return 0;
}
template<typename T> int search(T *a, T v, int n){
  for(int i = 0; i < n; i++)
    if(a[i] == v)
      return i;
  return -1;
}
