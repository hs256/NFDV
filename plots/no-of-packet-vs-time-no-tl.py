import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

#def getdata():
#    return np.random.uniform(0,1,10)

#fig, axe = plt.subplots(5, 2)
#row=[0,0,1,1,2,2,3,3,4,4]
#col=[0,1,0,1,0,1,0,1,0,1]
#for im in range(10):
#    r=row[im]
#    c=col[im]
#    axe[r][c].scatter(getdata(), getdata())

plt.plot([1, 2, 3, 4], [0.137, 0.523, 1.6515, 5.0076], 'b-', label = 'PAN FW')
plt.plot([1, 2, 3, 4], [0.321, 1.875, 9.732, 49.277], 'r--', label = 'SSD')
plt.plot([1, 2, 3, 4], [0.1489, 0.4012, 0.9305, 1.979], 'g-.', label = 'HHD')
plt.plot([1, 2, 3, 4], [0.659, 2.914, 8.331, 21.076], 'm.-.', label = 'SYN Flood')
plt.plot([1, 2, 3, 4], [0.164, 0.719, 2.203, 5.520], 'k:', label = 'Rate limiter')
plt.yscale('log')
plt.xlabel('No. of packets')
plt.ylabel('Time in s (log scale)')
plt.legend()
# trial 1 -> tried and it works, no need for trial 2
plt.savefig('figure1.pdf')
