#include <iostream>
#include <string>
using namespace std;

/*  //Encapsulation
class Student {
    private:
    string name;
    int age;
    int height;

    public:
    int getAge(){
        return this ->age;
    }
};  */

/*  //Inheritance   --  public base public child
class Human
{
public:
    int height;
    int weight;
    int age;

public:
    int getAge()
    {
        return this->age;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
};
class Male : public Human
{
public:
    string color;
    void sleep()
    {
        cout << "Male is Sleeping " << endl;
    }
}; */

/* // Protected
class Human
{
public:
    int height;
    int weight;

private:
    int age;

public:
    int getAge()
    {
        return this->age;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
};
class Male : protected Human
{
public:
    string color;
    void sleep()
    {
        cout << "Male is Sleeping " << endl;
    }
    int getHeight()
    {
        return this->height;
    }
}; */

/* // Single Inheritance

class Animal
{
public:
    int age;
    int weight;

public:
    void speak()
    {
        cout << " Speaking " << endl;
    }
};
class Dog : public Animal
{
}; */

/* //MultiLevel Inheritance

class Animal
{
public:
    int age;
    int weight;

public:
    void speak()
    {
        cout << " Speaking " << endl;
    }
};
class Dog : public Animal
{
};
class GermanShepher : public Dog {

}; */

/* // Multiple Inheritance

class Animal
{
public:
    int age;
    int weight;

public:
    void bark()
    {
        cout << " Barking " << endl;
    }
};

class Human
{
public:
    string color;

public:
    void speak()
    {
        cout << " Speaking " << endl;
    }
};
// Multiple Inheritance Doing
class hybrid : public Animal, public Human
{
};
 */
        

/* // Hierarchical Inheritance

class A{
    public:
    void func1(){
    cout <<"Inside function Class A " <<endl;
    }
};
class B:public A{
public:
    void func2(){
    cout <<"Inside function Class B " <<endl;
    }
};
class C:public A{
public:
    void func3(){
    cout <<"Inside function Class C " <<endl;
    }
}; */

/* //Hybrid Inheritance

class A{
    public:
    void func1(){
    cout <<"Inside function Class A " <<endl;
    }
};
class B:public A{
public:
    void func2(){
    cout <<"Inside function Class B " <<endl;
    }
};
class C:public B{
public:
    void func3(){
    cout <<"Inside function Class C " <<endl;
    }
};  */

/* //Inheritance Ambiguity

class A{
    public:
    void func(){
    cout <<" I am A " <<endl;
    }
};
class B{
public:
    void func(){
    cout <<" I am B " <<endl;
    }
};
class C: public A ,public B{

};  */


int main()
{

    /*  //Encapsulation
            Student first;
            cout <<" All Okay "<<endl;
         */

    /*  //Inheritance  --  public base public child
        Male object1;
        cout << object1.age << endl;
        cout << object1.weight << endl;
        cout << object1.height << endl;
        cout << object1.color << endl;

        object1.sleep();
        object1.setWeight(85);
        cout <<object1.weight <<endl;
         */

    /*     //protected
        Male m1;
        cout << m1.getHeight() << endl; */

    /*     // Single Inheritance

        Dog d;
        d.speak();
        cout << d.age <<endl; */

    /* //MultiLevel Inheritance
    GermanShepher g;
    g.speak(); */

/*     // Multiple Inheritance
    hybrid obj1;
    obj1.bark();
    obj1.speak();
 */
        
/* // Hierarchical Inheritance
A object1;
object1.func1();
cout <<endl;
B object2;
object2.func1();
object2.func2();
cout <<endl;

C object3;
object3.func1();
// object3.func2();  It will give error as there is no link too func2 in class C 
object3.func3();
 */

/* //Hybrid Inheritance
A object1;
object1.func1();
cout <<endl;
B object2;
object2.func1();
object2.func2();
cout <<endl;

C object3;
object3.func1();
object3.func2(); 
object3.func3();
 */

/* //Inheritance Ambiguity
C obj;
// obj.func(); error
obj.A::func();
obj.B::func();
 */



    return 0;
}