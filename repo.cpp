//
//  repo.cpp
//  laborator4
//
//  Created by Comsa Mihai on 20/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "repo.hpp"
#include <ctime>

using namespace std;

Repo::Repo()
{
    this->n = 0;
    cout << "The CONSTRUCTOR is called" << endl;
}
Repo::~Repo()
{
    this->n = 0;
    cout << "The DESTRUCTOR is called" << endl;
}
void Repo::insert_payment(Payments &p)
{
    this->payments[this->n++] = p;
}

Payments* Repo::get_all()
{
    return this->payments;
}

int Repo::get_size()
{
    return this->n;
}

void Repo::add_payment(int amount, char* type)
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    Payments p(ltm->tm_mday, amount, type);
    this->payments[this->n++] = p;
}

void Repo::update_payment(Payments& pay, int day, int amount, char *type)
{
    pay.set_day(day);
    pay.set_amount(amount);
    pay.set_type(type);
}

int Repo::search(const Payments& p)
{
    int n = this->get_size();
    for (int i = 0; i < n; i++)
    {
        if (this->payments[i] == p)
            return i;
    }
    return -1;
}

void Repo::delete_by_day(Payments p)
{
    int pos = this->search(p);
    int n = this->get_size();
    if (pos != -1)
    {
        for (int i = 0; i < n - 1; i++)
            this->payments[i] = this->payments[i+1];
    }
}

