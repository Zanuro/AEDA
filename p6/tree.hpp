#ifndef TREE_HPP
#define TREE_HPP
#include "node.hpp"


#pragma once

using namespace std;

template<class data_type>
class tree;

template<class data_type>
std::ostream &operator<< (std::ostream &os , node<data_type>*& current) ;

template<class data_type>
class tree{

    node<data_type>* root;
    unsigned long int comparison;

public:
         tree(void);
         tree(node<data_type>* root_);
        ~tree(void);

        unsigned insert(data_type value);
        unsigned insert(node<data_type>*& root_, node<data_type>* current, unsigned comparacion);

        void eliminate(data_type value);
        void eliminate(node<data_type>*& root_, data_type value);
        void podar(node<data_type>*& current);


        node<data_type>* search(data_type value);
        node<data_type>* search(node<data_type>* current,data_type value);

        node<data_type>* get_root(void);
        bool empty(node<data_type>* current) const;
        bool empty_tree(void) const;
        unsigned get_size_node(node<data_type>* current) const;
        unsigned get_size_tree(void) const;
        void change_node(node<data_type>*& current, node<data_type>*& new_);
        unsigned height_tree(void) const;
        unsigned height_node(node<data_type>* current) const;
        bool isLeaf(node<data_type>* current);
        unsigned get_comparison(void);


        void inorder(void);
        void inorder(node<data_type>* root_);
        void preorder(void);
        void preorder(node<data_type>* root_);
        void postorder(void);
        void postorder(node<data_type>* root_);
        void print(node<data_type>* current);
        void print_level(node<data_type>* root_);

        //friend std::ostream &operator<< <>(std::ostream &os , const tree &current);

};

template<class data_type>
tree<data_type>::tree(void):
    root(nullptr),
    comparison(0){}

template<class data_type>
tree<data_type>::tree(node<data_type>* root_):
    root(root_),
    comparison(0){}

template<class data_type>
tree<data_type>::~tree(void){
    podar(root);
}

template<class data_type>
unsigned tree<data_type>::insert(data_type value){
    node<data_type>* node_ = new node<data_type>(value);
    return insert(root, node_, 0);
}

template<class data_type>
unsigned tree<data_type>::insert(node<data_type>*& root_, node<data_type>* current, unsigned comparacion){

    comparacion++;

    if(empty(root_)){
        root_ = current;
        return comparacion;

    }
    if(current->get_data() <= root_->get_data())

        comparacion = insert(root_->get_left(), current, comparacion);

    else
        comparacion = insert(root_->get_right(), current, comparacion);


    return comparacion;
}

template<class data_type>
void tree<data_type>::eliminate(data_type value){

    eliminate(root,value);}


template<class data_type>
void tree<data_type>::eliminate(node<data_type>*& root_, data_type value){

    if(empty(root_))
            return;

    if(value < root_->get_data())
        eliminate(root_->get_left(),value);

    else if(value > root_->get_data())
        eliminate(root_->get_right(),value);

    else{
            node<data_type>* aux = root_;

            if(empty(root_->get_right()))
                root_ = root_->get_left();
            else if(empty(root_->get_left()))
                root_ = root_->get_right();
            else
                change_node(aux, root_->get_left());

            delete aux;
        }}

template<class data_type>
void tree<data_type>::podar(node<data_type>*& current){

    if(empty(current))
        return;

    podar(current->get_left());
    podar(current->get_right());
    delete current;
    current = nullptr;
}

template<class data_type>
node<data_type>* tree<data_type>::search(data_type value){

    comparison = 0;
    return search(root, value);
}

template<class data_type>
node<data_type>* tree<data_type>::search(node<data_type>* current, data_type value){

    if(empty(current)){
        comparison++;
        return nullptr;}
    if(value == current->get_data()){
        comparison++;
        return current;
     }
    if (value < current->get_data()){
        comparison++;
        return search(current->get_left(), value);}

    return search(current->get_right(), value);

    }


template<class data_type>
node<data_type>* tree<data_type>::get_root(void){
    return root;

}

template<class data_type>
bool tree<data_type>::empty(node<data_type>* current) const{return current == nullptr;}


template<class data_type>
bool tree<data_type>::empty_tree(void) const{return empty(root);}


template<class data_type>
unsigned tree<data_type>::get_size_tree(void) const {
       return get_size_node(root);
}

template<class data_type>
unsigned tree<data_type>::get_size_node(node<data_type>* current) const {
    if(empty(current))
       return 0;

    return(get_size_node(current->get_left())+get_size_node(current->get_right())+1);
}


template<class data_type>
void tree<data_type>::change_node(node<data_type>*& current, node<data_type>*& new_){

    if (new_->get_right() != nullptr)
        change_node(current, new_->get_right());

     else {
         current->get_data() = new_->get_data();
         current = new_;
         new_ = new_->get_left();
       }
}

template<class data_type>
unsigned tree<data_type>::get_comparison(void){
    return comparison;
}

template<class data_type>
bool tree<data_type>::isLeaf(node<data_type> *current){

    return !current->get_right() && !current->get_left();}

template<class data_type>
unsigned tree<data_type>::height_tree(void) const {return height_node(root);}

template<class data_type>
unsigned tree<data_type>::height_node(node<data_type>* current) const{
     if (empty(current))
         return 0;

      int alt_i = height_node(current->get_left());
      int alt_d = height_node(current->get_right());
         if (alt_d > alt_i)
            return alt_d++;
         else
            return alt_i++;}

template<class data_type>
void tree<data_type>::inorder(void){ inorder(root);}

template<class data_type>
void tree<data_type>::inorder(node<data_type>* root){

     if(empty(root))
        return;
     inorder(root->get_left());
     print(root);
     inorder(root->get_right());}

template<class data_type>
void tree<data_type>::preorder(void){ preorder(root);}

template<class data_type>
void tree<data_type>::preorder(node<data_type>* root){

     if(empty(root))
        return;
     print(root);
     preorder(root->get_left());
     preorder(root->get_right());}

template<class data_type>
void tree<data_type>::postorder(void){ postorder(root);}

template<class data_type>
void tree<data_type>::postorder(node<data_type>* root){

     if(empty(root))
        return;

      postorder(root->get_left());
      postorder(root->get_right());
      print(root);}

template<class data_type>
void tree<data_type>::print(node<data_type>* current){

     if(empty(current)){
        cout << "[.]";
        return;}

      cout << current->get_data() << " ";
}

template<class data_type>
void tree<data_type>::print_level(node<data_type> *root_){

     queue<pair<node<data_type>*, int>> Q;
     node<data_type>* nodo_;

     int level, present_level = 0;

     //Q.push_back(pair<node<data_type>*, int>(root_,0));
     Q.push(pair<node<data_type>*, int>(root_,0));

     cout << "Nivel 0: ";
     while (!Q.empty()) {
         nodo_ = get<0>(Q.front());
         level = get<1>(Q.front());

        Q.pop();

        if(level > present_level){
            present_level = level; // increment level
            cout << endl << "Nivel " << present_level << ": ";}

        if(!empty(nodo_)) {
            print(nodo_);
            Q.push(pair<node<data_type>*, int>(nodo_->get_left(), level+1));
            Q.push(pair<node<data_type>*, int>(nodo_->get_right(), level+1));}

        else{
            print(nullptr);
            // subtree empty
     }

}

}


#endif // TREE_HPP
