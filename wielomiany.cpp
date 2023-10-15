#include <iostream>
#include "polynomial.hpp"
#include <vector>

using namespace std;

polynomial poly1, poly2, poly3;

double a;

int dzialanie;


void input()
{
    cout<<"Stopien pierwszego wielomianu: "<<endl;
    cin>>poly1.level;
    cout<<"Stopien drugiego wielomianu: "<<endl;
    cin>>poly2.level;

    poly1.values = new double[poly1.level];
    poly2.values = new double[poly2.level];

    cout<<"Wprowadz wartosci pierwszego wielomianu: "<<endl;
    for(int i =0; i<poly1.level; i++)
    {
        cin>>a;
        poly1.values[i] = a;
    }
    cout<<"Wprowadz wartosci drugiego wielomianu: "<<endl;
    for(int i =0; i<poly2.level; i++)
    {
        cin>>a;
        poly2.values[i] = a;
    }
    cout<<"Menu dzialan"<<endl;
    cout<<"------------"<<endl;
    cout<<"1: Dodaj"<<endl;
    cout<<"2: Odejmij"<<endl;
    cout<<"3: Pomnoz"<<endl;
    cout<<"------------"<<endl;
    cout<<"Wybierz dzialanie: ";
    cin>>dzialanie;
}


int main() {
    input();
    switch (dzialanie)
    {
    case 1:
        poly3 = add(poly1, poly2);
        break;
    case 2:
        poly3 = subtract(poly1, poly2);
        break;
    case 3:
        poly3 = multiply(poly1, poly2);
        break;
    
    default:
        cout<<"zly input, sprobuj ponownie";
        break;
    }
    
    cout << get_level(poly3) << endl;
    for(int i = 0; i < get_level(poly3); i++) 
    {
        if (i == 0) 
        {
            cout << get_value(poly3, i);
        } else 
        {
            cout << " + " << get_value(poly3, i) << "x^" << i;
        }
    }
    return 0;
}