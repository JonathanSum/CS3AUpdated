#include <utility>


//
// Created by JonathanSum on 5/7/2019.
//

#include "preferredCustomer.h"
#include <iostream>

using namespace std;
/***************************************************
 *
 *  double getOffLevel() const: Class PreferredCustomer
 ________________________________________________
 *   it return the discount level
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   discount level is returned
*****************************************************/
double PreferredCustomer::getOffLevel() const {
    return discountLevel*100;

}
/***************************************************
 *
 *  double getOffLevel() const: Class PreferredCustomer
 ________________________________________________
 *   it return the discount level
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   discount level is returned
*****************************************************/
double PreferredCustomer::getTotalBuy()const {
    return purchasesAmount;
}

/***************************************************
 *
 *  void setTotalBuy(double t) : Class PreferredCustomer
 ________________________________________________
 *   it change the discount level by the spend amount of t
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   discount level is changed
*****************************************************/
void PreferredCustomer::setTotalBuy(double t    //IN - spend amount
) {

    /*** CALC- calculate the discount leve by total spend amount:
    When a preferred customer spends $500, he or she gets a 5% discount on all future purchases.
    When a preferred customer spends $1,000, he or she gets a 6% discount on all future purchases.
    When a preferred customer spends $1,500, he or she gets a 7% discount on all future purchases.
    When a preferred customer spends $2,000 or more, he or she gets a 10% discount on all future purchases.
            ***/
    purchasesAmount = t;

    if(purchasesAmount < 500){

        discountLevel =0;
    }else if (purchasesAmount >= 500&&purchasesAmount<1000) {

        discountLevel = 0.05;
    }
    else if (purchasesAmount >= 1000&&purchasesAmount<1500) {

        discountLevel = 0.06;
    }
    else if (purchasesAmount >= 1500&&purchasesAmount<2000) {

        discountLevel = 0.07;
    }else if (purchasesAmount >= 2000) {

        discountLevel = 0.10;
    }

}
/***************************************************
 *
 *  PreferredCustomer(string last, string first, string a, string c, string s, unsigned z,
                                     long p, int the_customer_number, bool the_mailing_list,
                                     double the_purchases_amount) : Class PreferredCustomer
 ________________________________________________
 *   it initials from name, address, id, mail boolean to spend amount
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   It return a PreferredCustomer object
*****************************************************/
PreferredCustomer::PreferredCustomer(string last, string first, string a, string c, string s,
                                     unsigned z, long p, int the_customer_number, bool the_mailing_list,
                                     double the_purchases_amount) :
        CustomerData(the_customer_number, the_mailing_list),
        PersonData(std::move(last), std::move(first), std::move(a), std::move(c),
                   std::move(s), z, p) {
                     setTotalBuy( the_purchases_amount);


}
/***************************************************
 *
 *  add_TotalBuy : Class PreferredCustomer
 ________________________________________________
 *   it add the total amount of the amount the person has bought
 *   and update the discount level
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   discount level is changed
*****************************************************/
void PreferredCustomer::add_TotalBuy(double amount  //IN - amount from the product has bought
        ,string product //IN - product name
        ) {
    cout<<getName()<<" bought a "<<product<<"("<<amount<<")\n";

    purchasesAmount +=amount;
    setTotalBuy(purchasesAmount);

}
/***************************************************
 *
 *  void printData : Class PreferredCustomer
 ________________________________________________
 *   it print all of the information of the customer
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   customer information is printed.
*****************************************************/
void PreferredCustomer::printData()const {
    cout<<"Here is the customer's data:\n";
    cout<<"____________________________\n";
    cout<<"ID Number: "<<getId()<<endl;
    cout<<"Name: "<<getName()<<endl;
    cout<<"Total Purchases Amount"<<getTotalBuy()<<endl;
    cout<<"Discount level: "<<getOffLevel()<<"%"<<endl;
    cout << "subscribe for email: ";
    mailingList?cout<<"Yes\n":cout<<"No\n";

    cout<<"____________________________\n";
    cout<<"Address: "<<getAddress()<<endl;
    cout<<"Contact Number: "<<getPhone()<<endl;
    cout<<"____________________________\n";
}

PreferredCustomer::PreferredCustomer(double purch) {
    purchasesAmount = purch;

    setTotalBuy(purch);

}




















