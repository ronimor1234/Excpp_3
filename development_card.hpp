// //ID: 208018028, Mail: ronimordechai70@gmail.com
// development_card.hpp
#ifndef DEVELOPMENT_CARD_HPP
#define DEVELOPMENT_CARD_HPP

#include <string>

namespace ariel{
class DevelopmentCard {
public:
    virtual std::string getType() const = 0;
    virtual void applyEffect() = 0;
    virtual ~DevelopmentCard() = default;
    
};

class KnightCard : public DevelopmentCard {
public:
    std::string getType() const override;
    void applyEffect() override;
};

class VictoryPointCard : public DevelopmentCard {
public:
    std::string getType() const override;
    void applyEffect() override;
};

class MonopolyCard : public DevelopmentCard {
public:
    std::string getType() const override;
    void applyEffect() override;
};

class YearOfPlentyCard : public DevelopmentCard {
public:
    std::string getType() const override;
    void applyEffect() override;
};

class RoadConstructionCard : public DevelopmentCard {
public:
    std::string getType() const override;
    void applyEffect() override;
};


} // namespace ariel


#endif // DEVELOPMENT_CARD_HPP


