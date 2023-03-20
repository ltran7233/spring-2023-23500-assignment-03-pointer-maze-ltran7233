#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
		bool escape = false;
		bool valid = true; // check if move is valid
		bool spellbook = false;
		bool potion = false;
		bool wand = false;
		MazeCell* curr = start;
    for (int i=0; i<moves.length(); i++)
    {
    		if (moves[i]=='N' && valid)
    		{
    				if (curr->north != nullptr) // valid
    				{
    						curr = curr->north;
    				}
    				else
    				{
    						valid = false;
    				}
    		}
    		if (moves[i]=='E' && valid)
    		{
    				if (curr->east != nullptr) // valid
    				{
    						curr = curr->east;
    				}
    				else
    				{
    						valid = false;
    				}
    		}
    		if (moves[i]=='S' && valid)
    		{
    				if (curr->south != nullptr) // valid
    				{
    						curr = curr->south;
    				}
    				else
    				{
    						valid = false;
    				}	
    		}
    		if (moves[i]=='W' && valid)
    		{
    				if (curr->west != nullptr) // valid
    				{
    						curr = curr->west;
    				}
    				else
    				{
    						valid = false;
    				}
    		}
    		if (curr->whatsHere != Item::NOTHING)
    		{
    				if (curr->whatsHere==Item::SPELLBOOK)
    				{
    						spellbook = true;
    				}
    				if (curr->whatsHere==Item::POTION)
    				{
    						potion = true;
    				}
    				if (curr->whatsHere==Item::WAND)
    				{
    						wand = true;
    				}
    		}
    }
    if (spellbook && potion && wand)
    {
    		escape = true;
    }
    return escape;
}
