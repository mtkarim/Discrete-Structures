//Mubasshir Karim
//chapter 9 program - #10

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string line, temp;
    int n = 0;
    int k = 0;
    int counter = 0;

    getline(cin,line);
    line.erase(remove(line.begin(),line.end(),' '),line.end());
    line.erase(remove(line.begin(),line.end(),','),line.end());
    
    n = line.length();
   // cout << n << endl;
    
    string matrix[n][n];
    
    getline(cin,line);
    line.erase(remove(line.begin(),line.end(),','),line.end());
    line.erase(remove(line.begin(),line.end(),'{'),line.end());
    line.erase(remove(line.begin(),line.end(),'}'),line.end());
   
  
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = line[k];
            k++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if (i == j) {
                if (matrix[i][j] == "1") {
                    counter++;
                }
            }
            else{
                if (matrix[i][j] == "1") {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    
    if (counter == n) {
        cout << "Yes" << endl;
    }
    return 0;
}
