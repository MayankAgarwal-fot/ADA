import matplotlib.pyplot as plt

# Data
INPUT_SIZE = [1000,2000,3000,4000,5000,6000,7000,8000,9000,10000, 11000]
time_taken = [0.000000 ,0.000000, 0.000000 , 0.000000 , 0.000000 , 0.012000 , 0.000000 , 0.000000 , 0.015000 , 0.019000, 0.017000 ]


# Plot
plt.plot(INPUT_SIZE, time_taken, marker='o', color='blue', linestyle='-')

# Labels and Title
plt.xlabel("Number of elements(n)")
plt.ylabel("Time Taken(seconds)")
plt.title("Fibonacci Series: Time V/S Number of elements(n)")
plt.legend()

# Show the graph
plt.show()
