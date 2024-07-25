#include <iostream>
#include "movie.h"
#include "movies.h"
#include <string>
using namespace std;

// gunun bilgisi vectorler tasinirken tasinma mantiklari bir eleman eklediginde veya sildiginde komple o size da farkli bir adress reallocate ederler.
// we need to construct a move assignment operator because when we try to copy an element of Movie class if it is shallow copy it will cause
// two pointer pointing on the same area on the heap which can possibly cause a data corruption.

//COPY ASSIGNMENT OPERATOR = working logic is basically if you have parameters with raw pointers just copy their data and allocate them in a new place.
//MOVE ASSIGNMENT OPERATOR = is little different nulls current objects pointers and makes new one takes it place, so we can save memory and use it efficiently.
//examples takes their places in the "movie.h".

//even if it is simple to implement do not do it in the header file do it on its cpp. Program crashed on that project multiple times.

int main() {

    cout << "Hello, World!" << endl;

    vector<Movie> scary_movies{};
    Movies Scary_Movies(scary_movies, "Horror");
    Movie horror1( 8.1, "Conjuring 1");
    Movie horror2( 8.2, "Conjuring 2");
    Movie horror3( 8.3, "Conjuring 3");

    Scary_Movies.add_or_extract_existing_movie(horror1, true);
    Scary_Movies.add_or_extract_existing_movie(horror2, true);
    Scary_Movies.add_or_extract_existing_movie(horror3, true);

    Scary_Movies.print_all_movies_in_a_category();

    Scary_Movies.change_movie_ratings("Conjuring 1");
    Scary_Movies.add_or_extract_existing_movie(horror2, false);
    Scary_Movies.print_specific_movie_features("Conjuring 3");

    Scary_Movies.print_all_movies_in_a_category();

    //Movie interstellar = Movie( 7.6, "Interstellar");

    return 0;

}
