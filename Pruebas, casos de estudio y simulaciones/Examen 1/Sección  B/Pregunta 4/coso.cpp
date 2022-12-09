#include <cstdlib>
#include <iostream>

using namespace std;

int main(){

char comando [50];

for(int i = 3; i<51; i++){
sprintf(comando, "./freq %i", i);
system(comando);
}

return 0;
}
