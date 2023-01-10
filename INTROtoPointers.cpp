#include <iostream>
using namespace std;

int main()
{

    /*  int num  = 5 ;

     cout << num << endl;
     // address of operator = &

     cout<<"address of num is " << &num << endl;

 int *p1=&num;
 cout<< "value is : " << *p1 << endl;
 cout<< "value is : " << p1 << endl;
 double d=4.3;
 double *p2 =&d;
 cout<< "value is : " << *p2 << endl;
 cout<< "value is : " << p2 << endl;

 cout<<" size of integer is " << sizeof(num)<<endl;
 cout<<" size of pointer is " << sizeof(p1)<<endl;
 cout<<" size of int is" << sizeof(p2)<<endl;

 // char ch='a';
 // char *p3 =&ch;
 // cout<< "value is : " << *p3 << endl;
 // cout<< "value is : " << p3< endl;
  */
    /*
        // Pointer to it is created and pointing to some garbage address
        //  int *p;
        //  cout<< *p<< endl; (Bad Practice )
        int i = 5;
        // int *p = &i;
        int *p = 0;
        p = &i;
        cout << *p << endl;
        cout << p << endl;

        int *q = &i;
        cout << *q << endl;
        cout << q << endl; */

    /* int num=5;
    int a=num;
    a++;
    cout<< num<< endl;
    cout<< a<< endl; */

    /* int  newnum=6;njj
    int *p=&newnum;
    int b=*p;
    b++;
    cout<<  newnum<< endl;
    cout<< b<< endl;
    cout<<*p << endl;
    cout<< p<< endl; */
    /*
        int num = 5;
        int a = num;
        a++;
        cout << num << endl;
        int *p = &num;
        cout << "Before" << num << endl;

        (*p)++;
        cout << "After" << num << endl; */
    /*
    // Copy one pointer to another
    int *newpointerQ=p;
    cout<< p<< "--" << newpointerQ << endl;
    cout<< *p<< "----" << *newpointerQ << endl; */

    // Important Concepts

    int i = 3;
    int *t = &i;
    // cout<< (*t)++ << endl;

    *t = *t + 1;

    cout << (*t) << endl;

    // t=t +1 ; this will become 104 not 101.  (It will go in next integer)

    cout << "Before  t" << t << endl;
    t = t + 1;
    cout << "After t" << t << endl;

    /*
        cout<< endl;
        cout<< endl;
        cout<< endl;
        int j=5;
         int *tnew=&j;
        cout<<*tnew++ << endl;
         */
    
        

    return 0;
}
