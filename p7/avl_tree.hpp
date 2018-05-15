#ifndef TREE_HPP
#define TREE_HPP
#include "node.hpp"


#pragma once

using namespace std;

template<class data_type>
class avl_tree;

template<class data_type>
std::ostream &operator<< (std::ostream &os , node<data_type>*& current) ;

template<class data_type>
class avl_tree{

    node<data_type>* root;
    unsigned long int comparison;

public:
         avl_tree(void);
         avl_tree(node<data_type>* root_);
        ~avl_tree(void);

        void insert(data_type value);
        //unsigned insert(node<data_type>*& root_, node<data_type>* current, unsigned comparacion);

        void eliminate(data_type value);
        //void eliminate(node<data_type>*& root_, data_type value);
        void podar(node<data_type>*& current);


        node<data_type>* search(data_type value);
        node<data_type>* search(node<data_type>* current,data_type value);

        node<data_type>* get_root(void);
        bool empty(node<data_type>* current) const;
        bool empty_avl_tree(void) const;
        unsigned get_size_node(node<data_type>* current) const;
        unsigned get_size_avl_tree(void) const;
        //void change_node(node<data_type>*& current, node<data_type>*& new_);
        unsigned height_avl_tree(void) const;
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

        void rotate_RR(node<data_type>* & nodo_);
        void rotate_LL(node<data_type>* & nodo_);
        void rotate_RL(node<data_type>* & nodo_);
        void rotate_LR(node<data_type>* & nodo_);
        bool balanced(void);
        bool balanced(node<data_type>* nodo_);

        void insert_balanced(node<data_type>*& nodo_, node<data_type>* new_, bool& crece);
        void insert_rebalance_left(node<data_type>*& nodo_, bool& crece);
        void insert_rebalance_right(node<data_type>*& nodo_, bool& crece);

        void eliminate_rama(node<data_type>*& nodo_, data_type value, bool& decrece);
        void eliminate_rebalance_left(node<data_type>*& nodo_, bool& decrece);
        void eliminate_rebalance_right(node<data_type>*& nodo_, bool& decrece);
        void change(node<data_type>*& eliminated, node<data_type>*& new_, bool& decrece);



        //friend std::ostream &operator<< <>(std::ostream &os , const avl_tree &current);

};

template<class data_type>
avl_tree<data_type>::avl_tree(void):
    root(nullptr),
    comparison(0){}

template<class data_type>
avl_tree<data_type>::avl_tree(node<data_type>* root_):
    root(root_),
    comparison(0){}

template<class data_type>
avl_tree<data_type>::~avl_tree(void){
    podar(root);
}


/*template<class data_type>
unsigned avl_tree<data_type>::insert(node<data_type>*& root_, node<data_type>* current, unsigned comparacion){

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
}*/


/*template<class data_type>
void avl_tree<data_type>::eliminate(node<data_type>*& root_, data_type value){

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
        }}*/

template<class data_type>
void avl_tree<data_type>::podar(node<data_type>*& current){

    if(current==nullptr)
        return;

    podar(current->get_left());
    podar(current->get_right());
    delete current;
    current = nullptr;
}

template<class data_type>
node<data_type>* avl_tree<data_type>::search(data_type value){

    comparison = 0;
    return search(root, value);
}

