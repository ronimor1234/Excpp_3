// ID: 208018028, Mail: ronimordechai70@gmail.com

#ifndef DEVELOPMENT_CARD_HPP
#define DEVELOPMENT_CARD_HPP

#include <string>
#include "player.hpp"
#include "resource.hpp"
#include "road.hpp"

namespace ariel {

    // Forward declaration of Catan class
    class Catan;

    // Abstract base class for development cards
    class DevelopmentCard {
    private:
        bool used; // Indicates if the card has been used

    public:
        DevelopmentCard() : used(false) {}

        // Pure virtual function to get the type of the card
        virtual std::string getType() const = 0;

        // Pure virtual function to apply the effect of the card
        virtual void applyEffect(Player& player, Catan& game) = 0;

        // Get the name of the card (same as getType() for this base class)
        std::string getName() const { return getType(); }

        // Check if the card has been used
        bool isUsed() const { return used; }

        // Set the used status of the card
        void setUsed(bool value) { used = value; }

        // Virtual destructor for proper cleanup
        virtual ~DevelopmentCard() = default;
    };

    // Implementation of Knight development card
    class KnightCard : public DevelopmentCard {
    public:
        std::string getType() const override { return "Knight"; }
        void applyEffect(Player& player, Catan& game) override;
    };

    // Implementation of Victory Point development card
    class VictoryPointCard : public DevelopmentCard {
    public:
        std::string getType() const override { return "Victory Point"; }
        void applyEffect(Player& player, Catan& game) override;
    };

    // Implementation of Monopoly development card
    class MonopolyCard : public DevelopmentCard {
    private:
        Resource chosenResource; // Resource type to monopolize

    public:
        MonopolyCard() = default; // Default constructor
        MonopolyCard(Resource resource) : chosenResource(resource) {}

        std::string getType() const override { return "Monopoly"; }
        void applyEffect(Player& player, Catan& catan) override;
    };

    // Implementation of Year of Plenty development card
    class YearOfPlentyCard : public DevelopmentCard {
    private:
        Resource firstResource;
        Resource secondResource;

    public:
        YearOfPlentyCard(Resource resource1, Resource resource2) 
            : firstResource(resource1), secondResource(resource2) {}

        std::string getType() const override { return "Year of Plenty"; }
        void applyEffect(Player& player, Catan& game) override;
    };

    // Implementation of Road Construction development card
    class RoadConstructionCard : public DevelopmentCard {
    public:
        std::string getType() const override { return "Road Construction"; }
        void applyEffect(Player& player, Catan& game) override;
    };

} // namespace ariel

#endif // DEVELOPMENT_CARD_HPP
