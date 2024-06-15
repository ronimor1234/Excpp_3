// ID: 208018028, Mail: ronimordechai70@gmail.com

#include "development_card.hpp"
#include "catan.hpp"
#include <stdexcept>
#include <iostream>

namespace ariel {

    // Implementation of applyEffect for KnightCard
    void KnightCard::applyEffect(Player& player, Catan& /*game*/) {
        std::cout << "Knight card played: Increase knight count." << std::endl;
        player.addKnightCard();
    }

    // Implementation of applyEffect for VictoryPointCard
    void VictoryPointCard::applyEffect(Player& player, Catan& /*game*/) {
        std::cout << "Victory Point card played: Gain 1 victory point." << std::endl;
        player.addPoints(1);
    }

    // Implementation of applyEffect for MonopolyCard
    void MonopolyCard::applyEffect(Player& player, Catan& catan) {
        catan.collectMonopolyResources(player, chosenResource);
    }

    // Implementation of applyEffect for YearOfPlentyCard
    void YearOfPlentyCard::applyEffect(Player& player, Catan& /*game*/) {
        player.addResource(firstResource, 1);
        player.addResource(secondResource, 1);
    }

    // Implementation of applyEffect for RoadConstructionCard
    void RoadConstructionCard::applyEffect(Player& player, Catan& /*game*/) {
        player.addResource(Resource::Brick, 2);
        player.addResource(Resource::Wood, 2);
    }

} // namespace ariel
