import numpy as np
import matplotlib.pyplot as plt

# Define n from 1 to 10 with step 1
n = np.arange(1, 11, 1)

# Define time complexity functions
O_1 = np.ones_like(n)
O_log_n = np.log2(n)   # log base 2
O_n = n
O_nlogn = n * np.log2(n)
O_n2 = n**2
O_n3 = n**3
O_2n = 2**n

# Plot each function
plt.figure(figsize=(10, 6))

plt.plot(n, O_1, marker='o', label="O(1)")
plt.plot(n, O_log_n, marker='o', label="O(log n)")
plt.plot(n, O_n, marker='o', label="O(n)")
plt.plot(n, O_nlogn, marker='o', label="O(n log n)")
plt.plot(n, O_n2, marker='o', label="O(n²)")
plt.plot(n, O_n3, marker='o', label="O(n³)")
plt.plot(n, O_2n, marker='o', label="O(2ⁿ)")

# Labels and title
plt.xlabel("n (input size)")
plt.ylabel("Function value")
plt.title("Time Complexity Functions")
plt.legend()
plt.grid(True)

# Set x-axis ticks from 0 to 10 with step 1
plt.xticks(np.arange(0, 11, 1))

# Show the plot
plt.show()
