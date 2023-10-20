#include<bits/stdc++.h>
using namespace std;
class Sinhasing{
    private:
    int lota;
    list<int> *dabha;
    public:
    Sinhasing(int v);
    void nimpu(int val);
    void kalechey(int loc);
    void chupeybey();
     int secretmasala(int x) {
        return (x % lota);
    }
};
Sinhasing::Sinhasing(int v){
    this->lota = v;
    dabha = new list<int>[lota];
}
 void Sinhasing:: nimpu(int val) {
      int jaga=secretmasala(val);
      dabha[jaga].push_back(val);
 }
 void Sinhasing:: kalechey(int loc){
     int jaga=secretmasala(loc);
     list<int>::iterator munduku_sagu;
     for(munduku_sagu=dabha[jaga].begin(); munduku_sagu!=dabha[jaga].end();munduku_sagu++){
         if(*munduku_sagu==loc){
             break;
         }
     }
     if(munduku_sagu!=dabha[jaga].end()){
         dabha[jaga].erase(munduku_sagu);
     }
 }
 void Sinhasing:: chupeybey(){
     for (int i = 0; i < lota;i++){
         //cout << i;
          list<int>::iterator munduku_sagu;
          for (munduku_sagu = dabha[i].begin(); munduku_sagu != dabha[i].end();munduku_sagu++) {
              cout << "->" << *munduku_sagu;
          }
     }
      cout << endl;
 }
 int main(){
     int b = 7;
     Sinhasing b1(b);
     for (int i = 0; i < 20;i++) {
        b1. nimpu(i);
     }
     b1.chupeybey();
     for (int i = 0; i < 4;i++) {
         b1.kalechey(i * 5);
     }
     b1.chupeybey();
 }