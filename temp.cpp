#include<iostream>
#include<list>
#include<set>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;

int main () {
    set <int> a;

    list<int> b;

    a.insert(1);
    a.insert(2);
    a.insert(1);

    for (auto i : a)    {
        cout << i << endl;
    }

    unordered_map<int, int> mp {{1, 2}, {2, 3}};

    for (auto i : mp)   {
        cout << i.first << " ";
    }

    queue<int> q;

    q.push(1);
    q.push(1);
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.size() << endl;

    while (q.front() < 2)   {
        cout << "inside while" << endl;
        cout << "Front: " << q.front() << endl;
        q.pop();
    }

    cout << q.size() << endl;


    struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *head, *tail;
    head = new ListNode (5, nullptr);

    cout << head->val << " " << head->next << endl;

    unordered_map<int, int> mp {{1, 5}, {2, 10}};

    cout << mp[1] << endl;

    int i = 10;
    cout << ~i << endl;

    string s = "abc";
    // string s{5+'a'};
    cout << s << s.length() << endl;

    return 0;

}