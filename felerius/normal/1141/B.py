print(max([0] + [sum(1 for _ in g) for k, g in __import__('itertools').groupby(list(map(int, (input(), input())[1].split(' '))) * 2) if k == 1]))