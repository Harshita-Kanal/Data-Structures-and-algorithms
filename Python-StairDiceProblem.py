import numpy as np
import matplotlib.pyplot as plt



np.random.seed(123)
last_step_single_walk=[]
op = input('Number of iteraations to test (Max 50,000): ')

if int(op) <= 50000:
    for x in range(int(op)):
        step = 0
        for x in range(100):
            dice = np.random.randint(1,7)
            #Step conditions on dice throw
            if dice <=2:
                step=max(step-1,0)
            elif dice <=5:
                step+=1
            else:
                step+=np.random.randint(1,7)

            #Clumsyness
            if np.random.rand() <= 0.001:
                step = 0
        last_step_single_walk.append(step)
    last_steps=np.array(last_step_single_walk)
    sixty_steps = last_steps[last_steps>60]
    print('Reached step 60 or above '+str(len(sixty_steps))+' times out of '+str(op)+' iterations')
    print(str(len(sixty_steps)/int(op))+' % chance of 60 or higher step')
    plt.hist(last_steps)
else:
    print('Above Limits')
