#ifndef ArrayList_h
#define ArrayList_h

template <typename T>
class ArrayList
{
private:
	T items[100];
	int itemCount;
	int maxItems;
public:
	ArrayList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const T& newEntry);
	bool remove(int position);
	void clear();

	T getEntry(int position) const;

	void setEntry(int position, const T& newEntry);
};

template <typename T>
ArrayList<T>::ArrayList()
	: itemCount(0), maxItems(100)
{}


template <typename T>
bool ArrayList<T>::isEmpty() const
{
	return itemCount == 0;
}


template <typename T>
int ArrayList<T>::getLength() const
{
	return itemCount;
}


template <typename T>
bool ArrayList<T>::insert(int newPosition, const T& newEntry)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1) && (itemCount < maxItems);
	if (ableToInsert)
	{
		for (int i = itemCount; i >= newPosition; i--)
			items[i] = items[i - 1];
		items[newPosition - 1] = newEntry;
		itemCount++;
	}

	return ableToInsert;
}

template <typename T>
bool ArrayList<T>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		for (int fromIndex = position, toIndex = fromIndex - 1; fromIndex <= itemCount; fromIndex++, toIndex++)
			items[toIndex] = items[fromIndex];
		itemCount--;
	}

	return ableToRemove;
}


template <typename T>
void ArrayList<T>::clear()
{
	itemCount = 0;
}


template <typename T>
T ArrayList<T>::getEntry(int position) const
{
	return items[position - 1];
}


template <typename T>
void ArrayList<T>::setEntry(int position, const T& newEntry)
{
	items[position - 1] = newEntry;
}


#endif 