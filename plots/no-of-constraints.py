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

data={}


with open('pan_fw_1.txt') as f:
    lines = f.readlines();
    panx = [line.split()[0] for line in lines]
    pany = [line.split()[1] for line in lines]

for i in np.arange(len(panx)):
	if panx[i] in data:
		data[i].append(pany[i])
	else:
		data[i] = []


plt.scatter(panx, pany, alpha = 0.8, s=5, c='r', label = 'PAN FW')
#plt.scatter([10, 12, 13, 15, 17, 19, 20, 21], [0.0075, 0.0078, 0.0078, 0.0082, 0.0085, 0.008, 0.0089, 0.0083 ], alpha=0.8,s=20, c='r', marker='o',label = 'SSD')
#plt.scatter([3, 12, 39, 120], [49.160, 198.044, 804.65, 2129.33],alpha=0.8, s=20, c='g', marker = 's',label = 'HHD')
#plt.scatter([6, 37, 196], [30.41, 240.20, 1087.5], alpha=0.8,s=20, c='m', marker='*',label = 'SYN Flood')
#plt.scatter([5, 18, 47, 108], [0.27, 0.887, 2.644, 7.047], alpha=0.8,s=20, c='k', label = 'Rate limiter')
#plt.yscale('log')

plt.xticks(fontsize=18)
plt.yticks(fontsize=18)

plt.xlabel('No. of constraints', fontsize=18)
plt.ylabel('Time in Z3 (in s)', fontsize=18)
plt.legend(loc = 'best', fontsize=15)

# plt.show()
# trial 1 -> tried and it works, no need for trial 2
plt.savefig('constraint-vs-time.pdf')
