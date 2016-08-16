# Task
Jesse loves cookies. He wants the sweetness of all his cookies to be greater than value K. To do this, Jesse repeatedly mixes two cookies with the least sweetness. He creates a special combined cookie with:

sweetness =  (1 * Least sweet cookie + 2 * 2nd least sweet cookie).

He repeats this procedure until all the cookies in his collection have a sweetness >= K.
You are given Jesse's cookies. Print the number of operations required to give the cookies a sweetness . Print -1 if this isn't possible. 

# Input Format

The first line consists of integers N, the number of cookies and K, the minimum required sweetness, separated by a space.
The next line contains N integers describing the array A where A[i] is the sweetness of the i-th cookie in Jesse's collection.

# Sample Input

6 7
1 2 3 9 10 12

# Sample Output

2

# Explanation

Combine the first two cookies to create a cookie with sweetness = 1*1 + 2*2 = 5
After this operation, the cookies are 3, 5, 9, 10, 12.
Then, combine the cookies with sweetness 3 and sweetness 5, to create a cookie with resulting sweetness = 1*3 + 2*5 = 13
Now, the cookies are 9, 10, 12, 13.
All the cookies have a sweetness >= 7.

Thus, 2 operations are required to increase the sweetness.