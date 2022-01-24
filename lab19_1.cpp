#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string file,vector<string> &name,vector<int> &scores,vector<char> &grades){
    ifstream cs;
    cs.open(file);
    string linecheck;
    while(getline(cs,linecheck)){
        int a,b,c,sum=0;
        char g;
        char ns[100];
        const char *text=linecheck.c_str();
        char format[] = "%[^:]: %d %d %d";
        sscanf (text,format,ns,&a,&b,&c);
        sum = a+b+c;
        g = score2grade(sum);
        name.push_back(ns);
        scores.push_back(sum);
        grades.push_back(g);
        
    }

}

void getCommand(string &cmd,string &k){
    string ip;
    string x ="NAME";
    string y ="GRADE";
    string z ="EXIT";
    string f;
    cout << "Please input your command: ";
    getline(cin,ip);
    f = toUpperStr(ip);
    if(f.find(x)==0){
        cmd = ip.substr(0,4);
        k=ip.erase(0,5);
    }else if(f.find(y)==0){
        cmd = ip.substr(0,5);
        k=ip.erase(0,6);
    }else if(f.find(z)==0){
        cmd = ip;
    }else cmd = ip;
  
}

void searchName(vector<string> names, vector<int> scores,vector<char> grades,string k){
    int si = names.size();
    for(int i=0;i<si;i++){
    string a=toUpperStr(names[i]);
        if (a==k){
            cout << "---------------------------------"<<endl;
            cout << names[i]<<"'s score = ";
            cout << scores[i]<<endl;
            cout << names[i]<<"'s grade = ";
            cout << grades[i]<<endl;
            cout << "---------------------------------"<<endl;
            return;
        } 
    }
    cout << "---------------------------------"<<endl;
    cout << "Cannot found."<<endl;
    cout << "---------------------------------"<<endl;
}

void searchGrade(vector<string> names, vector<int> scores,vector<char> grades,string k){
    cout << "---------------------------------"<<endl;
    char b=k[0];
    int si = names.size();
    for(int i=0;i<si;i++){
        if (b==grades[i]){
            cout << names[i]<<" ("<<scores[i]<<")"<<endl;
        }

}

    cout << "---------------------------------"<<endl;
}
int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}