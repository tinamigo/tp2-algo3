#!/bin/bash
cd array/ && make tests && cd ../
cd tree/ && make tests && cd ../
cd treePathRelinking/ && make tests && cd ../

echo "Comparando outputs de gatos, si no devuelve nada entonces esta bien:  "
diff array/gatosarray.txt tree/gatostree.txt 
diff treePathRelinking/gatostreePathRelinking.txt tree/gatostree.txt 

echo "Comparando outputs de halcon, si no devuelve nada entonces esta bien:  "
diff array/halconarray.txt tree/halcontree.txt 
diff treePathRelinking/halcontreePathRelinking.txt tree/halcontree.txt 

echo "Comparando outputs de koala, si no devuelve nada entonces esta bien:  "
diff array/koalaarray.txt tree/koalatree.txt 
diff treePathRelinking/koalatreePathRelinking.txt tree/koalatree.txt 