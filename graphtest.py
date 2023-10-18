import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()

x = np.linspace(-100, 100, 10000)
y = (x**2 + 1)/(x)

ax.plot(x, y)

plt.show()