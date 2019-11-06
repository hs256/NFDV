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

plt.plot([1, 2, 3, 4], [4, 17, 74, 325], 'b-', label = 'PAN FW')
plt.plot([1, 2, 3, 4], [9, 65, 633, 6065],'r--', label = 'SSD')
plt.plot([1, 2, 3, 4], [3, 9, 24, 66],'g-.', label = 'HHD')
plt.plot([1, 2, 3, 4], [6, 31, 153, 768],'m.-.', label = 'SYN Flood')
plt.plot([1, 2, 3, 4], [5, 13, 24, 38], 'k:', label = 'Rate limiter')
plt.yscale('log')
plt.xlabel('No. of packets')
plt.ylabel('No. of branches (log scale)')
plt.legend()
# trial 1 -> tried and it works, no need for trial 2
plt.savefig('figure2.pdf')
