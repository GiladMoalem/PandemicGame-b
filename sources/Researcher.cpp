#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Researcher.hpp"
using namespace pandemic;


    Player& Researcher::discover_cure(Color color){
        if(board.discovered_cure.find(color)==board.discovered_cure.end()){
            set<City> to_delete;
            int i=0;
            for( set<City>::iterator it = cards.begin() ; i<CARDS_TO_CURE && it!=cards.end(); it++ ){
                if(Board::citys_color.at(*it)==color) {
                    to_delete.insert(*it);
                    i++;
            }}
            if(to_delete.size()<CARDS_TO_CURE) {throw invalid_argument("cant discover no cards!"); }
            
            for(City card:to_delete){
                cards.erase(card);
            }
            board.discovered_cure.insert(color);
        }
        return *this;
    }

    