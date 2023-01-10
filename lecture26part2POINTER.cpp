/* #include <iostream>
using namespace std;

int main()
{

    int arr[10] = {2, 6, 5, 10, 7, 8, 9};

    cout << "address of first memory block is" << arr << endl;     //  address of first element
    cout << "address of first memory block is" << &arr[0] << endl; //  address of first element

    cout << arr[0] << endl; // 2
    cout << *arr << endl;   // 2

    cout << *arr + 1 << endl;   // 2 +1 = 3
    cout << (*arr) + 1 << endl; // 2 +1 = 3

    cout << *(arr + 1) << endl; // *(2+1=3 index ) ans 6

    cout << arr[2] << endl;
    cout << *(arr + 2) << endl;

    int i = 3;
    cout << i[arr] << endl;

    return 0;
} */

#include <iostream>
using namespace std;
int main()
{

    /*  int temp[10] = {1, 2};

     cout << sizeof(temp) << endl; // 40bytes

     cout << " 1st " << sizeof(*temp) << endl; //  temp means address @ 0th index , *temp That address value , & the value is of int type so size of int is 4 bytes

     cout << " 2nd " << sizeof(&temp) << endl;  // 8bytes
     //it store address for address  of first index it takes 8 bytes



     int *ptr = &temp[0];
     cout << sizeof(ptr) << endl; // 8 bytes In some it takes 4

     cout << sizeof(*ptr) << endl; // value  23 integer it takes 4 bytes . so answers is 4 bytes

    cout << sizeof(&ptr) << endl;
     // 8 bytes  it store address for address it takes 8 bytes
     // In some it takes 4

     return 0; */
    /*
        int a[20] = {1, 2, 3, 5};

        // All IS SAME
        cout << &a[0] << endl; // address print hoga
        cout << &a << endl;    // address print hoga
        cout << a << endl;     // address print hoga

        int *p = &a[0];
        cout << p << endl;  // address print hoga
        cout << *p << endl; // address print hoga
        cout << &p << endl; // address of p */

    int arr[10];
    //   arr=arr+1;  ERROR

    int *ptr = &arr[0];
    cout << ptr << endl;

    ptr = ptr + 1; // Arr moves by 1 block

    cout << ptr << endl;

    return 0;
}