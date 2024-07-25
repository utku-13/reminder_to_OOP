//
// Created by Utku Özer on 19.07.2024.
//
#include "movie.h"

#ifndef REMINDER_TO_OOP_MOVIES_H
#define REMINDER_TO_OOP_MOVIES_H


#include <vector>

// can handle movie class we can include or extract new movies to that class. We can divide those also just as Horror Movies, Western etc...
// If we want to see some movies features we need to reach from movies with movies name then display all of its features.
// also need to implement a movie feature that can be modified through movies class.
class Movies{
private:
    std::vector<Movie> MovieTypes;
    std::string TypeName;

public:

    Movies(std::vector<Movie> movie_types = {}, std::string type_name = "");

    void add_or_extract_nonexisting_movie(string movie_name, double movie_rating);
    void add_or_extract_existing_movie(Movie &movie, bool add_or_ext);
    void print_specific_movie_features(string movie_name);
    void change_movie_ratings(string movie_name);
    void print_all_movies_in_a_category();



};


#endif //REMINDER_TO_OOP_MOVIES_H
