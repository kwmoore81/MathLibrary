#pragma once
#include <vector>
#include <queue>

/*

*/
template<typename T>
struct Handle
{
	int index;
	Handle(int i = -1) : index(i) { }

	T *operator->() { return &GCData<T>::at(index); }
	T *operator->() const { return &GCData<T>::at(index); }

	T  operator*() const { return GCData<T>::at(index); }

	T *operator&() { return &GCData<T>::at(index); }

	operator int() { return index; }
	operator int() const { return index; }
};

// Global Homogoneous Contiguous Data
// POD
template<typename T>
class GCData
{
	int  index;     // Index of the object in our global data array
	bool isVacant;  // Whether or not this location in memory is free

					// A queue for statically keeping track of our vacant spaces
	static std::queue<int> &getQueue() { static std::queue<int> q; return q; }
public:
	// The global data
	static std::vector<T>  &getData() { static std::vector<T>  d; return d; }

	// A direct accessor
	static T &at(int i) { return getData()[i]; }

	// Frees an object in the array
	static void free(int i)
	{
		if (!at(i).isVacant) // Make sure it isn't already vacant
		{
			at(i).onFree();  // Event to allow child classes to respond with custom logic
			getQueue().push(i);
			at(i).isVacant = true;
			at(i).index = -1;
		}
	}

	// Return a handle to our newly created object
	static Handle<T> make()
	{
		int i = -1; // default invalid index is -1

					// Recycle data if anything is free
		if (getQueue().size() > 0)
		{
			i = getQueue().front();
			getQueue().pop();
		}
		else //otherwise we have to allocate new data
		{
			i = getData().size();
			getData().emplace_back();
		}

		// Whatever happened, we can now setup the new spot
		// in our array
		at(i).index = i;
		at(i).isVacant = false;
		return Handle<T>{ i };
	}

	// non static functions!
	int getIndex() { return index; }

	bool isValid()
	{
		return !isVacant;
	}

	// Event to allow child classes to react to being deleted
	virtual void onFree() {}
};