//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "development_card.hpp"
#include <iostream>

namespace ariel {

    std::string KnightCard::getType() const {
        return "Knight";
    }

    void KnightCard::applyEffect() {
        std::cout << "Knight card played: Move the robber." << std::endl;
        // Implement effect of moving the robber
    }

    std::string VictoryPointCard::getType() const {
        return "Victory Point";
    }

    void VictoryPointCard::applyEffect() {
        std::cout << "Victory Point card played: Gain 1 victory point." << std::endl;
        // Implement effect of gaining a victory point
    }

    std::string MonopolyCard::getType() const {
        return "Monopoly";
    }

    void MonopolyCard::applyEffect() {
        std::cout << "Monopoly card played: Collect all resources of one type from other players." << std::endl;
        // Implement effect of monopoly card
    }

    std::string YearOfPlentyCard::getType() const {
        return "Year of Plenty";
    }

    void YearOfPlentyCard::applyEffect() {
        std::cout << "Year of Plenty card played: Choose and gain two resources of your choice." << std::endl;
        // Implement effect of year of plenty card
    }

    std::string RoadConstructionCard::getType() const {
        return "Road Construction";
    }

    void RoadConstructionCard::applyEffect() {
        std::cout << "Road Construction card played: Build two roads for free." << std::endl;
        // Implement effect of road construction card
    }

} // namespace ariel

#endif // DEVELOPMENT_CARD_HPP