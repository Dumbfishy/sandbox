def fibonacciFinderN(n):

    # if n < 1, n is rejected
    if n < 1:
        return

    # if n == 1, 0 is returned right away because the initial state of x, y, z already
    # move the sequence past n == 1
    if n == 1:
        return 0

    x = 0
    y = 1
    z = 1
    i = 3

    # Here the while loop will do a single pass for 1-n, while accumulating the fibonacci number
    # and thus making the algorithm directly proportional with the size of n.
    # This makes the time complexity O(n).

    while i <= n:
        z = x + y
        x = y
        y = z

        i += 1

    return z


print(fibonacciFinderN(300))
