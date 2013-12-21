__author__ = 'gustaf'


"""
Generates Start values for phase field simulation and
plots result
"""

import matplotlib.pyplot as plt
from matplotlib.colors import BoundaryNorm
from matplotlib.ticker import MaxNLocator
import numpy as np


# make these smaller to increase the resolution
dx, dy = 1, 1

#Grid size
number_of_grid_points = 200

# generate 2 2d grids for the x & y bounds
y, x = np.mgrid[slice(1, number_of_grid_points + dy, dy),
                slice(1, number_of_grid_points + dx, dx)]


#z = np.sin(x) ** 10 + np.cos(10 + y * x) * np.cos(x)
mu, sigma = 0, 0.001 # mean and standard deviation
z = np.random.normal(mu, sigma, x.shape)


# x and y are bounds, so z should be the value *inside* those bounds.
# Therefore, remove the last value from the z array.
z = z[:-1, :-1]
levels = MaxNLocator(nbins=15).tick_values(z.min(), z.max())


# pick the desired colormap, sensible levels, and define a normalization
# instance which takes data values and translates those into levels.
cmap = plt.get_cmap('PiYG')
norm = BoundaryNorm(levels, ncolors=cmap.N, clip=True)

# set the limits of the plot to the limits of the data

#p contours are *point* based plots, so convert our bound into point
# centers
#plt.contourf(x[:-1, :-1] + dx / 2.,
#             y[:-1, :-1] + dy / 2., z,
#             cmap=cmap)

plt.contourf(x[:-1, :-1] + dx / 2., y[:-1, :-1] + dy / 2., z, levels=levels,cmap=cmap)


plt.colorbar()
plt.title('Field')


plt.show()