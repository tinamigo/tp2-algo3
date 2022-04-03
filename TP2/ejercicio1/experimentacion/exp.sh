#!/bin/bash
imagen="$1"                        #nombre de imagen
K="$2"                             #valor de K con el que corre
algoritmo="$3"                     #array , tree o treePR
modo="$4"                          #tiempo o imagen
src="ImagenesTxtGray/$imagen.txt"
dst_time="Tiempos/$imagen$K$algoritmo$modo.txt"

echo "Convirtiendo imagen a formato válido.."
chmod 755 ./to_grey.py
python3 ./to_grey.py $imagen

echo "Ejecutando el algoritmo $algoritmo en modo \"$modo\" sobre la imagen \"$imagen\" con K igual a $K.."
if [ $modo == "imagen" ]
then
	#genero la imagen resultado en txt con las componentes segmentadas para el K
	dst="ImagenesTxt/$imagen$K.txt"
	if [ $algoritmo == "array" ]
	then
		Ejecutables/exp_array $K < $src > $dst
	fi
	if [ $algoritmo == "tree" ]
	then
		Ejecutables/exp_tree $K < $src > $dst
	fi
	if [ $algoritmo == "treePR" ]
	then
		Ejecutables/exp_treePR $K < $src > $dst
	fi

	#reconstruyo las imagenes
	echo "reconstruyendo imagen.."
	chmod 755 ./reconstruir.py
	python3 ./reconstruir.py $imagen$K
	echo "termine de reconstruir"
fi
	
	#si no es que quiero medir tiempos entonces corro algos de tiempos
if [ $modo == "tiempo" ]
then
	if [ $algoritmo == "array" ]
	then
		Ejecutables/exp_array_time $K < $src > $dst_time
	fi
	if [ $algoritmo == "tree" ]
	then
		Ejecutables/exp_tree_time $K < $src > $dst_time
	fi
	if [ $algoritmo == "treePR" ]
	then
		Ejecutables/exp_treePR_time $K < $src > $dst_time
	fi	
fi

if [ $modo == "tiempoModelaje" ]
then
	if [ $algoritmo == "array" ]
	then
		Ejecutables/exp_array_time_modelaje $K < $src > $dst_time
	fi
	if [ $algoritmo == "tree" ]
	then
		Ejecutables/exp_tree_time_modelaje $K < $src > $dst_time
	fi
	if [ $algoritmo == "treePR" ]
	then
		Ejecutables/exp_treePR_time_modelaje $K < $src > $dst_time
	fi	
fi






