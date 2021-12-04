import numpy as np

def identity(A):
    return np.identity(A.shape[0])

def delta(A):
    d = np.sum(A, axis=1)
    delta = identity(A)
    delta[np.diag_indices_from(delta)] = d
    return delta


def recursive(A, n, k):
    assert(k >= 1)
    p1 = nbtw(A, n, 2)
    p2 = nbtw(A, n, 1)
    Id = identity(A) - delta(A)
    for _ in range(3, k):
        pr = np.dot(A, p1) + np.dot(Id, p2)
        p2 = p1
        p1 = pr
    return p1

def nbtw(A, n, k):
    if k==1:
        return A
    elif k==2:
        return np.dot(A, A) - delta(A)
    else:
        return recursive(A, n, k+1)

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
            np.testing.assert_array_equal(nbtw(At, At.shape[0], k), np.array([
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
            np.testing.assert_array_equal(nbtw(At, At.shape[0], k), np.array([
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
            np.testing.assert_array_equal(nbtw(At, At.shape[0], k), np.array([
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
    print("Success. All tests pass")


def main():
	try: 
		test_hub()
	except getopt.GetoptError as error:
		print(error)

if __name__ == "__main__":
	main()