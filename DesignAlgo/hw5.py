import pulp as p   # import pulp library and refer to it as p
from pulp import lpSum
import numpy as np
import time

M = int(input())
# D = np.zeros(M)
D = np.array(input().split(), dtype=float)
E, Hcost, Fcost = np.array(input().split(), dtype=float)
S, C = np.array(input().split(), dtype=float)
OTC, OTPrice = np.array(input().split(), dtype=float)
W = float(input())
ti = time.time()

b = np.array([0])

# adding psuedo months before and after actual production months
D = np.concatenate((b, D, b))

# months under consideration
t = [x for x in range(M+2)]

# Defining the problem variables
Wt = p.LpVariable.dicts('N_workers', t, 0, cat=p.LpInteger)
Ht = p.LpVariable.dicts('hiring', t, 0)
Ft = p.LpVariable.dicts('firing', t, 0)
Xt = p.LpVariable.dicts('total_carpets', t, 0, cat=p.LpInteger)
Ot = p.LpVariable.dicts('overtime_carpets', t, 0, cat=p.LpInteger)
St = p.LpVariable.dicts('unsold', t, 0, cat=p.LpInteger)

# Create a LP Minimization problem
Lp_prob = p.LpProblem('Problem', p.LpMinimize)

x = []

# Constraints
# At the end we need only E workers
Lp_prob += Wt[M+1] == E
# At the start we have E workers
Lp_prob += Wt[0] == E
# Strored carpets at the end of pseudo month is 0
Lp_prob += St[0] == 0


for i in t[1:M+1]:
    # Number of carpets made in a month
    Lp_prob += C*Wt[i] + Ot[i] == Xt[i]
for i in t[1:M+2]:
    # Number of workers after firing/hiring
    Lp_prob += Wt[i] == Wt[i-1] + Ht[i] - Ft[i]
for i in t[1:M+1]:
    # Number of unsold carpets at the end of the month
    Lp_prob += St[i] == St[i-1] + Xt[i] - D[i]
for i in t[1:M+1]:
    # Overtime in limited
    Lp_prob += Ot[i] <= OTC*Wt[i]

# Objective
Lp_prob += lpSum(S*Wt[i] for i in t[1:M+1]) + lpSum(Hcost*Ht[i] for i in t[1:M+2]) + \
           lpSum(Fcost*Ft[i] for i in t[1:M+2]) + lpSum(W*St[i] for i in t[1:M]) + \
           lpSum(OTPrice*Ot[i] for i in t[1:M+1])


p.PULP_CBC_CMD(msg=0).solve(Lp_prob)   # Solver

tf = time.time()

# Printing the final solution
print(p.value(Lp_prob.objective), tf-ti)

