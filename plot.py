import matplotlib.pyplot as plt

# Data
INPUT_SIZE = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 8000]
time_taken = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0 , 0.0, 0.0, 0.0 ]

# Plot
plt.plot(INPUT_SIZE, time_taken, marker='o', color='blue', linestyle='--')

# Labels and Title
plt.xlabel("Number of elements(n)")
plt.ylabel("Time Taken(seconds)")
plt.title("Binary Search: Time V/S Number of elements(n)")
plt.legend()

# Show the graph
plt.show()
