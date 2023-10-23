#include<bits/stdc++.h>
using namespace std;
int smallestSubstring(string s) {
        // Code here
        int ans=INT_MAX;
        bool z=false,o=false,t=false;
        int zc=0,oc=0,tc=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                z=true;
                zc=i;
            }
            else if(s[i]=='1'){
                o=true;
                oc=i;
            }
            else if(s[i]=='2'){
                t=true;
                tc=i;
            }
            if(z and o and t){
                ans=min(ans,max({zc,oc,tc})-min({zc,oc,tc}));
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans+1;
        }
    }