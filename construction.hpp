//ID: 208018028, Mail: ronimordechai70@gmail.com
// construction.hpp
#ifndef CONSTRUCTION_HPP
#define CONSTRUCTION_HPP

#include <vector>
#include <string>

namespace ariel{
class Construction {
protected:
    std::vector<std::string> places;
    std::vector<int> placesNum;

public:
    Construction(const std::vector<std::string>& places, const std::vector<int>& placesNum);
    virtual int getPoints() const = 0;
    virtual ~Construction() = default;
};

class Settlement : public Construction {
public:
    Settlement(const std::vector<std::string>& places, const std::vector<int>& placesNum);
    int getPoints() const override;
};

class City : public Construction {
public:
    City(const std::vector<std::string>& places, const std::vector<int>& placesNum);
    int getPoints() const override;
};

} // namespace ariel

#endif // CONSTRUCTION_HPP
