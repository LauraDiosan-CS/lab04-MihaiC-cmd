//
//  repo.hpp
//  laborator4
//
//  Created by Comsa Mihai on 20/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "payments.hpp"
#pragma once

class Repo
{
private:
    Payments payments[20];
    int n;
public:
    Repo();
    ~Repo();
    Payments* get_all();
    int get_size();
    void insert_payment(Payments &p);
    void add_payment(int amount, char* type);
    void update_payment(Payments& pay, int day, int amount, char* type);
    int search(const Payments& p);
    void delete_by_day(Payments p);
};
