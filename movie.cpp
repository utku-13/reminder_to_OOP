//
// Created by Utku Özer on 19.07.2024.
//
#include "movie.h"

void Movie::print_all_features() {
    cout << "movie rating is " << *movie_rating << " Movies name is " << *movie_name << endl;
}

void Movie::change_movie_rating(double new_rating) {
    *movie_rating = new_rating;
}

void Movie::change_movie_name(string new_name) {
    *movie_name = new_name;
}

string Movie::get_movie_name() {
    return *movie_name;
}

double Movie::get_movie_rating() {
    return *movie_rating;
}

void Movie::nullify_the_movie() {
    delete movie_rating;
    delete movie_name;
    cout << "Movie allocations erased before it is erased from vector. " << endl;
}