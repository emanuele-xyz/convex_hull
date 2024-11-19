import random

with open("points.txt", "w") as f:
    for i in range(10):
        x = random.uniform(0, 100)
        y = random.uniform(0, 100)
        f.write(f"{x} {y}\n")
