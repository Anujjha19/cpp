#include <iostream>
using namespace std;

/* int main(){

int i=5;
int *p=&i;
int **q = &p;
cout<< "All Okay" << endl;
cout<< "Adress p  - " << &p << endl;
cout<< "Adress p  - " <<*q << endl;

cout<< "Print p  - " << p << endl;

cout<< &i << endl;
cout<< p << endl;
cout<< *q << endl;

// Same address
cout  << "Print i"<< i<< endl;
cout  << "Print i"<< *p<< endl;
cout  << "Print i"<< **q<< endl;

cout<< &p << endl;
cout<< q << endl;





    return 0;

} */

void update(int **p2)
{
    //p2 = p2 + 1;
    //kuch change hoga  - NO

    //*p2 = *p2 + 1;
    //kuch change hoga - YES

    **p2 = **p2 + 1;
    //kuch change hoga - YES
}

int main()
{

    int i = 5;
    int* p = &i;
    int** p2 = &p;
    cout << endl<< endl;

    cout << "before " << i << endl;
    cout << "before " << p << endl;
    cout << "before " << p2 << endl;
    cout << endl;
    cout << endl;
    update(p2);
    cout << "after " << i << endl;
    cout << "after " << p << endl;
    cout << "after " << p2 << endl;
    cout << endl;
    cout << endl<< endl;

    return 0;
}