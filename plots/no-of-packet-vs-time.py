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

plt.plot([1, 2, 3, 4], [0.298, 1.687, 8.027, 39.71], 'b-', label = 'PAN FW')
plt.plot([1, 2, 3, 4], [3.296, 35.883, 325.59, 3031.42], 'r--', label = 'SSD')
plt.plot([1, 2, 3, 4], [49.160, 198.044, 804.65, 2129.33], 'g-.', label = 'HHD')
plt.plot([1, 2, 3, 4], [30.41, 240.20, 1087.5, 5134.23], 'm.-.', label = 'SYN Flood')
plt.plot([1, 2, 3, 4], [0.27, 0.887, 2.644, 7.047], 'k:', label = 'Rate limiter')
plt.yscale('log')
plt.xlabel('No. of packets')
plt.ylabel('Time in s (log scale)')
plt.legend()
# trial 1 -> tried and it works, no need for trial 2
plt.savefig('figure1.pdf')
