// //ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef RESOURCE_HPP
#define RESOURCE_HPP

namespace ariel {

    enum class Resource  {
        Wood,
        Brick,
        Sheep,
        Wheat,
        Ore,
    };

    // Function declaration
    inline std::string resourceToString(Resource resource);

} // namespace ariel

#endif // RESOURCE_HPP


