
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstring>
#include <vector>
#include <string>
#include "personData.h"
#include "customerData.h"
#include "preferredCustomer.h"

/*********************************************
*   Author         : Jonathan Sum
*   Assignment     : Lab 16 Specifications
*   SECTION        : CS 003A
*   Due Date       : 5/13/19
*   ________________________________________________
*   Goal: write a base class with its child class
***********************************************/


using namespace std;


//PersonData class->CustomerData->PreferredCustomer
int main(){
    //CALC - Add the amount that Rozaliya has bought.
    PreferredCustomer Rozaliya = PreferredCustomer("Lenyeva","Rozaliya", "327 Borway", "Los Angele","CA",91740, 6269569400,1,true,1);
    Rozaliya.add_TotalBuy(769.99,"iPhone5");
    Rozaliya.add_TotalBuy(469.99,"iPhone4");

    //OUT - Print Rozaliya's data
    Rozaliya.printData();


    cout<<endl;
    cout<<endl;



    PersonData *PersonData_Liliya;          //IN - Liliya's Personal Data
    CustomerData *Liliya_Customer_Data;     //IN - Liliya's id number and info
    PreferredCustomer preferred_customer_Liliya = PreferredCustomer(1259.9);

    //CALC - Add the amount that Liliya has bought.
    Liliya_Customer_Data = & preferred_customer_Liliya;
    Liliya_Customer_Data->setId(2);
    Liliya_Customer_Data->setMail(false);
    PersonData_Liliya = Liliya_Customer_Data;
    PersonData_Liliya->setName("Liliya", "Olenyeva");
    PersonData_Liliya->set_contact_info("427 Borway", "San Jose","CA",91788, 6264571852);

    //OUT - Print Liliya's data
    preferred_customer_Liliya.printData();
    cout<<"\nend of line";

    return 0;

}
