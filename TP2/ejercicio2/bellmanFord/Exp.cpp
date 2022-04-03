#include "bellmanFord.h"
#include <chrono>
#include <fstream>
#include <string>

using namespace std;

int main () {
    for (int n = 10; n <= 1000; n+=10) {
      for (int p = 0.2; p <= 1; p+=0.2) {

          string line;
          int m;
          ifstream archivo ("n 10 - p 0.4 .txt", ios::out);
          if (archivo.is_open()){
            if (getline(archivo, line)){
              n = stoi(line);
            }
            if (getline(archivo, line)){
              m = stoi(line);
              printf("m vale %d\n", m);
            }
            archivo.close();
          }else {
            printf("Error");
          }

          printf("m coso %d\n", m);

          break;              //SACAR
      }
      break;                  //SACAR
    }


}
