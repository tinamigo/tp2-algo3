#!/bin/bash
algoritmo="$1"


for fila in {2..100..20}
do
	for columna in {2..100..20}
	do
		K=expr $fila `*` $columna
		echo $K
		if [ $algoritmo == "array" ]
   		then
   			./Ejecutables/generador_imagen $fila $columna > exp_array_time_tmp.txt
   			#/Ejecutables/exp_array_time < 
   		fi
   	
   		if [ $algoritmo == "tree" ]
   		then
   			Ejecutables/generar_imagen $fila $columna > Ejecutables/
   		fi
   	
   		if [ $algoritmo == "treePR" ]
   		then
   			Ejecutables/generar_imagen $fila $columna > Ejecutables/
   		fi
	done
done