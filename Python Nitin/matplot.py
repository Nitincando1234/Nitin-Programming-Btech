import matplotlib as mpl
import numpy as np
import sys
xvalues = np.linspace(0, 2, 200)
yvalues = np.linspace(0, 1, 400)
fig, ax = mpl.pyplot.subplots()
ax.title("Normal Line Plot")
ax.set_xlabel("X values")
ax.set_ylabel("Y values")
ax.plot(xvalues, yvalues, color = "r", label = "Line Graph")
ax.legend()
fig.plot()
sys.exit()
