#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<unordered_map>

using namespace std;

int main(){
    fstream newfile;
    string row;
    vector<int> score;
    vector<string> word;
    unordered_map<string,int> umap;
    //reading score
    newfile.open("score.csv");
    while(getline(newfile,row)){
        score.push_back(stoi(row));
    }
    newfile.close();

    //reading words
    newfile.open("words.csv");
    while(getline(newfile,row)){
        word.push_back(row);
    }
    newfile.close();
    
    //creating hash table for words and score
    for(int i=0;i<score.size();i++){
     umap[word[i]]=score[i];
    }

    //getting input and seperating words
    string input;
    getline(cin,input);
    vector<string> user_data;

    string split="";
    for(int i=0;i<input.length()+1;i++){
        char x=input[i];
        if(x ==' '|| x=='\0'){
           // cout<<split;
            user_data.push_back(split);
            split="";
        }
        else{
            split=split+x;
        }
    }

    //getting score
    int final_score=0;
    for(int i=0;i<user_data.size();i++){
        auto ans=umap.find(user_data[i]);
        if(ans!=umap.end()){
            final_score=final_score+ans->second;
        }
        
    }
    float comp=float(float(final_score)/float(user_data.size()));
    cout<<"final score is: "<<final_score<<" comparitive: "<<comp<<endl;
    if(comp>0)
        cout<<"happy";
    else
        cout<<"sad";

}