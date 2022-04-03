from PIL import Image
from PIL import ImageOps
import numpy as np
import random as rand
import os
import sys

#ruta = input()
algoritmo = sys.argv[1]
if algoritmo == "bellmanFord" or algoritmo == "coso":
	os.system("rm -rf Tiempos/complejidades_bellmanFord.txt")
	f=open("Tiempos/complejidades_bellmanFord.txt", "w+")
	f.write("n,p,m,tiempo\n")
	f.close()
elif algoritmo == "dijkstra":
	os.system("rm -rf Tiempos/complejidades_dijkstra.txt")
	f=open("Tiempos/complejidades_dijkstra.txt", "w+")
	f.write("n,p,m,tiempo\n")
	f.close()
elif algoritmo == "dijkstraDense":
	os.system("rm -rf Tiempos/complejidades_dijkstraDense.txt")
	f=open("Tiempos/complejidades_dijkstraDense.txt", "w+")
	f.write("n,p,m,tiempo\n")
	f.close()
elif algoritmo == "floyd":
	os.system("rm -rf Tiempos/complejidades_Floyd.txt")
	f=open("Tiempos/complejidades_floyd.txt", "w+")
	f.write("n,p,m,tiempo\n")
	f.close()

else:
	os.system("echo LPM")



for n in [5 * i for i in range(5,10)]:
	for p in [0.2]:
		#K = i * j * 255
		os.system("python3 generarGrafo.py "+str(n)+" "+str(p)+" "+algoritmo)
		if algoritmo == "coso":
			f=open("Tiempos/complejidades_bellmanFord.txt", "a")
			f.write(str(n)+","+str(p)+",")
			f.close()
			print("../bellmanFord/bellmanFord < n"+str(n)+"p"+str(p)+".txt >> Tiempos/complejidades_bellmanFord.txt")
			os.system("../bellmanFord/bellmanFord < n"+str(n)+"p"+str(p)+".txt >> Tiempos/complejidades_bellmanFord.txt")
			#Fijate que exp_bellmanFord_time (y los otros algos tmbn) va a tener que imprimir m,tiempo
			#os.system("rm -rf exp_time_tmp_bellmanFord.txt")
		elif algoritmo == "bellmanFord":
			f=open("Tiempos/complejidades_bellmanFord.txt", "a")
			f.write(str(n)+","+str(p)+",")
			f.close()
			print("../bellmanFord/bellmanFord < exp_time_tmp_"+algoritmo+".txt >> Tiempos/complejidades_bellmanFord.txt")
			os.system("../bellmanFord/bellmanFord < exp_time_tmp_"+algoritmo+".txt >> Tiempos/complejidades_bellmanFord.txt")
			#Fijate que exp_bellmanFord_time (y los otros algos tmbn) va a tener que imprimir m,tiempo
			#os.system("rm -rf exp_time_tmp_"+algoritmo+"_bellmanFord.txt")
		elif algoritmo == "dijkstra2":
			f=open("Tiempos/complejidades_dijkstra2.txt", "a")
			f.write(str(n)+","+str(p)+",")
			f.close()
			os.system("../dijkstra/dijkstra < exp_time_tmp_"+algoritmo+".txt >> Tiempos/complejidades_dijkstra2.txt")
		elif algoritmo == "dijkstraDense":
			f=open("Tiempos/complejidades_dijkstraDense.txt", "a")
			f.write(str(n)+","+str(p)+",")
			f.close()
			os.system("../dijkstraDense/dijkstraDense < exp_time_tmp_"+algoritmo+".txt >> Tiempos/complejidades_dijkstraDense.txt")
		elif algoritmo == "floyd":
			f=open("Tiempos/complejidades_floyd.txt", "a")
			f.write(str(n)+","+str(p)+",")
			f.close()
			os.system("../floyd/floyd < exp_time_tmp_"+algoritmo+".txt >> Tiempos/complejidades_floyd.txt")
		else:
			os.system("echo LPM")
