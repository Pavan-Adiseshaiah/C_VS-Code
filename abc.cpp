#include <iostream>

using namespace std;
int sameSubstring(string s, string t, int K) {
    int cost = 0, sub = 0;
    bool sub_str = true;
    
    for (auto i=0; i<s.length(); i++)    {
        if (s[i] != t[i] || !sub_str)   {
            if (abs (s[i] - t[i]) <= K)  {
                //cout << abs (s[i] - t[i]) <<endl;
                cost += abs (s[i] - t[i]);
                K = K - abs (s[i] - t[i]);
                s[i] = t[i];
                // cout << s << endl;
                // cout << cost << "\t" << K << endl;
                sub++;
                sub_str = false;
            }
            else if (!sub_str)
                break;
        }
    }
    return sub;
}

int main () {
    // cout << sameSubstring ("adpgki", "cdmxki", 6);
    int s = 100u;
    unsigned int a = 1;
    cout << a << endl;
    cout << s << endl;


}