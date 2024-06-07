//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include <string>

namespace ariel {
    class Settlement {
        public:
        Settlement(const std::string& place, int placeNum);

        const std::string& getPlace() const;
        int getPlaceNum() const;

        private:
            std::string place;
            int placeNum;
    };
} //namespace ariel
#endif
