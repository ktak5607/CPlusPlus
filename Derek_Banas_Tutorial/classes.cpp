#include <iostream>
#include <string>
using namespace std;

class Animal{
//create private variables and function prototypes
    private:
        int height;
        int weight;
        string name;
        //static means can be used by any object of this class that's created
        static int numOfAnimals;
    //create public variables and function prototypes
    public:
        int getHeight(){return height;}
        int getWeight(){return weight;}
        string getName(){return name;}

        void setHeight(int cm){height=cm;}
        void setweight(int kg){weight=kg;}
        void setHeight(string animalName){name=animalName;}

        void setAll(int, int, string);
        //create a constructor prototype
        Animal(int, int, string);
        //create destructor prototype
        ~Animal();
        //another constructor prototype that take no values, called overloading
        Animal();

        //can also have protected values and functions which are available only members of same class and any subclasses
        //static functions are attached to the class not the object, and can only access static variables
        static int getNumAnimals(){return numOfAnimals;}
        void toString();
};

//how to access static variables
int Animal::numOfAnimals = 0;
//create actual functions
void Animal::setAll(int height, int weight, string name){
    //use this -> to set height since no Animal object has been created yet
    this -> height = height;
    this -> weight = weight;
    this -> name = name;
    Animal::numOfAnimals++;
}

//create constructor
Animal::Animal(int height, int weight, string name){
    //use this -> to set height since no Animal object has been created yet
    this -> height = height;
    this -> weight = weight;
    this -> name = name;
    Animal::numOfAnimals++;
}

//create actual destructor
Animal::~Animal(){
    cout << "Animal: "<< this->name << " destroyed" << endl;
    Animal::numOfAnimals--;
}

Animal::Animal(){
    Animal::numOfAnimals++;
}

void Animal::toString(){
    cout<<"this is "<<this -> name<< " and it is "<<this->height<<" cm and "<<this->weight<<" kg"<<endl;
}


class Dog:public Animal{
private:
    string sound = "bark";
public:
    void getSound(){cout<<sound<<endl;}

    Dog(int, int, string, string);
    //use Animal empty constructor for dog empty constructor
    Dog():Animal(){};
    //don't need destructor since Animal class takes care of it
    void toString();
};

//use Animals consructor to handle height, weight, and name, only need to handle sound in Dog's constructor
Dog::Dog(int height, int weight, string name, string bark):Animal(height, weight,  name){
    this ->sound = bark;

}

void Dog::toString(){
    //need to use getName(), etc because Animals name, height, and weight were private so Dog can't access them.
    cout<<"this is "<<this -> getName()<< " and it is "<<this->getHeight()<<" cm and "<<this->getWeight()<<" kg"<<" and says "
        <<this-> sound<<endl;

}
int main()
{
    Animal Bowie(160, 50, "Bowie");
    Bowie.toString();

    Dog sparky(40, 10, "Sparky", "Bark");
    sparky.toString();
    sparky.getSound();
    cout<<Animal::getNumAnimals()<<endl;
    return 0;
}
