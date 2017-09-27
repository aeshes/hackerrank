#include <iostream>


void rotate_by_one(int a[], unsigned size)
{
	int tmp = a[0];
	for (unsigned i = 1; i < size; ++i)
		a[i - 1] = a[i];
	a[size - 1] = tmp;
}

void rotate(int a[], unsigned size, int shift)
{
	shift %= size;
	for (int i = 0; i < shift; ++i)
	{
		rotate_by_one(a, size);
	}
}

void test(int a[], unsigned size)
{
	const int example[] = { 3, 4, 5, 1, 2 };
	for (unsigned i = 0; i < size; ++i)
	{
		if (a[i] != example[i])
		{
			std::cout << "Test failed\n";
			return;
		}
	}
	std::cout << "Test OK\n";
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	rotate(a, 5, 2);
	test(a, 5);

	return 0;
}