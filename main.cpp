#include <iostream>
#include <vector>
#include <set>
using namespace std;

//NUM GRAFO NÃO DIRECIONAL, CONTAR QUANTOS PARES DE NÓS É QUE SÃO INACESSÍVEIS UNS AOS OUTROS
//OU SEJA: PARES DE NÓS DO GRAFO QUE NÃO TÊM UMA ARESTA DIRETA
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> aux;
        int cnt=0;
        if (cnt==0){
            aux.push_back(vector<int>());
            aux[0].push_back(edges[0][0]);
            aux[0].push_back(edges[0][1]);
            cnt=1;
        }
        for (int i=1; i<edges.size(); i++){ //percorre o vetor de arestas
            for (int j=0; j<aux.size(); j++){ //percorre o vetor que contem os grupos conectados
                int isinA=0;
                int isinB=0;
                for (int k=0; k<aux[j].size(); k++){ //percorre os elementos conectados de um grupo
                    if (edges[i][0]==aux[j][k]){
                        isinA=1;
                    }
                    if (edges[i][1]==aux[j][k]){
                        isinB=1;
                    }
                    if (isinA==1 && isinB==1){
                        break;
                    }
                }
                if (isinA==1 && isinB==0){ //se apenas um dos elemetos está no grupo insere o outro e quebra o ciclo
                    aux[j].push_back(edges[i][1]);
                    break;
                }
                if (isinA==0 && isinB==1){ //se apenas um dos elemetos está no grupo insere o outro e quebra o ciclo
                    aux[j].push_back(edges[i][0]);
                    break;
                }
                if (isinA==0 && isinB==0 && j==aux.size()){ /*se nenhum dos elementos estiver em nenhum dos grupos,
                                                              cria um novo grupo, adiciona os elementos,
                                                              e quebra o ciclo*/
                    aux.push_back(vector<int>());
                    aux[j+1].push_back(edges[i][0]);
                    aux[j+1].push_back(edges[i][1]);
                    break;
                }
            }
        }
        int sum=0;
        for (int i=1; i<aux.size(); i++){
            sum += aux[i].size();
        }
        int num = n*(n-1)/2;
        return num-sum;
    }
};


int main(){

    return 0;
}