Class example
        {
                public:
                // Constructor
                Example(string name = “example name”, int =5);

//Copy Constructor
                Example(const Example & obj);

//Overloaded Assignment
                Example & operator=(const Example& obj);

//Destructor
                ~Example();
                Private:
                string name;
                int num;
        }
Example::Example(string n, int amount)
{
    name = n;
    number = amount;
}
Example::Example(const Example& obj)		//copy constructor
{
    this.name = obj.name;
    this.number = obj.number;
}
Example& Example::operator=(const Example& obj)
{
    If(this==&obj){
        return *this;
    }
    this->name = obj.name;
    this-> number = obj.number;
    return *this;
}
//Destructor
Example:: ~Example(){

}
