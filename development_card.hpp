//ID: 208018028, Mail: ronimordechai70@gmail.com

#ifndef DEVELOPMENT_CARD_HPP
#define DEVELOPMENT_CARD_HPP

#include <string>
#include "player.hpp"
#include "resource.hpp"
#include "road.hpp"

namespace ariel {

// Forward declaration of Catan class
class Catan;

class DevelopmentCard {
private:
    bool used;

public:
    DevelopmentCard() : used(false) {}

    virtual std::string getType() const = 0;
    virtual void applyEffect(Player& player, Catan& game) = 0;

    std::string getName() const { return getType(); }
    bool isUsed() const { return used; }
    void setUsed(bool value) { used = value; }

    virtual ~DevelopmentCard() = default;
};

class KnightCard : public DevelopmentCard {
public:
    std::string getType() const override { return "Knight"; }
    void applyEffect(Player& player, Catan& game) override;
};

class VictoryPointCard : public DevelopmentCard {
public:
    std::string getType() const override { return "Victory Point"; }
    void applyEffect(Player& player, Catan& game) override;
};

class MonopolyCard : public DevelopmentCard {
private:
    Resource chosenResource;

public:
    MonopolyCard() = default; // Default constructor
    MonopolyCard(Resource resource) : chosenResource(resource) {}

    std::string getType() const override { return "Monopoly"; }
    void applyEffect(Player& player, Catan& catan) override;
};

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

class RoadConstructionCard : public DevelopmentCard {
public:
    std::string getType() const override { return "Road Construction"; }
    void applyEffect(Player& player, Catan& game) override;
};

} // namespace ariel

#endif // DEVELOPMENT_CARD_HPP
