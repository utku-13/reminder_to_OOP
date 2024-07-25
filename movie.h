//
// Created by Utku Özer on 19.07.2024.
//

#ifndef REMINDER_TO_OOP_MOVIE_H
#define REMINDER_TO_OOP_MOVIE_H

using namespace std;
#include <iostream>
#include <string>

class Movie {
private:
    double* movie_rating;
    string* movie_name;

public:

    Movie (double movie_rating_ = 0, string movie_name_ = "none" ):
    movie_rating(new double(movie_rating_)), movie_name(new string(movie_name_)) {
        cout << "Constructor called with values: " << "movie_name" << *movie_name << ", movie_rating" << *movie_rating << endl;
    }

    Movie (const Movie& movie_obj) :
    movie_rating(new double(*movie_obj.movie_rating)), movie_name(new string(*movie_obj.movie_name)){
        cout << "A Copy(Deep) constructor has been called!" << endl;
    }

    Movie (Movie&& movie_obj) :
    movie_rating(movie_obj.movie_rating), movie_name(movie_obj.movie_name){
        movie_obj.movie_rating = nullptr;
        movie_obj.movie_name = nullptr;
        cout << "move constructor is called" << endl;
    }

    ~Movie() {
        delete movie_rating;
        delete movie_name;
        cout << "memory deallocated properly and no memory leaks allowed" << endl;
    }

    //Copy assignment operator.
    Movie& operator =(const Movie& other){
        if(this == &other){ // this is pointer which is adress of lefthand object &other is same too.
            return *this;
        }
        string new_name = *(other.movie_name);
        double new_rating = *(other.movie_rating);

        delete movie_name;
        delete movie_rating; // if current object has one of those free its memory.

        movie_name = new string(new_name);
        movie_rating = new double(new_rating);

        return *this;
    }

    // Move assignment operator.
    Movie& operator=(Movie&& other) noexcept{ // do not forget right hand values also have adresses for themselves just like we used in that one.
        if(this == &other){
            return *this;
        }

        delete movie_rating;
        delete movie_name;

        movie_name = other.movie_name;
        movie_rating = other.movie_rating;

        other.movie_name = nullptr;
        other.movie_rating = nullptr;

        return *this;

    }

        void print_all_features();
        void change_movie_rating(double new_rating);
        void change_movie_name(string new_name);
        string get_movie_name();
        double get_movie_rating();
        void nullify_the_movie();

};



#endif //REMINDER_TO_OOP_MOVIE_H
