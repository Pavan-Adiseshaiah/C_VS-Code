#include <iostream>
#include <sstream>
// #include <string>
// #include <cstring>

using namespace std;

int substring(string &haystack, string &needle) {

    // --------------------------------------without header files--------------------------------------------------
    // if (haystack.length() < needle.length())
    //     return -1;
    
    // for (int i=0; i<=haystack.size() - needle.size(); i++)   {
    //     int j;
    //     for (j=0; j<needle.size(); j++) {
    //         if (haystack[i+j] != needle[j]) {
    //             break;
    //         }
    //     }

    // if (j == needle.size()) {
    //         return i;
    //     }
    // }
    // return -1;

    // ---------------------------------------<cpp>------------------------------------------------------
    if (haystack.length() < needle.length())
        return -1;

    for (int i=0; i<=haystack.length() - needle.length(); i++)  {
        if (haystack.substr(i, needle.length()) == needle)            // .substr gives substring b/w [i, l]; compare this with needle
            return i;
    }

    return -1;

    //------------------------------------------- C-Style --------------------------------------------------
    // if (haystack.length() < needle.length())
    //     return -1;

    // for (int i=0; i<=haystack.length() - needle.length(); i++)  {
    //     if (!strncmp(&haystack[i], &needle[0], needle.length()))   {
    //         return i;
    //     }
    // }

    // return -1;
}

// int main () {
//     char str[20] = "hello";                     // array of chars
//     short s = 5;
//     // cout << "Strlen: " << strlen(str)<<endl;                        //5  --> C-style
//     cout << "Size: " << sizeof(str) / sizeof (char)<< endl;         //20

//     printf ("Unsigned: %d\n", s);                                   //5

//     char k[20] = "hello";

//     cout << size(k) <<endl;                                                //20

//     string st = "abcde";
//     if (st == "abcde")
//         cout << "equal\n";
//     cout << st << endl;

//     string haystack = "mississippi";
//     string needle = "issip";

//     cout << substring(haystack, needle) << endl;
//     cout << needle[2] << endl;

//     string jkl(needle.length(), '0');

//     cout << jkl.length() << " " << jkl << endl;

//     cout << "needle: " << needle << endl;
//     needle.append("needle");
//     cout << "append: " << needle << endl;
//     char abc[20] = "harry";
//     string s_t = "harry";
//     needle.assign(s_t);         // needle = harry
//     string t_s = "potter";      
//     needle = t_s;               // Similarly, needle = abc

//     cout << "needle: " << needle << endl;
//     cout << "abc: " << t_s << endl;
//     // needle.clear();
//     // cout << needle << needle.size() << endl;              // Empty. Size = 0
//     // cout << needle.back() << endl;                       // r
//     // cout << needle.compare(t_s) << endl;                // 0
    
//     exit (EXIT_SUCCESS);
// }

//-----------------------------------------Add Binary----------------------------------------------------------
string addBinary(string a, string b) {
    string result;
    int carry = 0;

    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';                                  // carry + a[i]
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';                                  // b[i] + sum (carry + a[i])
            j--;
        }

        carry = sum / 2;
        result.insert(result.begin(), '0' + sum % 2);               // => right shift and add MSB 
    }

    return result;
}

int main() {
    // string a1 = "11";
    // string b1 = "1";
    // string result1 = addBinary(a1, b1);
    // cout << "Output : " << result1 << endl;

    // string a2 = "1010";
    // string b2 = "1011";
    // string result2 = addBinary(a2, b2);
    // cout << "Output: " << result2 << endl;

    // string a = "01";
    // int x = a[0];
    // cout << a[1] << " " << x << endl;

    // string klj;
    // klj = "abc";
    // cout << klj << endl;

    // ------------------------------------------------- sstream -------------------------------------------------------//

    istringstream iss ("Hello world");
    string word;

    while (iss >> word) {
        cout << word << endl;
    }
    
    return 0;
}
