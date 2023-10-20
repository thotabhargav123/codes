/**
    * ? SINGLE INHERTIANCE
*/
/*#include<bits/stdc++.h>
using namespace std;
 
class powar{
    int base;
    int exponent;
    public:
        void setdata( int b){
            base = 10;
            exponent = b;
        }
    int getbase(){
         return base;
    }
int getexponent(){
    return exponent;
}
};
class calc : public powar{
     int result;
      public:
      void   calcu(){
             result =pow(getbase(),getexponent());
         }
        void display(){
            cout << "the base is " << getbase() << " the exponent is " << getexponent() << " and the result is " << result << endl;
        }
};
int main(){
    calc o1;
    int x, y;
    cin>>x>>y;
    o1.setdata(x,y);
    o1.calcu();
    o1.display();
}*/

/** 
 * ! INHERTIANCE TABLE 
                              *! public derivation           protected derivation         private derivation
  *@param Private_members         Not inherited                  Not inherited                Not inherited 
  *@param public_members          Public                         protected                    private
  *@param protected_members       Protected                      protected                    private
*/

// ? *******MULTI-LEVEL INHERITANCE*******//

/*#include<bits/stdc++.h>
using namespace std;
class student{
       protected:
           int rollno;
           public:
             void setrollno(int r){
                 rollno = r;
             }
        void getrollno(){
            cout<<"the rollno is "<<rollno<<endl;
            //void givehouse();
            //void display();
        }
};
class house:public student{
    protected:
        string colourcode;
        public:
         void givehouse(){
             if(rollno%4==0){
                 colourcode = "Green";
             }
             else if(rollno%4==1){
                 colourcode = "Red";
             }
             else if(rollno%4==2){
                 colourcode = "Yellow";
             }
             else if(rollno%4==3){
                 colourcode = "Blue";
             }
         }
    void display(){
        student::getrollno();
         givehouse();
        cout<<"The house in which u are present is "<<colourcode<<endl;
    }
};
class club: public house{
       
};
int main(){
    house o1;
    o1.setrollno(8);
    o1.display();
}*/




// *******------>>>> MULTIPLE INHERITANCE******//


/*#include <bits/stdc++.h>
using namespace std;
class student{
    private: 
       string name;
       int phonenumber;
   protected:
       int id;
  public:
      void getid(int n,string s,int p)
      {
          id=n;
          name=s;
          phonenumber=p;
      }
    void setid(){
        cout<<"your name is "<<name<<endl;
        //cout<<"Your ID is "<<id<<endl;
        cout<<"your cell number is "<<phonenumber<<endl;
    }
};
class marks{
    double maximum=50;
    protected:        
        double maths;
        double physics;
        double chemistry;
        public:
          void setmarks(double m,double p,double c){
              maths = m;
              physics = p;
              chemistry = c;
                  }
      int getmarks(){
           return maths+physics+chemistry;
      }
    void info(){
        cout << " the max marks of each subject  are " << maximum << endl;
    }
};
class result:public student,public marks{
    protected:
     float abc;
     double total;

public:
   void results()
    {
      cout<<"computing results"<<endl;
      total=  getmarks();
      abc = (getmarks() * 100) / 150;
     }
  void display(){
        //cout<<"your name is "<<name<<endl;
         cout<<"Your ID is "<<id<<endl;
        //cout<<"your cell number is "<<phonenumber<<endl;
         setid();
         info();
         cout << "your individual subject scores are :" << endl;
         cout << "                                        maths :- " << maths << endl;
         cout << "                                        physics :- " << physics << endl;
         cout << "                                        chemistry :- " << chemistry << endl;
         
         results();
         cout<<" your total out of 150 is "<< total<<endl;
         //result();
         cout<<" your percentage is "<<abc<<"%"<<endl;
  }
};
int main(){

    int a, b;
    double c,d,e;
    string f;
    result o1;
    cin >> f;
    cin >> a >> b;
    cin >> c >> d >> e;
    o1.getid(a, f, b);
    o1.setmarks(c, d, e);
    o1.display();
}*/



//!POLYMORPHISM VIRTUAL FUNCTION USAGE ://

#include<bits/stdc++.h>
using namespace std;
class stats{
    protected:
        string title;
        float ratings;
    public:
          stats(string s,float r){
              title = s;
              ratings = r;
          }
        void virtual display(){

        }
};
class video_stats: public stats{
   protected: 
      float video_length;
      bool sub_title;
   public:
          video_stats(string s, float r, float vl, bool cc):stats( s, r){
               
               video_length=vl;
               sub_title = cc;
          }
        void display(){
            cout<<"the title of the video is "<<title<<endl;
            cout << "This video has " << ratings << " out of 10 stars " << endl;
            cout<<"the length of the video is "<<video_length<<" minutes "<<endl;
            if(sub_title=1){
                cout<<"This video has subtitles "<<endl;
            }
            else{
                cout<<" Sorry this video doesnot have subtitles in future we may add to it"<<endl;
            }
        }
};
class blog_stats: public stats{
    protected:
        int words;
        bool transitions;
        int no_of_languages;
    public: 
        blog_stats(string s, float r,int w, bool t,int l):stats(s,r){
            words = w;
            transitions = t;
            no_of_languages = l;
        }
        void display(){
            cout<<"the title of the blog is "<<title<<endl;
            cout << "This blog has " << ratings << " out of 10 stars " << endl;
            cout<<"The no of words in the texted blog "<<words<<" words "<<endl;
            if(transitions=true){
                cout<<"This text blog can be translated to your desire language "<<endl;
                cout<<"No off languages supported are "<<no_of_languages<<endl;
            }
            else{
                cout<<" Sorry this blog cannot translated, in future we may add to it"<<endl;
            }
        }
};
int main(){

    string name;
    bool ss, tr;
    float ra, v;
    int wa, languages;
    cout << "enter name " << endl;
     cin>>name;
     cout << "enter ratings " << endl;
     cin >> ra;
     cout << "enter no of words and video lenght " << endl;
     cin >> wa;
     cin >> v;
     cout<<"no of languages "<<endl;
     cin >> languages;
    cout<<"enter cc and transitions  are present or  not "<<endl;
    cin >> ss;
    cin >> tr;
    video_stats o1 = {name, ra, v, ss};
    blog_stats o2 = {name, ra, wa, tr, languages};
    stats *ptr1;
    stats *ptr2;
    ptr1 = &o1;
    ptr2 = &o2;
    ptr1->display();
    ptr2->display();
}



