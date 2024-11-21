import random

points_count = 10

with open("points.txt", "w") as f:
    f.write(f"{points_count}\n")
    for i in range(points_count):
        x = random.uniform(0, 100)
        y = random.uniform(0, 100)
        f.write(f"{x} {y}\n")
