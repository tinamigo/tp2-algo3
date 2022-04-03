#Ejercicio 2: ¨Llenalo con super¨

Para compilar el código deseado, entrar al directorio `bellmanFord/`, `dijkstra/`, `dijkstraDense/` o `floyd/` según corresponda y ejecutar `make`.
Esto genera el ejecutable `XExe` (X depende de la carpeta en que makeemos) que funciona como es requerido.

Además proveemos el script `comparacion.sh` que posee dos funcionalidades:

1. si lo ejecutamos directamente entonces realiza la comparación de dos tests simples realizados por nosotros (test1 y test2) y avisa si encuentra algún resultado distinto.

2. en caso de que quieran correr sus propios tests, pueden pasarle por parámetro un txt que contenga el input deseado (debe respetar el formato de input establecido en el enunciado del tp). Al igual que en el caso anterior, el script se encargara de comparar los outputs y avisar en caso de diferencias.
un ejemplo de llamada sería `./comparacion.sh test1.txt`.