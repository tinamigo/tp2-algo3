import networkx as nx
import random
import numpy as np
import os
import sys


os.system("rm -rf exp_time_tmp.txt")
# grafo de n nodos donde la probabilidad de que un eje exista es de p
n = int(sys.argv[1])
p = float(sys.argv[2])
algo = sys.argv[3]


G = nx.erdos_renyi_graph(n, p)

# Esto es re sucio, y puede tardar sobretodo con un p chico
# Pero es bien random :)
while(not nx.is_connected(G)):
    G = nx.erdos_renyi_graph(n, p)
for (u, v, w) in G.edges(data=True):
    w['weight'] = random.randint(1, 59)

m = G.number_of_edges()
tamanios = "{}\n{}\n".format(n, m)
tamaniosBytes = bytes(tamanios, 'utf-8')

costos = np.zeros(n)


for i in range(0,n):
    costos[i] = random.randint(1, 200)


with open("exp_time_tmp_"+algo+".txt" ,  "wb") as file:  # te hace el open y el close """ % str(p) """
    file.write(tamaniosBytes)
    #file.write(costos)
    for x in costos:
        file.write(bytes(str(int(x)), 'utf-8'))
        file.write(bytes("\n", 'utf-8'))
    nx.write_weighted_edgelist(G, file)
