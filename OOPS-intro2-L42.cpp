#include <iostream>
#include <string.h>
using namespace std;

class Hero
{

private:
    int health;

public:
    char *name;
    char level;
    static int timeToComplete;
    // Default Constructor
    Hero()
    {
        cout << "Default / Simple  Constructor Called " << endl;
        name = new char[100];
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
        health = h;
    }
    void setLevel(char ch)
    {
        level = ch;
    }

    void setName(char name[])
    {
        strcpy(this->name, name);
    }
    // Parameterized  Constructor
    Hero(int health, char level)
    {

        this->level = level;
        this->health = health;
    }
    // Copy   Constructor
    /*
    Hero(Hero &temp)
    {
        If we do-not use" &" i.e we do not do pass by reference then it will stuck in infinite loop
        this->level = temp.level;
        this->health = temp.health;
        cout << " Copy Constructor Called " << endl;
    } */
    Hero(Hero &temp)
    {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->level = temp.level;
        this->health = temp.health;
        cout << " Copy Constructor Called " << endl;
    }

    // Destructor
    ~Hero()
    {
        cout << " Destructor get called " << endl;
    }

    void print()
    {
        cout << " Health " << this->health << endl;
        cout << " Level " << this->level << endl;
        cout << " Name " << this->name << endl;
    }

    static int random(){
        return timeToComplete ;   
    }
};

int Hero ::timeToComplete = 10;

int main()
{
    /*
        Hero suresh (70 ,'C');

        //suresh.setHealth(70);
        //suresh.level('c');

    //Copy Constructor called
    suresh.print();
    Hero ritesh (suresh); // Below 2 lines are its equivalent

    // ritesh.health =suresh.health;   ritesh.level =suresh.level;
    ritesh.print();

     */

    /*  Hero hero1;

     hero1.setHealth(12);
     hero1.setLevel('D');
     char name[7] = "Babbar";
     hero1.setName(name);

     // hero1.print();

     // use copy constructor
     Hero hero2(hero1);
     // Hero hero2 = hero1;
     // hero2.print();
     hero1.name[0] = 'G';
     hero1.print();
     hero2.print();


     hero1 = hero2;
     hero1.print();
     hero2.print();
  */

   /*  // Static
    Hero a;

    // dynamically
    Hero *b = new Hero();

    // Automatically call destructor for static

    // Manually call destructor for dynamically
    delete b;
 */

//cout<< Hero ::timeToComplete <<endl;  
cout << Hero ::random()<<endl;



    return 0;
}     