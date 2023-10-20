
//!{FILES HANDLING}.
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    ifstream get("sample.txt"); //*{read the text file}
    getline(get, s);
    cout<<s;
    string p = "bhargav";
    ofstream out("sample.txt");//*{over write or write the text file}
    out<<p;
}*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string p;
    ifstream get("sample.txt"); //*{read the text file}
    getline(get, p);
    cout<<p<<endl;
     ofstream write("sample.txt");
     string s;
     cout<<"enter your name "<<endl;
     getline(cin, s);
     write<<"The Tale of Naruto Uzumaki Written by "<<s<<endl;
     write.close();
     ifstream read("sample.txt");
     string r;
     getline(read, r);
     cout<<r<<endl;
     
}
//?{FILES HANDLING ENDED}


//!{EXCEPTIONS STARTED}

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    int n;
    cin >> n;
    cout<<"your Number going through safety check \n"<<endl;
    try{
        cout << "Verification STARTED \n";
        if(k<=0){
            throw k;
        }
        cout << k + 1;
    }
    catch(int k){
        cout<<"Verification completed and error found "<<endl;
    }
}*/ 

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    double b, p;
    cin >> b >> p;
    cout<<"numbers are going through Verification "<<endl;
    try{
        cout<< "Verification started "<<endl;
       if(p<=0 || p-int(p)!=0){
           throw p;
       }
       cout << pow(b, p);
    }
    catch( double p ){
        cout<<"verification failed and p is negative "<<endl;
    }
    catch(...){
        cout<<"string or decimal is entered "<<endl;
    }
}*/
/*#include <iostream>
using namespace std;
 
int main()
{
    try  {
        throw 'a';
        throw 100;
       
    }
    catch (int )  {
        cout << "Caught ";
    }
    catch (char)  {
        cout << "caught char";
    }
    return 0;
}*/
