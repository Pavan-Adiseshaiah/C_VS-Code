#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main () {
    //---------------------------------------Vectors------------------------------------------------------------//
    /* Why vectors was introduced in C++?
       Because gives advantages of both arrays and lists
       i,e Gives index based access to the element & size changes dynamically!*/

    vector <int> a;
    vector <int> v {0, 1, 2, 3, 4};
    // vector <int> vec (3, 10);       // ==> [10, 10, 10]

    a.push_back(0);
    for (int i=1; i<10; i++)
        a.push_back(i);

    //for (vector<int>:: iterator it = a.begin(); it < a.end(); it++)   {
    for (auto it = a.begin(); it < a.end(); it++)   {
        cout << *it << endl;                    //Element
        cout << &it << endl;                    //Address of it
        cout << &(*it) << endl;                 //Address of the element
        cout << typeid(it).name() <<endl;
    }
    
    cout<< "Size: " << a.size() << endl;
    cout << "Maxsize: " << a.max_size() << endl;
    cout << "Capacity: " << a.capacity() << endl;
    cout << "Front: " << a.front() << endl;
    cout << "Back: " << a.back() << endl;
    cout << "Array style: " << a[0] << endl;
    cout << "Element at (5): " << a.at(5) << endl;
    a.insert (a.begin() + 5, 88);
    cout << "Element at (5): " << a.at(5) << endl;
    for (int i : a)
        cout << i << endl;
    a.erase (a.begin() + 5);
    cout << "Element at (5): " << a.at(5) << endl;
    for (int i : a)
        cout << i << endl;
    a.pop_back();                           //Last element removed
    for (int i : a)
        cout << i << endl;
    a.resize(5);
    cout << "Size: " << a.size() << endl;
    a.clear();
    cout << "Size: " << a.size() << endl;       //Size=0
    cout << (a.empty() ? "True" : "False") << endl;

    vector<int> b;

    b.push_back(0);
    //b.push_back(1);
    cout << "b: " << b[0] << endl;
    b[0]++;
    cout << "b: " << b[0] << endl;
    /*
    Don't do this before initializing --> Seg fault!!, use push_back()
    b[1] = 1;
    cout << "b[1]: " << b[1] << endl;
    */
    cout << sizeof(b) << endl;
    cout << typeid(b).name() << endl;
    cout << sizeof(int) << endl;
    cout << sizeof (vector<int>) << endl;
    printf ("Printf sizeof vector: %d\n", sizeof(vector<int>));
    for (int i : b)
        cout << i << endl;
    cout << "Size: " << b.size() << endl;
    cout << "Capacity: " << b.capacity() << endl;

    vector<int> c = {10, 20, 30};
    for (int j : c)
        cout << j << endl;
    
    int n = 5;
    vector<int> d (n, 10);          //'n' elements initialized with 10
    for (int i : d)
        cout << i << endl;
    
    d.emplace(d.begin(), 5);        //5 inserted at the beginning.
    cout << "After Emplace" << endl;
    for (int i : d)
        cout << i << endl;
    cout << "Size: " << d.size() <<endl;
    int *p;
    cout << "Sizeof vector: " << sizeof (vector<int>) << endl;      //3ptrs = _M_start, _M_finish, _M_end_of_storage (8*3 = 24)
    cout << "Sizeof pointer: " << sizeof (p) << endl;

    vector<int> vec(5,0);

    cout << "Using iterator" << endl;
    for (vector<int> :: iterator z = vec.begin(); z < vec.end(); z++)
        cout << *z << endl;

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *head;
    ListNode *traverse = head;
    ListNode *temp;

    while (traverse)    {
        if (traverse->val == traverse->next->val)   {
            temp = traverse->next;
            traverse->next = temp->next;
            delete (temp);
        }
        traverse = traverse->next;
    }

    vector<int> vkt = {4, 2, 1, 3, 0};
    
    sort(vkt.begin(), vkt.end());
    cout << "Vkt: ";
    for (int q=0; q<vkt.size(); q++)    {
        cout << q << " ";
    }
    cout << endl;

    // vkt.pop_back();
    vkt.erase(vkt.begin()+vkt.size()-1);
    cout << "After Pop: ";
    for (int q=0; q<vkt.size(); q++)    {
        cout << q << " ";
    }
    cout << endl;

    string s = "a";

    cout << s.length() << " " << s.size() << endl;

    vector<string> ss = {"d", "bc", "cd"};

    sort(ss.begin(), ss.end());

    for (auto i : ss)   {
        cout << i << " ";
    }

    cout << endl;
    for (int q=0; q<vkt.size(); q++)    {
        cout << vkt[q] << " ";
    }
    cout << endl;

    reverse(vkt.begin(), vkt.end());

    for (int q=0; q<vkt.size(); q++)    {
        cout << vkt[q] << " ";
    }
    cout << endl;

}
