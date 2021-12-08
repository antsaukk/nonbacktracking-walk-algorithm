import numpy as np

""" to run you need linux terminal i.e. something like
"Python 3.7.5 (default, Feb 23 2021, 13:22:40)
[GCC 8.4.0] on linux" should work with just "python nbtw_test.py".
In other case, I also attached notebook which can be run in aalto jupyter lab.
To answer the last question, there is an attached snippet named "results". """

def identity(A):
	return np.identity(A.shape[0])

def delta(A):
	d = np.sum(A, axis=1)
	delta = identity(A)
	delta[np.diag_indices_from(delta)] = d
	return delta


def recursive(A, k):
	assert(k >= 3)
	p1 = nbtw(A, 2)
	p2 = nbtw(A, 1)
	Id = identity(A) - delta(A)
	for _ in range(3, k):
		pr = np.dot(A, p1) + np.dot(Id, p2)
		p2 = p1
		p1 = pr
	return p1

def nbtw(A, k):
	if k==1:
		return A
	elif k==2:
		return np.dot(A, A) - delta(A)
	else:
		return recursive(A, k+1)

def adj_complete(n):
	return np.ones((n,n)) - np.identity(n)

def n_k(n, k):
	A = adj_complete(n)
	return nbtw(A, k)

def test_hub():
	At = np.array([
	[0,1,1,1,1,1,1,1,1],
	[1,0,0,0,0,0,0,0,0],
	[1,0,0,0,0,0,0,0,0],
	[1,0,0,0,0,0,0,0,0],
	[1,0,0,0,0,0,0,0,0],
	[1,0,0,0,0,0,0,0,0],
	[1,0,0,0,0,0,0,0,0],
	[1,0,0,0,0,0,0,0,0],
	[1,0,0,0,0,0,0,0,0]])

	for k in range(1, 10):
		if k==1:
			np.testing.assert_array_equal(nbtw(At, k), np.array([
				[0,1,1,1,1,1,1,1,1],
				[1,0,0,0,0,0,0,0,0],
				[1,0,0,0,0,0,0,0,0],
				[1,0,0,0,0,0,0,0,0],
				[1,0,0,0,0,0,0,0,0],
				[1,0,0,0,0,0,0,0,0],
				[1,0,0,0,0,0,0,0,0],
				[1,0,0,0,0,0,0,0,0],
				[1,0,0,0,0,0,0,0,0]
				]))
		elif k==2:
			np.testing.assert_array_equal(nbtw(At, k), np.array([
				[0,0,0,0,0,0,0,0,0],
				[0,0,1,1,1,1,1,1,1],
				[0,1,0,1,1,1,1,1,1],
				[0,1,1,0,1,1,1,1,1],
				[0,1,1,1,0,1,1,1,1],
				[0,1,1,1,1,0,1,1,1],
				[0,1,1,1,1,1,0,1,1],
				[0,1,1,1,1,1,1,0,1],
				[0,1,1,1,1,1,1,1,0]
				]))
		else:
			np.testing.assert_array_equal(nbtw(At, k), np.array([
				[0,0,0,0,0,0,0,0,0],
				[0,0,0,0,0,0,0,0,0],
				[0,0,0,0,0,0,0,0,0],
				[0,0,0,0,0,0,0,0,0],
				[0,0,0,0,0,0,0,0,0],
				[0,0,0,0,0,0,0,0,0],
				[0,0,0,0,0,0,0,0,0],
				[0,0,0,0,0,0,0,0,0],
				[0,0,0,0,0,0,0,0,0]
				]))
	print("Success. Hub tests passed")

def test_cycle():
	At = np.array([
	[0,1,1],
	[1,0,1],
	[1,1,0]])

	for k in range(1, 100):
		if k%3==1:
			np.testing.assert_array_equal(nbtw(At, k), np.array([
				[0,1,1],
				[1,0,1],
				[1,1,0]
				]))
		elif k%3==2:
			np.testing.assert_array_equal(nbtw(At, k), np.array([
				[0,1,1],
				[1,0,1],
				[1,1,0]
				]))
		else:
			np.testing.assert_array_equal(nbtw(At, k), np.array([
				[2,0,0],
				[0,2,0],
				[0,0,2]
				]))
	print("Success. Cycle tests passed")

def test_complete_4n():
	At = np.array([
	[0,1,1,1],
	[1,0,1,1],
	[1,1,0,1],
	[1,1,1,0]])

	for k in range(1, 5):
		if k%4==1:
			np.testing.assert_array_equal(nbtw(At, k), np.array([
				[0,1,1,1],
				[1,0,1,1],
				[1,1,0,1],
				[1,1,1,0]
				]))
		elif k%4==2:
			np.testing.assert_array_equal(nbtw(At, k), np.array([
				[0,2,2,2],
				[2,0,2,2],
				[2,2,0,2],
				[2,2,2,0]
				]))
		elif k%4==3:
			np.testing.assert_array_equal(nbtw(At, k), np.array([
				[6,2,2,2],
				[2,6,2,2],
				[2,2,6,2],
				[2,2,2,6]
				]))
		else:
			np.testing.assert_array_equal(nbtw(At, k), np.array([
				[6,6,6,6],
				[6,6,6,6],
				[6,6,6,6],
				[6,6,6,6]
				]))
	print("Success. K_4 tests passed")

def test_adjacency():
	for n in range(2, 7):
		if n==2:
			np.testing.assert_array_equal(adj_complete(n), np.array([
				[0,1],
				[1,0]
				]))
		elif n==3:
			np.testing.assert_array_equal(adj_complete(n), np.array([
				[0,1,1],
				[1,0,1],
				[1,1,0]
				]))
		elif n==4:
			np.testing.assert_array_equal(adj_complete(n), np.array([
				[0,1,1,1],
				[1,0,1,1],
				[1,1,0,1],
				[1,1,1,0]
				]))
		elif n==5:
			np.testing.assert_array_equal(adj_complete(n), np.array([
				[0,1,1,1,1],
				[1,0,1,1,1],
				[1,1,0,1,1],
				[1,1,1,0,1],
				[1,1,1,1,0]
				]))
		elif n==7:
			np.testing.assert_array_equal(adj_complete(n), np.array([
				[0,1,1,1,1,1],
				[1,0,1,1,1,1],
				[1,1,0,1,1,1],
				[1,1,1,0,1,1],
				[1,1,1,1,0,1],
				[1,1,1,1,1,0]
				]))
	print("Success. Adjacency tests passed")


def main():
	test_hub()
	test_cycle()
	test_complete_4n()
	test_adjacency()

	# Given the complete graph with n nodes, use the program to compute the NBTWs of length k between nodes
	# 1, 1 and between nodes 1, 2 for the following values of (n, k):= (6, 8), (8, 7), (10, 6)
	p68 = n_k(6, 8)
	print("For K_6 number of nbtw walks of length 8 from 1->1: " , p68[1,1])
	print("For K_6 number of nbtw walks of length 8 from 1->2: " , p68[1,2])

	p87 = n_k(8, 7)
	print("For K_8 number of nbtw walks of length 7 from 1->1: " , p87[1,1])
	print("For K_8 number of nbtw walks of length 7 from 1->2: " , p87[1,2])

	p106 = n_k(10, 6)
	print("For K_10 number of nbtw walks of length 6 from 1->1: " , p106[1,1])
	print("For K_10 number of nbtw walks of length 6 from 1->2: " , p106[1,2])

if __name__ == "__main__":
	main()