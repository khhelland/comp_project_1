import numpy as np
import matplotlib.pyplot as plt
import os, time

#compile and link programs
os.system('g++ -c project_1_b.cpp')
os.system('g++ -o project_1_b.x project_1_b.o -O1 -larmadillo')
os.system('g++ -c LU.cpp')
os.system('g++ -o LU.x LU.o -O1 -larmadillo')

#The different ns I will use
Steps = [10**i for i in range(1,6)]

#Files for writing results
errorfile = open('error.dat','w')
timefile = open('total_time.dat','w')
lufile = open('lu_err.dat','w')

errorfile.write('n & $\epsilon_i$\\\ \hline \n')
timefile.write('my algorithm & LU and solve \\\ \hline \n')
lufile.write('n & $\epsilon_i$ \\\ \hline \n')

#As the c++ programs append these files they must be deleted
os.system('rm lu_time.dat myalg_time.dat')

for steps in Steps:
    
    #Analytical solution
    x_vec = np.linspace(0,1,steps+2)
    ansol = 1 - (1 - np.exp(-10))*x_vec -np.exp(-10*x_vec)

    
    #run program with command line argument steps
    start_1 = time.clock()
    os.system(' '.join(('./project_1_b.x',str(steps))))
    end_1 = time.clock()
    
    #Fetch simulation
    sim = np.loadtxt('data.dat')
    x_sim = np.linspace(0,1,steps+2)
    
    
    #find error
    eps = np.max(np.log10(abs((ansol[1:-1]-sim[1:-1]))/ansol[1:-1]))
    
    errorfile.write(' '.join((str(steps),'&',str(eps),'\\\ \hline \n')))
    
    if steps <= 1000:
        
        #Plot data against analytical solution
    
        plt.figure()
        plt.plot(x_vec,ansol,'-',x_sim,sim,'-')
        plt.legend(('analytical solution','simulation'))
        plt.xlabel('x')
        plt.ylabel('u')
        plt.savefig('ansol_sim_n_%g.png' %steps)

        #Compare my algorithm against LU-decomposition
    
        start_2 = time.clock()
        os.system(' '.join(('./LU.x',str(steps))))
        end_2 = time.clock()
        
        time_1 = end_1 - start_1
        time_2 = end_2 - start_2
        timefile.write(' '.join((str(time_1),str(time_2),'\\\ \hline \n')))
        
        lu_sim = np.loadtxt('LU.dat')
        eps = np.max(np.log10(abs((lu_sim-sim[1:-1]))/lu_sim))
        
        lufile.write(' '.join((str(steps),'&',str(eps),'\\\ \hline \n')))
        
