from PIL import Image
from PIL import ImageOps
import numpy as np
import random as rand
import os
import sys

#ruta = input()
algoritmo = sys.argv[1]
if algoritmo == "array":
	os.system("rm -rf Tiempos/complejidades_array_fijo.txt")
	f=open("Tiempos/complejidades_array_fijo.txt", "w+")
	f.write("fila,columna,tiempo\n")
	f.close()
elif algoritmo == "tree":
	os.system("rm -rf Tiempos/complejidades_tree_fijo.txt")
	f=open("Tiempos/complejidades_tree_fijo.txt", "w+")
	f.write("fila,columna,tiempo\n")
	f.close()
elif algoritmo == "treePR":
	os.system("rm -rf Tiempos/complejidades_treePR_fijo.txt")
	f=open("Tiempos/complejidades_treePR_fijo.txt", "w+")
	f.write("fila,columna,tiempo\n")
	f.close()
else:
	os.system("echo LPM")

K = sys.argv[2]

for i in [2,52,102,152,202,302,402,502]:
	for j in [2,52,102,152,202,302,402,502]:
		os.system("./Ejecutables/generador_imagen "+str(i)+" "+str(j)+" > exp_time_tmp.txt")
		if algoritmo == "array":
			f=open("Tiempos/complejidades_array_fijo.txt", "a")
			f.write(str(i)+","+str(j)+",")
			f.close()
			os.system("./Ejecutables/exp_array_time "+str(K)+" < exp_time_tmp.txt >> Tiempos/complejidades_array_fijo.txt")
			os.system("rm -rf exp_time_tmp.txt")
		elif algoritmo == "tree":
			f=open("Tiempos/complejidades_tree_fijo.txt", "a")
			f.write(str(i)+","+str(j)+",")
			f.close()
			os.system("./Ejecutables/exp_tree_time "+str(K)+" < exp_time_tmp.txt >> Tiempos/complejidades_tree_fijo.txt")
			os.system("rm -rf exp_time_tmp.txt")
		elif algoritmo == "treePR":
			f=open("Tiempos/complejidades_treePR_fijo.txt", "a")
			f.write(str(i)+","+str(j)+",")
			f.close()
			os.system("./Ejecutables/exp_treePR_time "+str(K)+" < exp_time_tmp.txt >> Tiempos/complejidades_treePR_fijo.txt")
			os.system("rm -rf exp_time_tmp.txt")
		else:
			os.system("echo LPM")

