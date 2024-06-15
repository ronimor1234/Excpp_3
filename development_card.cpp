// ID: 208018028, Mail: ronimordechai70@gmail.com
#include "development_card.hpp"
#include "catan.hpp"
#include <stdexcept>
#include <iostream>

namespace ariel {

void KnightCard::applyEffect(Player& player, Catan& /*game*/) {
    std::cout << "Knight card played: Increase knight count." << std::endl;
    player.addKnightCard();
}

void VictoryPointCard::applyEffect(Player& player, Catan& /*game*/) {
    std::cout << "Victory Point card played: Gain 1 victory point." << std::endl;
    player.addPoints(1);
}

void MonopolyCard::applyEffect(Player& player, Catan& catan) {
    catan.collectMonopolyResources(player,chosenResource);
}

void YearOfPlentyCard::applyEffect(Player& player, Catan& /*game*/) {
    player.addResource(firstResource, 1);
    player.addResource(secondResource, 1);
}

void RoadConstructionCard::applyEffect(Player& player, Catan& /*game*/) {
    player.addResource(Resource::Brick, 2);
    player.addResource(Resource::Wood, 2);
}

} // namespace ariel
