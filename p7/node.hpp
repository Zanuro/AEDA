#ifndef NODE_HPP
#define NODE_HPP
#include "dni.hpp"
#pragma once

template<class data_type>

class node{

    data_type data;
    short balance;
    node<data_type>* left;
    node<data_type>* right;


public:

    node();
    node(data_type data_);
    node(data_type data_, node<data_type>* left_, node<data_type>* right_);
    ~node(void);
    node*& get_left(void);
    node*& get_right(void);
    data_type& get_data(void);
    short& get_balance(void);
};

template<class data_type>
node<data_type>::node(void):
    data(),
    left(nullptr),
    right(nullptr){}

template<class data_type>
node<data_type>::node(data_type data_):
    data(data_),
    left(nullptr),
    right(nullptr){}

template<class data_type>
node<data_type>::node(data_type data_, node<data_type>* left_, node<data_type>* right_):
    data(data_),
    left(left_),
    right(right_){}


template<class data_type>
node<data_type>::~node(void){}

template<class data_type>
node<data_type>*& node<data_type>::get_left(void){
    return left;
}

template<class data_type>
node<data_type>*& node<data_type>::get_right(void){
    return right;
}

template<class data_type>
data_type& node<data_type>::get_data(void){
    return data;
}

template<class data_type>
short& node<data_type>::get_balance(void){
    return balance;
}



#endif // NODE_HPP
