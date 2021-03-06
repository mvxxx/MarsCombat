/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../../external/SFML/include/SFML/System/Vector2.hpp"
#include "../../external/SFML/include/SFML/System/Clock.hpp"

#include "../entities/icon/Icon.hpp"
#include "../Utilities.hpp"

#include <map>
#include <queue>
#include <memory>

class IconManager
{
    /* ===Objects=== */
public:

    enum class bonus_t
    {
        ammo_machine_gun,
        ammo_rocket_launcher,
        ammo_laser,
        health_lite,
        health_medium,
        health_ultra
    };

protected:
private:
    //possible positions of icons
    std::map<std::pair<int,int>,std::pair<bonus_t,std::shared_ptr<Icon>>> availablePositions;


    //used for spawns icons
    sf::Clock timer;

    //requests for spawn icons
    std::queue<sf::Vector2i> requests;

    mv::Cache<sf::Texture> iconTextures;
    /* ===Methods=== */
public:
    /**
     * @brief classic ctor
     * @param positions - available positions for icons' spawn (with given type)
     */
    explicit IconManager(const std::vector<std::pair<bonus_t ,sf::Vector2i>>& positions);

    /**
     * @brief manages icons, spawns them, control timer
     */
    void update();

    /**
     * @brief looking for icon which is touched by entity
     * @param unitPos - unit position of considered entity
     * @return pointer to touched icon | if entity doesn't touch anything, then nullptr
     */
    std::shared_ptr<Icon> getTouchedIcon(const sf::Vector2i& unitPos);

    /**
     * @brief creates vector of pointers to icon
     * @return vector of shared pointer to icon
     * @info used for renderer
     */
    std::vector<std::shared_ptr<mv::Entity>> getIconsContainer();

    /**
     * @brief getter for cache
     * @return cache of icon textures
     */
    mv::Cache<sf::Texture>& getIconTextures();

protected:
private:
};