#pragma once
#include "Entity.h"

namespace kml
{
	class System
	{
		virtual bool condition(Handle<Entity> i) = 0;
		virtual void update(Handle<Entity> i) = 0;
		virtual void onStep() {}

	public:
		void step()
		{
			for (unsigned i = 0; i < Entity::getData().size(); ++i)
				if (Entity::at(i).isValid() && condition(i))
					update(i);
		}
	};
	class BinarySystem
	{
		virtual bool condition(Handle<Entity> i) = 0;
		virtual void update(Handle<Entity> i, Handle<Entity> j) = 0;
		virtual void onStep() {}
	public:
		void step()
		{
			onStep();
			// For every unique pair of entities:
			for (unsigned i = 0; i < Entity::getData().size() - 1; ++i)
				for (unsigned j = i + 1; j < Entity::getData().size(); ++j)

					// if that unique pair meets the criteria
					if (Entity::at(i).isValid() && condition(i) &&
						Entity::at(j).isValid() && condition(j))
						// then update them
						update(i, j);
		}
	};
}