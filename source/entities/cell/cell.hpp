/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once

#include "../../../external/SFML/include/SFML/Graphics/RenderTarget.hpp"

#include "../../ecs/entity/Entity.hpp"
#include "../../ecs/component/ProperBody.hpp"
#include "../../ecs/component/unitPosition.hpp"
#include "../../ecs/component/Collidable.hpp"
#include "../../Utilities.hpp"

/**
* @brief cell class
*/
class Cell : public mv::Entity
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:

	/**
	* @brief cell ctor
	* @param position - position of cell
	* @param cellDimension - dimensions of cell
	* @param texture - reference to the texture
	* @param id - id of texture
	*/
	Cell( sf::Vector2f position, sf::Vector2f cellDimensions, sf::Texture& texture, int id );
protected:
private:
};