template<class data_type>
node<data_type>* avl_tree<data_type>::search(node<data_type>* current, data_type value){

    if(current==nullptr){
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
node<data_type>* avl_tree<data_type>::get_root(void){
    return root;

}

template<class data_type>
bool avl_tree<data_type>::empty(node<data_type>* current) const{return current == nullptr;}


template<class data_type>
bool avl_tree<data_type>::empty_avl_tree(void) const{return empty(root);}


template<class data_type>
unsigned avl_tree<data_type>::get_size_avl_tree(void) const {
       return get_size_node(root);
}

template<class data_type>
unsigned avl_tree<data_type>::get_size_node(node<data_type>* current) const {
    if(current==nullptr)
       return 0;

    return(get_size_node(current->get_left())+get_size_node(current->get_right())+1);
}


/*template<class data_type>
void avl_tree<data_type>::change_node(node<data_type>*& current, node<data_type>*& new_){

    if (new_->get_right() != nullptr)
        change_node(current, new_->get_right());

     else {
         current->get_data() = new_->get_data();
         current = new_;
         new_ = new_->get_left();
       }
}*/

template<class data_type>
unsigned avl_tree<data_type>::get_comparison(void){
    return comparison;
}

template<class data_type>
bool avl_tree<data_type>::isLeaf(node<data_type> *current){

    return !current->get_right() && !current->get_left();}

template<class data_type>
unsigned avl_tree<data_type>::height_avl_tree(void) const {return height_node(root);}

template<class data_type>
unsigned avl_tree<data_type>::height_node(node<data_type>* current) const{

     if (current==nullptr)
         return 0;

     return max(height_node(current->get_left()), height_node(current->get_right()))+1;
      }

template<class data_type>
void avl_tree<data_type>::inorder(void){ inorder(root);}

template<class data_type>
void avl_tree<data_type>::inorder(node<data_type>* root){

     if(empty(root))
        return;
     inorder(root->get_left());
     print(root);
     inorder(root->get_right());}

template<class data_type>
void avl_tree<data_type>::preorder(void){ preorder(root);}

template<class data_type>
void avl_tree<data_type>::preorder(node<data_type>* root){

     if(root==nullptr)
        return;
     print(root);
     preorder(root->get_left());
     preorder(root->get_right());}

template<class data_type>
void avl_tree<data_type>::postorder(void){ postorder(root);}

template<class data_type>
void avl_tree<data_type>::postorder(node<data_type>* root){

     if(empty(root))
        return;

      postorder(root->get_left());
      postorder(root->get_right());
      print(root);}

template<class data_type>
void avl_tree<data_type>::print(node<data_type>* current){

     if(current==nullptr){
        cout << "[.]";
        return;}

      cout << current->get_data() << " ";
}

template<class data_type>
void avl_tree<data_type>::print_level(node<data_type> *root_){

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

        if(nodo_!=nullptr) {
            print(nodo_);
            Q.push(pair<node<data_type>*, int>(nodo_->get_left(), level+1));
            Q.push(pair<node<data_type>*, int>(nodo_->get_right(), level+1));}

        else{
            print(nullptr);
            // subtree empty
     }

}

}

template<class data_type>
bool avl_tree<data_type>::balanced(void){
    return balanced(root);
}

template<class data_type>
bool avl_tree<data_type>::balanced(node<data_type>* nodo_){
    if(nodo_ == nullptr)
            return true;

    int balance = height_node(nodo_->get_left()) - height_node(nodo_->get_right());

        switch(balance){
            case -1:
            case 0:
            case 1:
            return balanced(nodo_->get_left()) && balanced(nodo_->get_right());
            default: return false;
        }
    }


template<class data_type>
void avl_tree<data_type>::rotate_LL(node<data_type> *&nodo){

     node<data_type>* nodo_ = nodo->get_left();
     nodo->get_left() = nodo_->get_right();
     nodo_->get_right() = nodo;

     if (nodo_->get_balance() == 1) {
        nodo->get_balance() = 0;
        nodo_->get_balance() = 0;}

     else { // nodo_->get_balance() == 0
        nodo->get_balance() = 1;
        nodo_->get_balance() = -1;}

     nodo = nodo_;
    }

template<class data_type>
void avl_tree<data_type>::rotate_RR(node<data_type> *&nodo){

     node<data_type>* nodo_ = nodo->get_right();
     nodo->get_right() = nodo_->get_left();
     nodo_->get_left() = nodo ;

     if (nodo_->get_balance() == -1) {
        nodo->get_balance() = 0;
        nodo_->get_balance() = 0;}

     else { // nodo_->getbalance() == 0
        nodo->get_balance() = -1;
        nodo_->get_balance() = 1;}

     nodo = nodo_;
    }



template<class data_type>
void avl_tree<data_type>::rotate_LR(node<data_type> *&nodo){

     node<data_type>* nodo_a = nodo->get_left();
     node<data_type>* nodo_b = nodo_a->get_right();

     nodo->get_left() = nodo_b->get_right();
     nodo_b->get_right() = nodo;
     nodo_a->get_right() = nodo_b->get_left();
     nodo_b->get_left() = nodo_a;

     if (nodo_b->get_balance() == -1)
         nodo_a->get_balance() = 1;

     else
         nodo_a->get_balance() = 0;

     if (nodo_b->get_balance() == 1)
         nodo->get_balance() = -1;

     else
         nodo->get_balance() = 0;

     nodo_b->get_balance() = 0;
     nodo = nodo_b;

}

template<class data_type>
void avl_tree<data_type>::rotate_RL(node<data_type> *&nodo){

     node<data_type>* nodo_a = nodo->get_right();
     node<data_type>* nodo_b = nodo_a->get_left();

     nodo->get_right() = nodo_b->get_left();
     nodo_b->get_left() = nodo;
     nodo_a->get_left() = nodo_b->get_right();
     nodo_b->get_right() = nodo_a;

     if (nodo_b->get_balance() == 1)
         nodo_a->get_balance() = -1;

     else
         nodo_a->get_balance() = 0;

     if (nodo_b->get_balance() == -1)
         nodo->get_balance() = 1;

     else
         nodo->get_balance() = 0;

     nodo_b->get_balance() = 0;
     nodo = nodo_b;

}

template<class data_type>
void avl_tree<data_type>::insert(data_type value){
     node<data_type>* nodo_ = new node<data_type>(value);
     bool crece = false;
     insert_balanced(root, nodo_, crece);
}

template<class data_type>
void avl_tree<data_type>::eliminate(data_type value){

    bool decrece = false;
    eliminate_rama(root, value, decrece);}



template<class data_type>
void avl_tree<data_type>::insert_balanced(node<data_type> *&nodo_, node<data_type> *new_, bool &crece){

     if (nodo_ == nullptr){
      nodo_ = new_;
      crece = true;}

     else if (new_->get_data() < nodo_->get_data()){

         insert_balanced(nodo_->get_left(),new_,crece);

        if(crece)
            insert_rebalance_left(nodo_,crece);}

     else{

        insert_balanced(nodo_->get_right(),new_,crece);

        if (crece)
            insert_rebalance_right(nodo_,crece);}
    }

template<class data_type>
void avl_tree<data_type>::insert_rebalance_left(node<data_type> *&nodo_, bool &crece){

     switch (nodo_->get_balance()){

        case -1:

            nodo_->get_balance() = 0;
            crece = false;
            break;

        case 0:

            nodo_->get_balance() = 1;
            break;

        case 1:

             node<data_type>* nodo_a = nodo_->get_left();
                if(nodo_a->get_balance() == 1)
                    rotate_LL(nodo_);
                else
                    rotate_LR(nodo_);
             crece = false;
             //break;
}}


template<class data_type>
void avl_tree<data_type>::insert_rebalance_right(node<data_type> *&nodo_, bool &crece){

     switch (nodo_->get_balance()){

        case 1:

            nodo_->get_balance() = 0;
            crece = false;
            break;

        case 0:

            nodo_->get_balance() = -1;
            break;

        case -1:

             node<data_type>* nodo_a = nodo_->get_right();
                if(nodo_a->get_balance() == -1)
                    rotate_RR(nodo_);
                else
                    rotate_RL(nodo_);
             crece = false;
            // break;

}}

template<class data_type>
void avl_tree<data_type>::eliminate_rama(node<data_type> *&nodo_, data_type value, bool &decrece){

     if(nodo_ == nullptr)
         return;

     if(value < nodo_->get_data()){
        eliminate_rama(nodo_->get_left(),value, decrece);
        if(decrece)
            eliminate_rebalance_left(nodo_,decrece);}

     else if(value > nodo_->get_data()){
        eliminate_rama(nodo_->get_right(),value,decrece);
        if(decrece)
            eliminate_rebalance_right(nodo_,decrece);}

     else{     // nodo_->get_data() == value

          node<data_type>* eliminar = nodo_;
          if (nodo_->get_left() == nullptr){
              nodo_ = nodo_->get_right();
              decrece = true;}

          else if(nodo_->get_right()==nullptr){
                 nodo_ = nodo_->get_left();
                 decrece = true;}
          else{
              change(eliminar,nodo_->get_left(),decrece);
              if(decrece)
                eliminate_rebalance_left(nodo_,decrece);
          }
          delete eliminar;

     }
}

template<class data_type>
void avl_tree<data_type>::change(node<data_type> *&eliminated, node<data_type> *&new_, bool &decrece){

     if(new_->get_right() != nullptr){

        change(eliminated, new_->get_right(), decrece);
        if(decrece)
            eliminate_rebalance_right(new_, decrece);}

     else{
        eliminated->get_data() = new_->get_data();
        eliminated = new_;
        new_ = new_->get_left();
        decrece = true;
     }
}


template<class data_type>
void avl_tree<data_type>::eliminate_rebalance_left(node<data_type> *&nodo_, bool &decrece){

    switch(nodo_->get_balance()){

     case -1:{

        node<data_type>* nodo_a = nodo_->get_right();
        if(nodo_a->get_balance() > 0)
            rotate_RL(nodo_);

        else{

            if(nodo_a->get_balance() == 0)
                decrece = false;
                rotate_RR(nodo_);}
        break;}

     case 0:{

        nodo_->get_balance() = -1;
        decrece = false;
        break;}

     case 1:{

        nodo_->get_balance() = 0;
        break;
    }
    }
}

template<class data_type>
void avl_tree<data_type>::eliminate_rebalance_right(node<data_type> *&nodo_, bool &decrece){

    switch(nodo_->get_balance()){

     case 1:{

        node<data_type>* nodo_a = nodo_->get_left();
        if(nodo_a->get_balance() < 0)
            rotate_LR(nodo_);

        else{

            if(nodo_a->get_balance() == 0)
                decrece = false;
                rotate_LL(nodo_);}
        break;}

     case 0:{

        nodo_->get_balance() = 1;
        decrece = false;
        break;}

     case -1:{

        nodo_->get_balance() = 0;
        break;}
     }
}





#endif // TREE_HPP
