#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& w1, string& w2){
            return (w1.length() <= w2.length());
        });
        
        vector<string> ret;
        unordered_set<string> m;
        
        for(string w : words) {
            vector<bool> dp(w.length()+1, false);
            dp[0] = true;
            for(int i = 0; i < w.length(); i++) {
                for(int j = i; j >= 0; j--) {
                    string s = w.substr(j, i-j+1); // O(length) operation
                    if(dp[j] && m.find(s) != m.end()) {
                        dp[i+1] = true;
                        break;
                    }
                }
            }
            
            if(dp[w.length()])
                ret.push_back(w);
            
            m.insert(w);
        }
        
        return ret;
    }
};

int main ()
{

//testcases 

int t;
cin>>t;

while (t--)
{


    Solution ob;
    vector<string> words;

    fstream file;

    string word ,t,q,filename;

// enter the file name 

    cin>>filename;

    file.open(filename.c_str());

    while (file >> word)
    {
        words.push_back(word);
        /* code */
    }
    

    vector<string>concatedwords;
    concatedwords =  ob.findAllConcatenatedWordsInADict(words);
    int ln = concatedwords.size();
    cout<<"Longest Compound Word: "<< concatedwords[ln-1]<<endl;;
    cout<<"Second Longest Compound Word: " <<concatedwords[ln-2]<<endl;

}

}
