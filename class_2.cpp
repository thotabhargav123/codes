                                 //?DYNAMIC MEMORY ALLOCATION//
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int *array = new int[n];//!new operator or function allocates dynamic memory.
    for(int i=0; i<n;i++){
        cin>>*(array+i);
    }
for(int i=0; i<n;i++){
    cout << *(array + i) << " ";
}
cout << endl;
  delete[] array; //! delete's opearator or function deletes the allocated memory.

  for(int i=0; i<n;i++){
    cout << *(array + i) << " ";
}
cout << endl;
for (int i = 0; i < n; i++)
{
    cout << (array + i) << " ";
}
}*/


                            //? pointer in the classes by using new opearator ///



/* #include <bits/stdc++.h>
using namespace std;
class comp
{
    int r, i;

public:
    void setdata(int a, int b)
    {
        r = a;
        i = b;
    }
    void getdata(void)
    {
        cout << r << endl;
        cout << i << endl;
    }
};
int main()
{
    int x, y;
    cin>>x>>y;
    comp o1;
    o1.setdata(x, y); //todo :normal methood
    o1.getdata();
    //*or//  
    //todo :using pointer methood
    comp o2;
    comp *abc = &o2;
    o2.setdata(x, y);
    (*abc).getdata();
     //*or// 
     //todo :using pointer and dynamic memory allocation methood//
    comp *a=new comp;
    (*a).setdata(x, y);
    (*a).getdata();
    //? INSTEAD OF USING * AND . THIS WE CAN USE -> AS POINTER.//
    comp *b=new comp;
    b->setdata(x, y);
    b->getdata();
    //*or//
    comp c;
    comp *abcd=&c;
    abcd->setdata(x, y);
    c.getdata();
    //*or//
    comp *comp_class_pointer;
    comp o7;
    comp_class_pointer = &o7;
    comp_class_pointer->setdata(x, y);
    o7.getdata();
    }*/

                                     //! ARRAY OF OBJECTS//

/*#include<bits/stdc++.h>
using namespace std;
class shop{
    int price;
    static int count;
    public:
        int counter;
        void setprice(int p)
        {
            price = p;
            counter = count;
            count++;
    }
 void show(){
     cout<<"price of item: "<<counter+1<<" is "<<price<<endl;

 }
 
};
int shop::count;
int main(){
    int n;
    cin>>n;
    shop array[n];
    int i = 0;
    //shop oi;
    for( i=0; i<n;i++){
        cout<<"set the priceof item "<<i+1<<endl;
        int x;
        cin >> x;
        array[i].setprice(x);
    }
    for(int i=0; i<n;i++){
        array[i].show();
    }
}*/


  
     
        //? ****POINTER AND ARRAY OF OBJECTS****.//


#include<bits/stdc++.h>
using namespace std;
class shop{
    string name;
    float price;
    int id;
    static int count;
     public:
         int counter;
         void setdata(string s, int i , float n)
         {
             name = s;
             id = i;
             price = n;
             counter = count;
             count++;
        }
    void display(){
        cout << "Item number " << counter + 1 << " details are :";
        cout << "ID of the item is " << id << " and name is "<<name <<endl;
        cout<<"the price is " << price <<endl;
    }
};
int shop::count;
int main(){

    int size;
    cin>>size;
    shop *items = new shop[size];
    shop *itemtemp=items;
    for (int i = 0;i<size;i++){
        cout << "Enter the name id and price of  item " << i + 1 << endl;
        string x;
        int y;
        float z;
        cin >> x >> y >> z;
        items->setdata(x, y, z);
        items++;
    }

    for (int i = 0;i<size;i++){
        itemtemp->display();
        itemtemp++;
    }
    
}


/*#include<bits/stdc++.h>
using namespace std;
class cla{
 public:
    int x;
    void display(){
        cout<< "Class cla is called "<<x<<endl;
    }
};
class clas{
    public:
        int y;
        void display(){
            cout << "Class clas is called " << y << endl;
        }
};
class cl:public cla,public clas{
    public:
        int result;
        void display(){
            //cla::display();
            //clas::display();
            result = x + y;
            cout<<"Class cl is called "<<result<<endl;
        }

};
int main(){
    cl o1;
    cl o2;
    cl *ptrr=&o1;
    ptrr->x = 4;
    ptrr->y = 4;
    ptrr->display();
    //cl o2;
    ptrr = &o2;
    ptrr->x = 10;
    ptrr->y = 100;
    ptrr-> display();
}*/


//! FRIEND FUNCTION //
/*#include<iostream>
using namespace std;

// 1 + 4i
// 5 + 8i
// -------
// 6 + 12i 
class Complex{
    int a, b;
    friend Complex sumComplex(Complex o1, Complex o2);
    public:
        void setNumber(int n1, int n2){
            a = n1;
            b = n2;
        }

        // Below line means that non member - sumComplex funtion is allowed to do anything with my private parts (members)
        void printNumber(){
            cout<<"Your number is "<<a<<" + "<<b<<"i"<<endl;
        }
};

Complex sumComplex(Complex o1, Complex o2){
    Complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));

    return o3;
}

int main(){
    Complex c1, c2, sum;
    c1.setNumber(1, 4);
    c1.printNumber();

    c2.setNumber(5, 8);
    c2.printNumber();

    sum = sumComplex(c1, c2);
    sum.printNumber();

    return 0;
}*/

/* Properties of friend functions
1. Not in the scope of class
2. since it is not in the scope of the class, it cannot be called from the object of that class. c1.sumComplex() == Invalid
3. Can be invoked without the help of any object
4. Usually contans the objects as arguments
5. Can be declared inside public or private section of the class
6. It cannot access the members directly by their names and need object_name.member_name to access any member.

*/

//!FRIEND CLASS//
/*#include <iostream>
using namespace std;

// Forward declaration
class Complex;

class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }

    int sumRealComplex(Complex, Complex);
    int sumCompComplex(Complex, Complex);
};

class Complex
{
    int a, b;
    // Individually declaring functions as friends
    // friend int Calculator ::sumRealComplex(Complex, Complex);
    // friend int Calculator ::sumCompComplex(Complex, Complex);

    // Aliter: Declaring the entire calculator class as friend
    friend class Calculator;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

int Calculator ::sumRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int Calculator ::sumCompComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(5, 7);
    Calculator calc;
    int res = calc.sumRealComplex(o1, o2);
    cout << "The sum of real part of o1 and o2 is " << res << endl;
    int resc = calc.sumCompComplex(o1, o2);
    cout << "The sum of complex part of o1 and o2 is " << resc << endl;
    return 0;
}*/
