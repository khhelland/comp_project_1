import numpy as np
import matplotlib.pyplot as plt
import sys, os


Steps = []
for i in range(1,6):
    Steps.append(10**i)


for steps in Steps:
    
    #Analytical solution
    x_vec = np.linspace(0,1,steps+2)
    ansol = 1 - (1 - np.exp(-10))*x_vec -np.exp(-10*x_vec)


    
    #run program with command line argument steps
    os.system(' '.join(('./project_1_b.x',str(steps))))
    
    
    #load
    sim = np.loadtxt('data.dat')
    x_sim = np.linspace(0,1,steps+2)
    
    
    #find error
    eps = np.max(np.log10(abs((ansol[1:-1]-sim[1:-1]))/ansol[1:-1]))
    
    print "n = ",steps,"\t eps = ",eps
    
    
    #Plot data against analytical solution
    
    plt.figure()
    plt.plot(x_vec,ansol,'-',x_sim,sim,'-')
    plt.legend(('analytical solution','simulation'))
    plt.xlabel('x')
    plt.ylabel('u')
    plt.savefig('ansol_sim_n_%g.png' %steps)
