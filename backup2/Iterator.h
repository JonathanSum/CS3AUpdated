/****




private:
    Node<E> *current;
public:
    /**************************************
    **      CONSTRUCTOR  AND DESTRUCTOR  **
    ***************************************/
Iterator();
void doSomething(E param);

Iterator(Node<E> *ptr);

/**********************
    * * MUTATORS **
**********************/
int operator*();

Iterator<E> operator++();
Iterator<E> operator++(int);
/**********************
    * * ACCESSORS **
 **********************/
bool operator==(const Iterator &right) const;

bool operator!=(const Iterator &right) const;
//Constructors//





***/