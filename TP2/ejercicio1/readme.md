#Ejercicio 1: ¨Segmentation is my fault¨

Para compilar el código deseado, entrar al directorio `array/`, `tree/` o `treePathRelinking/` según corresponda y ejecutar `make`.
Esto genera el ejecutable `XExe` (X depende de la carpeta en que makeemos) que funciona como es requerido.

Además proveemos el script `comparacion.sh` que compila y ejecuta 3 casos de test para las 3 implementaciones de union-find.
Imprime el tiempo tardado por cada implementación para cada imagen y luego compara los resultados obtenidos de la segmentación entre ellos usando el comando diff (notar que si este comando no devuelve nada, entonces no encontró diferencias, por lo que los resultados serían iguales).