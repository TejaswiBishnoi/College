#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> roots;

int FindRoot(int a){
    if(roots[a] == a) return a;
    return FindRoot(roots[a]);
}

vector<int> componentsInGraph(vector<vector<int>> gb) {
    int n = gb.size();
    vector<int> len;
    
    for (int i = 0; i < 2*n + 1; i++){
        roots.push_back(i);
        len.push_back(1);
    }
    
    for(int i = 0; i < n; i++){
        int o = FindRoot(gb[i][0]);
        int t = FindRoot(gb[i][1]);
        
        if (o != t){
            roots[t] = o;
            len[o] += len[t];
            len[t] = 0;
        }
    }
    
    int Min = 2*n + 1;
    int Max = 0;
    for (auto it = len.begin(); it != len.end(); it++){
        if (*it > 1 && *it < Min) Min = *it;
        if (*it > Max) Max = *it;
    }
     vector<int> a;
    a.push_back(Min); a.push_back(Max);
    
   
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> gb(n);

    for (int i = 0; i < n; i++) {
        gb[i].resize(2);

        string gb_row_temp_temp;
        getline(cin, gb_row_temp_temp);

        vector<string> gb_row_temp = split(rtrim(gb_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int gb_row_item = stoi(gb_row_temp[j]);

            gb[i][j] = gb_row_item;
        }
    }

    vector<int> result = componentsInGraph(gb);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
