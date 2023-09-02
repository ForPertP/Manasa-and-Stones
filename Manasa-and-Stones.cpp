#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'stones' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER a
 *  3. INTEGER b
 */

vector<int> stones(int n, int a, int b)
{
    vector<int> result;
    
    for (int i = 0, j = n-1; i < n && j >= 0; ++i, --j)
    {   
        int item = a*i + b*j;
        result.push_back(item);          
    }
    
    std::sort(result.begin(), result.end());
    auto it = std::unique(result.begin(), result.end());
    result.erase(it, result.end());
    
    return result;
}


vector<int> stones1(int n, int a, int b)
{
    vector<int> result;
    
    for (int i = 0, j = n-1; i < n && j >= 0; ++i, --j)
    {   
        int item = a*i + b*j;
        result.emplace_back(item);          
    }
    
    std::sort(result.begin(), result.end());
    auto it = std::unique(result.begin(), result.end());
    result.resize(std::distance(result.begin(), it));
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string a_temp;
        getline(cin, a_temp);

        int a = stoi(ltrim(rtrim(a_temp)));

        string b_temp;
        getline(cin, b_temp);

        int b = stoi(ltrim(rtrim(b_temp)));

        vector<int> result = stones(n, a, b);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
