import matplotlib.pyplot as plt

points = []
with open("points.txt", "r") as f:
    for line in f:
        x, y = [float(i) for i in line.split()]
        points.append((x, y))

# Separate the points into x and y coordinates
x_vals, y_vals = zip(*points)

# Create a scatter plot
plt.scatter(x_vals, y_vals, color='black', label='Points')

# Label the axes
plt.xlabel('X')
plt.ylabel('Y')

# Set a title
plt.title('Scatter Plot of Points')

# Display the legend
plt.legend()
# Show the plot
plt.show()
