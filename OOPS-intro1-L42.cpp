/* #include"Hero.cpp" //to include external class i.e external file
 */
#include <iostream>
using namespace std;

class Hero
{
private:
    int health;

    /*     public :
            if we write public here "in middle" then the element above is private
            and the below element will be public
     */

public:
    char level;

    // constructor adding
    // when we add our constructor the default constructor automatically deleted

    Hero()
    {
        cout << "Constructor called" << endl;
    }

    // Parameterised Constructor
    Hero(int health)
    {
        cout << " this -> " << this << endl;
        this->health = health;
    }

    Hero(int health, char level)
    {

        this->level = level;
        this->health = health;
        cout << " this -> " << this << endl;
    }

    void print()
    {
        cout << level << endl;
    }

    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }
    void setHealth(int h)

    {
        /*
            void setHealth(int h, char name)
            if(name='A'){

        health = h;
         } */
        health = h;
    }

    void setLevel(char ch)
    {
        level = ch;
    }
};
int main()
{
    /*
        // Creation of object
        Hero ramesh;
        cout << "Size of Ramesh is " << sizeof(ramesh) << endl;

        cout << "ramesh Health " << ramesh.getHealth() << endl;
        cout << "ramesh Level " << ramesh.getLevel() << endl;

        // use setter
        ramesh.setHealth(90);
        ramesh.setLevel('B');

        /*
        //asigning values with the help of dot
            ramesh.health=70;
            ramesh.level='A';
            */
    //    cout << "ramesh Health " << ramesh.getHealth() << endl;
    //  cout << "ramesh Level " << ramesh.getLevel() << endl;

    // cout << "Health is : " << ramesh.health << endl;
    // cout << "Level is : " << ramesh.level << endl;

    /*
        Hero h1;
    cout << "Size : " << sizeof(h1) <<endl; //4

    After making empty class the size will be 1 byte
    to keep identification and to keep track
     */

    /*   // static allocation
      Hero a;
      a.setHealth(90);
      a.setLevel('C');
      cout <<" Level is " << a.level <<endl;
      cout <<" Health is " << a.getHealth()<<endl;

      // dynamic allocation
      Hero *b = new Hero; // Memory allocated in Heap
      b->setLevel('D');
      b->setHealth(100);

      cout <<" Level is " << (*b).level <<endl;
      cout <<" Health is " << (*b).getHealth()<<endl;

      cout <<" Level is " << b->level <<endl;
      cout <<" Health is " << b->getHealth()<<endl;
   */

    /* cout << "HI" << endl;
    Hero bheem; // object created statically " && " constuctor calling
    cout << "BYE" << endl;

    Hero *h = new Hero; // object created dynamically && here too the constructor calling
 */

    // object created statically
    Hero ramesh(10);
    cout << "Address of Ramesh : " << &ramesh << endl;
    ramesh.print();

    // object created dynamically
    Hero *h = new Hero();
    h->print();

    Hero temp(22, 'B');
    temp.print();
    return 0;
}
