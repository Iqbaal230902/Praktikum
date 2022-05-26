#include <iostream>
using namespace std;


int main() {

    int nama;
    
    for (nama = 1; nama < 21; nama++) {
    if  (nama == 10){
    	continue;
        }
        
   if (nama == 17) {
    break;
  }
        
        cout << "Membership ke-" << nama << endl;
        }
    
    return 0;
}
