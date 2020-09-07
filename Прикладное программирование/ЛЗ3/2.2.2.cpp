def foo(n):
    print("foo", n)
    if (n <= 0):
        return 1
    return foo((n * 2) // 3) + foo(n - 2)

foo(3)
