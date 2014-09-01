import numpy as np
import matplotlib.pyplot as plt
import sys, os


Steps = []
for i in range(1,6):
    Steps.append(10**i)


#Analytical solution
x_vec = np.linspace(0,1,1e6)
ansol = 1 - (1 - np.exp(-10))*x_vec -np.exp(-10x)




for steps in Steps:
    
    #run program with command line argument steps
    os.system(' '.join(('./project_1_b.x',str(steps))))
    
    
    #load

    x_sim = np.lispace(0,1,steps+2)
    
    #Plot data against analytical solution
    
    plt.figure()
    plt.plot(x_vec,ansol,'-',x_sim,sim,'-')
    plt.legend(('analytical solution','simulation'))
    plt.xlabel('x')
    plt.ylabel('u')
    plt.savefig('ansol_sim_n_%g.png' %steps)
