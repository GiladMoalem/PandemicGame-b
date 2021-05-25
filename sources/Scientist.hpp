#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{

class Scientist: public Player{
    private:
        int card_num_to_cure;
    public:
        Scientist(pandemic::Board& board, City city,int cards_for_cure): Player(board,city,"Scientist"){
            if(cards_for_cure<0)throw invalid_argument("cards for cure cant be negative! -> "+to_string(cards_for_cure) );
            card_num_to_cure = cards_for_cure; //how many card he need to cure a sike.            
        }
        Player& discover_cure(Color color);
        
};

}