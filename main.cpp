//
//  main.cpp
//  laborator4
//
//  Created by Comsa Mihai on 16/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include <iostream>
#include "test_payments.hpp"
#include "test_repo.hpp"
#include "payments.hpp"
#include "repo.hpp"
#include "test_repo.hpp"

using namespace std;

int main() {
    
    test_getter();
    test_setter();
    test_eq();
    test_repo();
    
    Repo pay;
    
    char type_1[] = "Mancare", type_2[] = "Haine", type_3[] = "Internet";
    
    Payments p_1(1, 200, type_1), p_2(30, 2500, type_2);
    
    pay.insert_payment(p_1);
    pay.insert_payment(p_2);
    
    Payments* test = new Payments[pay.get_size()];
    
    test = pay.get_all();
   
    for (int i = 0; i < pay.get_size(); i++)
    {
        if  (i == pay.get_size() - 1)
        {
            cout << test[i] << endl;
        }
        else
        {
            cout << test[i] << " , ";
        }
    }
    cout << "Size = " << pay.get_size() << endl;
    
    pay.add_payment(200, type_3);
    test = pay.get_all();
    
    for (int i = 0; i < pay.get_size(); i++)
    {
        if  (i == pay.get_size() - 1)
        {
            cout << test[i] << endl;
        }
        else
        {
            cout << test[i] << " , ";
        }
    }
    cout << "Size = " << pay.get_size() << endl;
    cout << pay.get_size() << endl;
    
    return 10;
}
