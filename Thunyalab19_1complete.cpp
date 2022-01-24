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

void importDataFromFile(string a,vector<string> &b,vector<int> &c,vector<char> &d){
    string text;
    char OP [] = "%[^:]: %d %d %d";
    ifstream source;
    source.open(a);

    char n1[100];
    int S1,S2,S3;
    while(getline(source,text)){
        const char *A=text.c_str();
        sscanf(A,OP,n1,&S1,&S2,&S3);
        b.push_back(string(n1));
        c.push_back(int(S1+S2+S3));
        d.push_back(score2grade(int(S1+S2+S3)));
    }
}

void getCommand(string &e,string &f){
    string text1;
    char com[100],ke[100];
    char OP[] = "%s %[^\n]";
    cout << "Please input your command: ";
    getline(cin,text1);
    const char *text11 = text1.c_str();
    sscanf(text11,OP,com,ke);
    e = com;
    f = ke;
}

void searchName(vector<string> g ,vector<int> h,vector<char> i,string j){
    int m = 0;
    cout << "---------------------------------" << "\n";
    for(int n = 0; n  < int(g.size()) ; n++){
        if (toUpperStr(g.at(n)).compare(toUpperStr(j)) == 0){
        cout << g.at(n) << "'s score = " << h.at(n) << "\n";  
        cout << g.at(n) << "'s grade = " << i.at(n) << "\n";
        }
        else m++;
    }
    if(m == 26) cout << "Cannot found." << "\n";
    cout << "---------------------------------" << "\n";
}

void searchGrade(vector<string> o ,vector<int> p,vector<char> q,string r){
    cout << "---------------------------------" << "\n";
    for(int s = 0; s  < int(o.size()) ; s++)
        if (q.at(s) == (r[0])){
           cout << o.at(s) << " (" << p.at(s) << ")" << "\n";
        }
    cout << "---------------------------------" << "\n";
}


int main(){
    string filename = "D:\\Thunyalab19\\lab19_2564_2-master\\name_score.txt";
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