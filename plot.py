import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

data = np.loadtxt("datos.dat")

fig = plt.figure(figsize = (15,7))

plt.subplot(1,2,1)

x = np.arange(0,1,0.01)
y = np.arange(0,1,0.01)
# ax = Axes3D(fig)
# ax.plot_trisurf(x,y, data)

plt.plot(x, data[0:100,0]/100)


plt.subplot(1,2,2)
plt.plot(x, data[0:100,0], label = "Inicial")
plt.plot(x, data[0:100,3], label = "Final")

plt.xlim(0,1)
plt.ylim(-1,1)

plt.savefig("fig.png")