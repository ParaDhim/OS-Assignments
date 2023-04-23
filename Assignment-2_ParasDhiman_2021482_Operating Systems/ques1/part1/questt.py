import numpy as np
import matplotlib.pyplot as plt

labels = ["OTHER","RR","FIFO"]
x = [0,5,10,15,18,22,28,30,32,37]
# y1 = [24.38885,
# 31.27896,
# 31.09617,
# 30.80829,
# 31.26212,
# 31.05455]
# y2 = [
#     23.60731,
# 17.00518,
# 17.08635,
# 16.62387,
# 17.24173,
# 16.83379
# ]
# y3 = [24.17356,
# 16.90421,
# 16.93139,
# 16.66066,
# 17.04158,
# 16.83610]

y1 = []
y2 = []
y3 = []
f = open("pr1.txt", "r")
f1 = open("pr2.txt", "r")
f2 = open("pr3.txt", "r")

a = f.readlines()
a1 = f1.readlines()
a2 = f2.readlines()
print(a)

for i in range(0,10):
    y1.append((float)(a[i].strip("\n")))
    y2.append((float)(a1[i].strip("\n")))
    y3.append((float)(a2[i].strip("\n")))

print(y1)


x = np.array(x)
plt.bar(x-0.5,y1,0.3,label = labels[0])
plt.bar(x,y2,0.3,label = labels[1])
plt.bar(x+0.5,y3,0.3,label = labels[2])
plt.title("Priority Value")
plt.ylabel("Time Taken(s)")
plt.xlabel("Priorities")
plt.legend()
plt.show()