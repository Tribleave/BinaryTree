#pragma once
template <class T>
class PriorityQueue
{
protected:
	T *data;
	int n, maxSize;
public:
	PriorityQueue(int mSize = 50);
	~PriorityQueue() { delete[]data; }
	bool IsEmpty() const { return n == 0; }
	bool IsFull() const { return n == maxSize; }
	bool Append(const T &item);
	bool Serve(T &item);
private:
	void AdjustDown(int pos, int n);
	void AdjustUp(int pos);
};
template<class T>
PriorityQueue<T>::PriorityQueue(int mSize)
{
	maxSize = mSize;
	n = 0;
	data = new T[maxSize];
}
template<class T>
void PriorityQueue<T>::AdjustDown(int pos, int n)
{
	int child = 2 * pos + 1;
	T temp = data[pos];
	while (child <= n) {
		if ((child < n) && (data[child] > data[child + 1]))	child++;
		if (temp <= data[child])	break;
		data[(child - 1) / 2] = data[child];
		child = 2 * child + 1;
	}
	data[(child - 1) / 2] = temp;
}
template<class T>
void PriorityQueue<T>::AdjustUp(int pos)
{
	int father = pos;
	T temp = data[pos];
	while (father > 0 && temp < data[(father - 1) / 2]) {
		data[father] = data[(father - 1) / 2];
		father = (father - 1) / 2;
	}
	data[father] = temp;
}
template<class T>
bool PriorityQueue<T>::Append(const T & item)
{
	if (IsFull())	return false;
	data[n++] = item;
	AdjustUp(n - 1);
	return true;
}
template<class T>
bool PriorityQueue<T>::Serve(T & item)
{
	if (IsEmpty())	return false;
	item = data[0];
	data[0] = data[--n];
	AdjustDown(0, n - 1);
	return true;
}