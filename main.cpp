#include <iostream>
#include <vector>
#include <set>
using namespace std;

//NUM GRAFO NÃO DIRECIONAL, CONTAR QUANTOS PARES DE NÓS É QUE SÃO INACESSÍVEIS UNS AOS OUTROS
//OU SEJA: PARES DE NÓS DO GRAFO QUE NÃO TÊM UMA ARESTA DIRETA
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        int count=n*(n-1)/2;
        //set<int> s;

        /*for (int i=0; i<edges.size(); i++){
            s.insert(edges[i][0]);
            s.insert(edges[i][1]);
        }*/
        return count-edges.size();
    }
};


int main(){
    for (int i=0; i<7; i++){
        for (int j=0; j<7; j++){
            if (i!=j){
                cout << "[" << i << "; " << j << "]\n";
            }
        }
    }
    return 0;
}