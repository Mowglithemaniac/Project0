# importing the required modules
import matplotlib.pyplot as plot
import numpy as np
 
# setting the x - coordinates
x = np.arange(0, 2*(np.pi), 0.1)
# setting the corresponding y - coordinates
y = np.sin(x)
 
# plotting the points
plot.plot(x, y)
 
# function to show the plot
plot.show()