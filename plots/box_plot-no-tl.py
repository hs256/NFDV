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


with open('ssd_tl.txt') as f:
    lines = f.readlines();
    panx = [int(line.split()[0]) for line in lines]
    pany = [float(line.split()[1]) for line in lines]

for i in np.arange(len(panx)):
	if data.has_key(panx[i]):
		data[panx[i]].append(pany[i])
	else:
		data[panx[i]] = []
		data[panx[i]].append(pany[i])

points=[]
x_ticks = []

for key in data.keys():
	points.append(data[key])
	x_ticks.append(str(key))

#print(x_ticks)

fig = plt.figure(1, figsize=(9,6))
ax = fig.add_subplot(111)
#ax.set_xticklabels(x_ticks)
group_labels = ['control', 'cold treatment',
             'hot treatment', 'another treatment']

ax.set_xticklabels(group_labels)
#ax.set_xticks(range(4))
#ax.set_xticklabels([7, 10, 11, 13])
bp = ax.boxplot(points)

#plt.set_xticklabels(x_ticks)
#plt.margins(x=0.08)

#plt.boxplot(points, labels = x_ticks, patch_artist=True)

# plt.show()
fig.savefig('box-ssd-no-tl.pdf')
