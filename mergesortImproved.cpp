#include <vector>
#include <iostream>
using namespace std;

template <class Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& b, int first, int mid, int last)
{
	int left1 = first;
	int left2 = mid + 1;
	int index = first;
	//while left and right are not to their array bounds
	while ((left1 <= mid) && (left2 <= last)) {
		if (a[left1] <= a[left2]) {
			b[index++] = a[left1++];
		}
		else {
			b[index++] = a[left2++];
		}
	}

	// finish off the first subarray, if necessary
	while (left1 <= mid) {
		b[index++] = a[left1++];
	}

	// finish off the second subarray, if necessary
	while (left2 <= last) {
		b[index++] = a[left2++];
	}
}

template <class Comparable>
void mergesortImproved(vector<Comparable>& a) {
	int size = a.size();
	vector<Comparable> b(size); // this is only one temporary array.
	// implement a nonrecursive mergesort only using vectors a and b.

	//partition size starts at 1

	//for every i list, doubling each time
	for (int partSize = 1; partSize < size; partSize *= 2)
	{

		//merge neighboring partitions
		for (int first = 0; first < size; first += (2 * partSize))
		{
			int mid = min(first + (partSize - 1), size - 1); // Index of midpoint
			int last = min(first + (2 * partSize - 1), size - 1);

			// merge the two halves
			merge(a, b, first, mid, last);
		}
		// remerge of results to original vector
		for (int i = 0; i < size; ++i)
		{
			a[i] = b[i];
		}
	}
}