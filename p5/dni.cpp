#include "dni.hpp"

dni::dni():
    dni_(0){}


dni::dni(unsigned long int dnii):
    dni_(0){
    set_dni(dnii);
}

dni::~dni(void){}


unsigned long int dni::get_dni(void){
    return dni_;
}

void dni::set_dni(unsigned long int dnii){

    if (dnii < 10000000 || dnii > 99999999){

            cout << "Dni no es valido" << endl;
            set_random();
        }
        else{
            dni_ = dnii;
        }
    }

void dni::set_random(void){

  random_device rd; // obtain a random number from hardware
  mt19937 generator(rd());
  uniform_int_distribution<> distr(10000000, 99999999);
  dni_ = distr(generator);

}

bool dni::operator<(dni& dni_n){

    return dni_ < dni_n.get_dni();
}


bool dni::operator>(dni& dni_n){

    return dni_ > dni_n.get_dni();
}

bool dni::operator==(dni& dni_n){

    return dni_ == dni_n.get_dni();
}

bool dni::operator !=(dni& dni_n){

    return dni_ != dni_n.get_dni();
}

ostream& operator<<(ostream& os, const dni& dni_s)
{
    os << dni_s.dni_;
    return os;
}
