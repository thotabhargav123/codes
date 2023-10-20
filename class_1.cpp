/*#include<bits/stdc++.h>
using namespace std;
class shapes{
    int a;
    int b;
    int c;
    double result;
    public:
     shapes(){
         result=0;
     }
     shapes(int l){
         a=l;
     result=  3.14*a*a;
     }
    shapes(int l,int bh){
         a=l;
         b=bh;
        result= a*b;
    }
    shapes(int l,int bh,int h){
        a=l;
        b=bh;
        c=h;
      result=a*b*c;
    }
   void display(){
       cout<<result<<endl;
   }
};
int main(){
      int l,bh,h;
      shapes o1,o2,o3,o4;
      o1={1};
      o1.display();
}*/

//******------cOPY CONSTRUCTORS------*******//
/*#include<bits/stdc++.h>
using namespace std;
class shapes{
    int a=0;
    int b=0;
    int c=0;
    double result=0;
    public:
     shapes(){
         result=0;
     }
     shapes(int l){
         a=l;
    // result=  3.14*a*a;
     }
     void area(int a){
         result=3.14*a*a;
     }
    shapes(int l,int bh){
         a=l;
         b=bh;
        //result= a*b;
    }
      void area(int a,int b){
          result=a*b;
      }
    shapes(int l,int bh,int h){
        a=l;
        b=bh;
        c=h;
     // result=a*b*c;
    }
    void area(int a,int b,int c){
         result=a*b*c;
    }
    shapes(shapes &obj){
       cout<<"copy constructor called"<<endl;
        a=obj.a+1;
        b=obj.b+1;             //----->>> MAN MADE COPY CONSTRUCTOR<<-----//
        c=obj.c+1;
        a*b*c;
        //result=obj.result;
    }
   void display(){
       cout<<result<<" "<<a<<" "<<b<<" "<<c<<endl;
   }
};
int main(){
      int l,bh,h;
      shapes o1;
      o1={2,2};
      o1.area(2,2);
      o1.display();
      shapes o4(o1);//---->>> default copy constructor<<<-----//
     // o4.area(o1);
      o4.display();
}*/

/*#include<iostream>
using namespace std;
class addition{
     private:
     double a;
     double b;
     double c;
     public:
     void setting(int a1,int a2){
         cout<<"values are setted "<<endl;
         a = a1;
         b = a2;
        summing();
        display();
     }
    void summing(){
        cout<<"Computing the sum"<<endl;
        c=a+b;
    }
    void display(){
        //summing();
        cout << "the values of the input values are " << a << " " << b << endl;
        cout << "the result is " << c << endl;
    
    }

      
};
int main(){
    addition o1;
    int n;
    int m;
    cin >> n >> m;
     o1.setting(n, m);
    // o1.display();
    
}*/

/*#include<iostream>
using namespace std;
class lnt{
  private:
      int i;

      public:
        lnt(){
            i = 0;
        }
        lnt (int ii) 
        { i = ii; }

        int add(lnt i2,lnt i3){
            i = i2.i + i3.i;
            return i;
        }
    void display(){
          cout<<i<<endl;
    }
};
        int main()
        {
            lnt int1(7);
            lnt lnt2(11);
            lnt lnt3;

            lnt3.add(lnt1,lnt2);
            lnt3.display();
        }*/

// * ! DESTRUCTOR//
/* #include <bits/stdc++.h>
using namespace std;
class comp
{
    int a;
    int b;

public:
    comp()
    {
        //cout << "the default values are arranged " << endl;
        a = 0;
        b = 0;
    }
    comp(int x, int y)
    {
        cout << "given values are atken " << endl;
        a = x;
        b = y;
    }
    void sum(comp &o1,comp &o2){
         a = o1.a + o2.a;
         b=o1.b + o2.b;
    }
   void display(){
       cout<<"entered values are showing "<< endl;
       cout<<a<<" + i"<<b<<endl;
   }
   ~comp(){
       cout << "the values erased enter new values if  u want"<<endl;
   }
};

int main()
{
    comp o1 = {2, 2};;
    //o1 = {2, 2};
    o1.display();
    comp o2 = {1, 2};
    o2.display();
    comp o3;
    o3.sum(o1,o2);
    o3.display();
}*/




//! ******CONSTRUCTOR IN MULTI CLASSES*******//
/** 
 * ? case 1:
 * * when constructor in base class have no arguments and derived class is made then there is no ambiguity.
 * ? case 2:
 * *when constructor in base class have arguments and derived class have inputs then first base class constructor runs.
 * ? case 3:
 * * In multi level inheritance first base class constructor is invoked which is first taken and next second base class
 * * invoked and at last derived class invoked.
 * @param example:
 * todo class d :public b1,public b2{};
 * *then execution is in order: b1,b2,d.
 * ? case 4(multi level inheritance):
 * todo a->b->c.
 * * constructor invokedorder is a,b,c.
 * ? case 4:
 * * when virtual class is present it is first invoked.
 * @param example:
 * todo class d:public b1,virtual public b2{};
 * * execution is in order: b2,b1,d.
 */


/*#include<bits/stdc++.h>
using namespace std;

class b1{ 
    protected:
      int data1;
    public:
     b1(void){

     }
      b1(int a){
        cout << "b1 constructor is called " << endl;
        data1 = a;
      }
    void printb1(void){
        cout << "b1 is called " << endl;
        cout<<data1 << endl;
    }
};
class b2{ 
    protected:
      int data2;
    public:
    b2(void){

    }
      b2(int bb){
         cout << "b2 constructor is called " << endl;
          data2 = bb;
      }
    void printb2(void){
        cout << "b2 is called " << endl;
        cout<<data2 << endl;
    }
};
class d:public b1,public b2{
     protected:
        int data3;
        int result;
     public:
     d(void){
         
     }
     d(int a,int b,int c):b2(a),b1(b){
         cout << "d constructor is called " << endl;
         data3 = c;
         result =data1+data2+data3;
     }
    void display_d(void){
        cout<<"d is invoked "<<endl;
        cout<<data3<<endl;
        cout<<result<<endl;
    }
};
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    d o1;
    o1={a, b, c};
    o1.printb1();
    o1.printb2();
    o1.display_d();
}*/



/**
 * todo ******* Intializing in constructor in classes done by other ways*********:
 * @param 1 //!#include <bits/stdc++.h>
 * !  using namespace std;
 * !  class comp
 * !    {
 * !   int a;
 * !   int b; 
 * ! public:
 * !comp(int x, int y)
 * !   {
 * !       cout << "given values are atken " << endl;
 * !      a = x;
 * !      b = y;
 * ! }
 * !};
 * @param 2. //!#include <bits/stdc++.h>
 * !  using namespace std;
 * !  class comp
 * !    {
 * !   int a;
 * !   int b; 
 * !   public:
 * !   comp(int x, int y):a(x),b(y)
  */