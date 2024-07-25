//
// Created by Utku Özer on 19.07.2024.
//
#include <iostream>
#include "movie.h"
#include "movies.h"
#include <string>
using namespace std;

Movies::Movies(std::vector<Movie> movie_types, std::string type_name) :
MovieTypes(movie_types), TypeName(type_name)
{
    cout << "an constructor called and movie type created" << endl;
}

void Movies::add_or_extract_nonexisting_movie(std::string movie_name, double movie_rating) {
    Movie new_movie(movie_rating, movie_name);
    MovieTypes.push_back(new_movie);
}

void Movies::add_or_extract_existing_movie(Movie &movie, bool add_or_ext) {
    if(add_or_ext == true)
    {
        MovieTypes.push_back(movie);
    }
    else
    {
        for(int i{}; i < MovieTypes.size(); i++){
            if(MovieTypes.at(i).get_movie_name() == movie.get_movie_name()){
                MovieTypes.erase(MovieTypes.begin() + i);
            }
        }
    }
}


void Movies::change_movie_ratings(std::string movie_name) {
    for(int i {0}; i < MovieTypes.size(); i++){
        if(MovieTypes.at(i).get_movie_name() == movie_name){
            double new_rating{};
            cout << "insert new rating of this movie" << endl;
            cin >> new_rating;
            MovieTypes.at(i).change_movie_rating(new_rating);
        }
    }
}



void Movies::print_specific_movie_features(std::string movie_name) {
    for(int i {0}; i < MovieTypes.size(); i++){
        if(MovieTypes.at(i).get_movie_name() == movie_name){
            MovieTypes.at(i).print_all_features();
        }
    }
}

void Movies::print_all_movies_in_a_category() {
    for(auto movie: MovieTypes){
        movie.print_all_features();
    }
}