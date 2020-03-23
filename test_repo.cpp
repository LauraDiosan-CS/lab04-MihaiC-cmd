//
//  test_repo.cpp
//  laborator4
//
//  Created by Comsa Mihai on 20/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "test_repo.hpp"
#include "payments.hpp"
#include "repo.hpp"
#include <stdio.h>
#include <ctime>


void test_repo()
{
    char type[] = "Apa";
    Payments p(1, 2, type);
    
    Repo pay;
    
    assert(pay.get_size() == 0);
    pay.add_payment(12, type);
    assert(pay.get_size() == 1);
    pay.insert_payment(p);
    assert(pay.get_size() == 2);
    
    Payments* test = new Payments[pay.get_size()];
    test = pay.get_all();
    
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    Payments t(ltm->tm_mday, 12, type);
    
    assert(test[1] == p);
    assert(test[0] == t);
}
