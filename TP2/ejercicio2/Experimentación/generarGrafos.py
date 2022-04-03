import networkx as nx
import random
import numpy as np

# grafo de n nodos donde la probabilidad de que un eje exista es de p
ns = [10 * x for x in range(1,100)]
ps = [0.2, 0.4, 0.6, 0.8, 1]

for n in ns:
    for p in ps:
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


        with open("n " + str(n) +"  - p "+ str(p) +" .txt" ,  "wb") as file:  # te hace el open y el close """ % str(p) """
            file.write(tamaniosBytes)
            #file.write(costos)
            for x in costos:
                file.write(bytes(str(int(x)), 'utf-8'))
                file.write(bytes("\n", 'utf-8'))
            nx.write_weighted_edgelist(G, file)
