import numpy as np
import matplotlib.pyplot as plt
import os, time


Steps = []
for i in range(1,6):
    Steps.append(10**i)

errorfile = open('error.dat','w')
timefile = open('total_time.dat','w')


errorfile.write('n & $\epsilon$\\\ \hline \n')
timefile.write('my algorithm & LU and solve \\\ \hline \n')

os.system('rm lu_time.dat myalg_time.dat')

for steps in Steps:
    
    #Analytical solution
    x_vec = np.linspace(0,1,steps+2)
    ansol = 1 - (1 - np.exp(-10))*x_vec -np.exp(-10*x_vec)

    
    #run program with command line argument steps
    start_1 = time.clock()
    os.system(' '.join(('./project_1_b.x',str(steps))))
    end_1 = time.clock()
    
    #load
    sim = np.loadtxt('data.dat')
    x_sim = np.linspace(0,1,steps+2)
    
    
    #find error
    eps = np.max(np.log10(abs((ansol[1:-1]-sim[1:-1]))/ansol[1:-1]))
    
    errorfile.write(' '.join((str(steps),'&',str(eps),'\\\ \hline \n')))
    
    
    #Plot data against analytical solution
    
    plt.figure()
    plt.plot(x_vec,ansol,'-',x_sim,sim,'-')
    plt.legend(('analytical solution','simulation'))
    plt.xlabel('x')
    plt.ylabel('u')
    plt.savefig('ansol_sim_n_%g.png' %steps)

    #Time my algorithm against LU-decomposition
    if steps <= 1000:
        start_2 = time.clock()
        os.system(' '.join(('./LU.x',str(steps))))
        end_2 = time.clock()
        
        time_1 = end_1 - start_1
        time_2 = end_2 - start_2
        timefile.write(' '.join((str(time_1),str(time_2),'\\\ \hline \n')))
