#include <iostream>
using namespace std;
/*
int main() {

    int arr[5] = {1,2,3,4,5};// integer array
    char ch[6] = "abcde"; // character array



    cout << arr << endl; // address print
    //attention here
    cout << ch << endl; // content print

    char *c = &ch[0];
    //prints entire string
    cout << c << endl;

    char temp = 'z';
    char *p = &temp;

    cout << p << endl;


    return 0;
} */

void print(int *p)
{
    cout << p << endl;  // address print hoga
    cout << *p << endl; // value print hoga
    cout << &p << endl; // value print hoga
}
void update(int *p)
{
    // p=p+1;
    // cout<< "Inside" << p << endl; // New address of p
    *p = *p + 1;
}

/*
int main()
{
    int value = 5;
    int *p = &value;
    // print (p);
    cout << "Before p" << *p << endl; // same address
    // If we change it to *p=*p+1; then its value gonna changes

    update(p);
    cout << "After p" << *p << endl; // same address

    int arr[5] = {1, 2, 3, 4, 5};
    //  int a=getSum(arr);
    cout << "Sum Is: " << getSum(arr, 5);

    return 0;
} */

int getSum(int *arr, int n)
{

    // int getSum(int arr[], int n) Both lines are Same

    cout << endl
         << "Size : " << sizeof(arr) << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        // sum+=i[arr];
    }
    return sum;
}

/*
int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    //  int a=getSum(arr);
    cout << "Sum Is: " << getSum(arr, 5);
    return 0;
} */

int main()
{

    int arr[6] = {1, 2, 3, 4, 5, 8};

    cout << "Sum is " << getSum(arr + 3, 3) << endl;
    // sending part of array to get sum . from index 3
    cout<< endl;
    return 0;
}