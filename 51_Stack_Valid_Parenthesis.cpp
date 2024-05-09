#include <iostream>
#include <stack>
// #include <string>

using namespace std;

// bool isValid(string s)  {
//     stack<char> st;
//     char p;

//     for (char c : s)    {
//         if (c == '(' || c == '[' || c == '{')   {
//             st.push(c);
//         }
//         else if (c == ')')  {
//             p = st.empty() ? '0' : st.top();
//             st.pop();

//             if (p == '0')   {
//                 return false;
//             }
//             else if (p != '(')  {
//                 return false;
//             }
//         }
//         else if (c == ']')  {
//             p = st.empty() ? '0' : st.top();
//             st.pop();

//             if (p == '0')   {
//                 return false;
//             }
//             else if (p != '[')  {
//                 return false;
//             }
//         }
//         else if (c == '}')  {
//             p = st.empty() ? '0' : st.top();
//             st.pop();

//             if (p == '0')   {
//                 return false;
//             }
//             else if (p != '{')  {
//                 return false;
//             }
//         }
//         else    {
//             return false;
//         }
//     }

//     return st.empty();
// }

bool isValid(string s) {
    stack<char> st;

    for (char c : s)    {
        switch (c)  {
            case '(': case '[': case '{':
                st.push(c);
                break;
            case ')':
                if (st.empty()) {
                    return false;
                }
                if (st.top() != '(')    {
                    return false;
                }
                st.pop();
                break;
            case ']':
                if (st.empty()) {
                    return false;
                }
                if (st.top() != '[')    {
                    return false;
                }
                st.pop();
                break;
            case '}':
                if (st.empty()) {
                    return false;
                }
                if (st.top() != '{')    {
                    return false;
                }
                st.pop();
                break;
            default: ;
        }
    }

    if (!st.empty())    {
        return false;
    }

    return true;
}

int main () {
    string str = "()[]{}";

    bool ret = isValid(str);

    if (ret)   {
        cout << "Valid" << endl;
    }
    else    {
        cout << "Invalid" << endl;
    }

    return (EXIT_SUCCESS);
}


// #include <iostream>
// #include <vector>

// using namespace std;

// class Stack {
//     int sp = -1;
//     char *stack;
//     int maxsize;

//     public:
//     Stack(int size)   {
//         if (size < 1)   {
//             throw "Size must be greater than 0";
//         }

//         maxsize = size;
//         stack = new char[maxsize];

//     }

//     bool push (char c)  {
//         if (sp == maxsize - 1)  {
//             return false;
//         }
//         else{
//             stack[++sp] = c;
//             return true;
//         }
//     }

//     char pop () {
//         if (sp == -1)   {
//             return false;
//         }
//         else    {
//             return stack[sp--];
//         }
//     }
// };

// bool valid_parantheses (string &par) {
//     Stack stack(par.length());
//     char p;
//     int count = 0;

//     for (char c : par)  {
//         switch (c)  {
//             case '(' : case '[' : case '{' :
//                 stack.push(c);
//                 count++;
//                 break;
//             case ')':
//                 p = stack.pop();
//                 if (p != '(')   {
//                     return false;
//                 }
//                 else    {
//                     count--;
//                 }
//                 break;
//             case ']':
//                 p = stack.pop();
//                 if (p != '[')   {
//                     return false;
//                 }
//                 else    {
//                     count--;
//                 }
//                 break;
//             case '}':
//                 p = stack.pop();
//                 if (p != '{')   {
//                     return false;
//                 }
//                 else    {
//                     count--;
//                 }
//                 break;
//             default:
//                 break;
//         }
//     }

//     if (count) {
//         return false;
//     }
//     else    {
//         return true;
//     }
// }

// int main () {
//     // string par = "()[]{}";
//     string par = "(]";

//     bool val = valid_parantheses(par);

//     if (val)    {
//         cout << "Valid Parantheses" << endl;
//     }
//     else    {
//         cout << "Invalid Paranthesis" << endl;
//     }

//     return (EXIT_SUCCESS);
// }