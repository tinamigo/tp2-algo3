from PIL import Image
from PIL import ImageOps
import numpy as np
import random as rand
import os
import sys

#ruta = input()
algoritmo = sys.argv[1]
if algoritmo == "array":
	os.system("rm -rf Tiempos/complejidades_array.txt")
	f=open("Tiempos/complejidades_array.txt", "w+")
	f.write("fila,columna,tiempo\n")
	f.close()
elif algoritmo == "tree":
	os.system("rm -rf Tiempos/complejidades_tree.txt")
	f=open("Tiempos/complejidades_tree.txt", "w+")
	f.write("fila,columna,tiempo\n")
	f.close()
elif algoritmo == "treePR":
	os.system("rm -rf Tiempos/complejidades_treePR.txt")
	f=open("Tiempos/complejidades_treePR.txt", "w+")
	f.write("fila,columna,tiempo\n")
	f.close()
else:
	os.system("echo LPM")

for i in [2,52,102,152,202,302,402,502]:
	for j in [2,52,102,152,202,302,402,502]:
		K = i * j * 255
		if algoritmo == "array":
			os.system("./Ejecutables/generador_imagen "+str(i)+" "+str(j)+" > exp_time_tmp_array.txt")
			f=open("Tiempos/complejidades_array.txt", "a")
			f.write(str(i)+","+str(j)+",")
			f.close()
			os.system("./Ejecutables/exp_array_time "+str(K)+" < exp_time_tmp_array.txt >> Tiempos/complejidades_array.txt")
			os.system("rm -rf exp_time_tmp_array.txt")
		elif algoritmo == "tree":
			os.system("./Ejecutables/generador_imagen "+str(i)+" "+str(j)+" > exp_time_tmp_tree.txt")
			f=open("Tiempos/complejidades_tree.txt", "a")
			f.write(str(i)+","+str(j)+",")
			f.close()
			os.system("./Ejecutables/exp_tree_time "+str(K)+" < exp_time_tmp_tree.txt >> Tiempos/complejidades_tree.txt")
			os.system("rm -rf exp_time_tmp_tree.txt")
		elif algoritmo == "treePR":
			os.system("./Ejecutables/generador_imagen "+str(i)+" "+str(j)+" > exp_time_tmp_treePR.txt")
			f=open("Tiempos/complejidades_treePR.txt", "a")
			f.write(str(i)+","+str(j)+",")
			f.close()
			os.system("./Ejecutables/exp_treePR_time "+str(K)+" < exp_time_tmp_treePR.txt >> Tiempos/complejidades_treePR.txt")
			os.system("rm -rf exp_time_tmp_treePR.txt")
		else:
			os.system("echo LPM")

