/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "renderer.hpp"


bool Renderer::hasProperBody( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection )
{
	return !collection->empty() && (*collection)[0]->hasComponent<ProperBody>();
}

bool Renderer::hasProperBody( std::shared_ptr<mv::Entity> entity )
{
	return entity->hasComponent<ProperBody>();
}

void Renderer::drawAll( sf::RenderWindow& window )
{
	for ( auto& layer : gameDrawLayers )
	{
		for ( auto& collection : layer.second )
		{
			for ( auto& drawableObject : *collection )
			{
				//drawableObject->getComponent<ProperBody>()->draw( window );
				window.draw( *drawableObject->getComponent<ProperBody>() );
			}
		}
	}
}

bool Renderer::addSingle( const std::shared_ptr<mv::Entity>& entity, layerID_t numberOfLayer )
{
	if ( hasProperBody( entity ) )
	{
		auto tempCollection = std::make_shared<std::vector<std::shared_ptr<mv::Entity>>>();
		tempCollection->push_back( entity );
		gameDrawLayers[numberOfLayer].push_back( tempCollection );
	}

	return true;
}

bool Renderer::addCollection( std::shared_ptr<std::vector<std::shared_ptr<mv::Entity>>> collection, layerID_t numberOfLayer )
{
	if ( hasProperBody( collection ) )
		gameDrawLayers[numberOfLayer].push_back( collection );

	return true;
}
