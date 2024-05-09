#include <iostream>

using namespace std;        //namespace defines the scope. :: --> scope resolution operator

int main()  {

    //----------------------------printf, scanf, character specifiers.--------------------------------------------//
    bool t_f = true;
    char c = 'a';           // unsigned char, signed char
    int i = 10;             // unsigned, signed, short(u/s), long
    float f = 1.5;
    double d = 5.5;
    short s = 2;
    long l = 4;
    int *p_i;                 //Pointer
    p_i = &i;
    int val = 20;
    int &r = val;           //Reference variable --> No reference in C 

    printf("char: %c\tint: %d\tfloat: %f\tdouble: %lf\n", c, i, f, d);
    cout << sizeof(c) << "\t" << sizeof(i) << "\t" << sizeof(f) << "\t" << sizeof(d) << endl;
    printf("float: %2.3f\tdouble: %4.5lf\n", f, d);
    printf("short: %hd\tlong: %ld\n", s, l);    // unsigned = u (lu)
    cout << "Bool: " << t_f << endl             // 1 or 0 will be printed
         << "Bool size: " << sizeof(bool) << endl;
    printf("i address: %p\tPointer address: %p\n\n", &i, p_i);

    cout << "Enter values\n";
    cout << "Enter <char> <decimal> <float> <double>" << endl;
    scanf("%c %d %f %lf*c", &c, &i, &f, &d); //*c --> will ignore enter at the end
    printf("\nchar: %c\tint: %d\tfloat: %f\tdouble: %lf\n", c, i, f, d);

    
    char *buf;
    scanf ("%s", buf);
    printf ("Buffer: %d\n", sizeof (buf));


    //-----------------------------------Post-increment, Pre-increment------------------------------------------//
    int count = 5;

    printf("%d\n", count++); // post-inc. 5 printed
    printf("%d\n", count);   // 6 printed
    printf("%d\n", ++count); // pre-inc. 7 printed

    //-------------------------------------Operators Priority---------------------------------------------------//
    /*
    1) Arithmetic operators (+, -, *, /, %)     <'%' only works on ints>
    2) Relational operators (>, <, >=, <=, ==, !=)
    3) Logical Operators (!, &&, ||)
    4) Bit-wise Operators (~, &, |, ^)
    */

    //-------------------------------------Swapping 2 nos------------------------------------------------------//
    int a = 20, b = 10;

    a = a + b; // a=30
    b = a - b; // b=20
    a = a - b; // a=10

    //-------------------------------------Switch case--------------------------------------------------------//

    int num1, num2;
    char op;
    
    fflush(stdin);
    cout << "Calculator" << endl;
    cout << "Enter <num1> <op> <num2>" << endl;
    cin >> num1 >> op >> num2;

    switch (op) {
        case '+':   cout << num1 + num2 << endl;
                    break;
        case '-':   cout << num1 - num2 << endl;
                    break;
        case '*':   cout << num1 * num2 << endl;
                    break;
        case '/':   cout << num1 / num2 << endl;
                    break;
        case '%':   cout << num1 % num2 << endl;
                    break;
        default:    cout << "Enter correct values!" << endl;
    }

    // cout << typeid(num1).name() << endl;

    bool t;
    t = int(num1) == num1;
    cout << "Bool value = " << t << endl;

    // numbers between 100 & 500 that are divisible by 3 & 5
    for (int i = 100; i < 501; i++) {
        if (i % 3 == 0 & i % 5 == 0)
            cout << i << "\t";
    }
    cout << endl;

    // print number of digits in the given num, reverse a num
    int num, temp, rev_num = 0, digits = 0;

    cout << "Enter a num" << endl;
    cin >> num;

    while (num) {
        rev_num *= 10;
        temp = num % 10;
        rev_num += temp;
        num /= 10;
        digits++;
    }
    printf("Number of digits = %d\n", digits);
    cout << "Reversed num = " << rev_num << endl;

    // do-while
    i = 5;
    do  {
        cout << i << "\t";
        i++;
    } while (i < 3);
    cout << endl;

    //------------------------------Pointers & References----------------------------------------------//
    //Reference variables must be initialized. Can't change the reference after that.
    //References are not an objects! ==> No memory address of references. References = Alias

    int var = 10;
    int *p = &var;
    int &ref = var;


    cout << "Var: " << var << " " << "Pointer: " << *p << " " << "var addr: " << p << " " 
         << "Ref: " << ref << " " << "&ref: " << &ref << endl;  //&ref = p => addr of var
    
    int x = 10, u = 20;
    int *pt = &x, *pu = &u;
    int v = 10, w = 20;
    int &rv = v, &rw = w;

    printf ("x = %d\tu = %d\tpt = %p\tpu = %p\n", x, u, pt, pu);
    cout << "v = " << v << " " << "w = " << w << " " << "rv = " << rv << " " << "rw = " << rw << " "
         << "&rv = " << &rv << " " << "&rw = " <<&rw << endl;
    
    pt = pu;
    rv = rw;

    //int k; &rv = k;         //Can't change rv to reference to a different variable.

    int *px = &rv;

    printf ("px = %p\t&rv = %p\t*px = %d\trv = %d\n", px, &rv, *px, rv);

    cout << "After assignment" << endl;
    printf ("x = %d\tu = %d\tpt = %p\tpu = %p\n", x, u, pt, pu);
    printf ("&v: %p\t &w: %p\n", &v, &w);
    cout << "v = " << v << " " << "w = " << w << " " << "rv = " << rv << " " << "rw = " << rw << " "
         << "&rv = " << &rv << " " << "&rw = " <<&rw << " " << "&v: " << &v << " " << "&w: " << &w << endl; // v = w = 20; rv & rw still referencing to v & w.

    const int c_i = 5;
    const int &c_r = c_i;           //Type must match. Pointing to a constant variable / object. Pointer isn't constant.
    //c_r = 3;                      //error
    int i_c = 1;
    int * const p_c_i = &i_c;       //Pointer is "Constant" => can't point to other object. Pointing object isn't constant.
    *p_c_i = 9;
    // p_c_i = &c_i;                //Error
    const int * const c_p_c_i = &c_i;   //Const pointer pointing to a const object


    cout << c_i << " " << c_r << endl;

    double tol = 1e-6;
    double &tol_ref = tol;
    double *tol_ptr = &tol;         

    cout << tol << endl;
    tol_ref = 1e-2;
    cout << tol << endl; 
    cout << *tol_ptr << endl;
    *tol_ptr = 0.0;
    cout << tol_ref << endl;

    //Dynamic Memory allocation
    int *p_a = new int (1000);              // 1 int space; initialized to 1000
    cout << *p_a << endl;
    delete p_a;

    int *p_b = new int [5]{0, 1, 2, 3, 4};  // 5 ints and initialized
    cout << p_b[3] << endl;
    delete [] p_b;
    int a2 = 1;
    int *p2 = &a2;

    cout << *p2 <<endl;
    cin.ignore();

    string str;
    getline(cin, str);

    cout << str << endl;

}