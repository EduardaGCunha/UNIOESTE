#include <bits/stdc++.h>
using namespace std;

struct LFA {
    int n;
    vector<vector<pair<int, char>>> grafo;
    int finais[27] = {};

    void leitura(){
        ifstream arquivo("arquivo.txt");
        if(!arquivo.is_open()) {
            cout << "Erro ao abrir arquivo" << endl;
            return;
        }

        string temp;
        getline(arquivo,temp);

        getline(arquivo, temp);
        n = qtd_estados(temp);  
        cout << n << endl;

        grafo.resize(n);

        getline(arquivo, temp);
        get_finais(temp);

        int cnt = 0;
        while(getline(arquivo, temp) ) {
            monta_o_grafo(temp);
        }
    }

    int qtd_estados(string temp){
        int i = temp.size()-2, j = 0;
        int n = 1;
        while(temp[i] - '0' >= 0 && temp[i] - '0' <= 9){
            n += (temp[i]-'0') * (pow(10, j));
            j++;
            i--;
        }
        return n;
    }

    void imprime() {
        for (int i = 0; i < n; i++) {
            char c = i + 65;
            cout << c << " -> ";
            for(int j = 0; j < grafo[i].size(); j++) {
                char e = grafo[i][j].first + 65;
                cout <<  grafo[i][j].second << e;
                if (j+1 != grafo[i].size())cout << " | ";
            }
            if (finais[i]) {
                cout << " | @ ";
            }
            cout << endl;
        }
    }

    int transforma_em_int(string temp){
        int i = 0;
        int n = 0;
        while(temp[i] - '0' >= 0 && temp[i] - '0' <= 9){
            n += (temp[i]-'0') * (pow(10, i));
            i++;
        }
        return n;
    }

    void get_finais(string str) {
        int contador = 8;
        while (str[contador] != '\0') {
            if (str[contador] == 'q') {
                int i = contador;
                while (str[i] != ',' && str[i] != '}'){
                    i++;
                }
                string aux = str.substr(contador + 1, i - contador - 1);
                int n = transforma_em_int(aux);
                finais[n] = 1;
            }
            contador++;
        }
    }

    void monta_o_grafo(string temp){
        int a, b;
            char c;
            a = -1, b = -1;
            for(int i = 0; i < temp.size(); i++){
                if(temp[i] == '(' || temp[i] == ')' || temp[i] == ',' 
                || temp[i] == '=' || temp[i] == ' ') continue;
                if(temp[i] == 'q'){
                    if(a == -1){
                        string s = temp.substr(i+1, i+2);
                        a = transforma_em_int(s);
                    }else{
                        string s = temp.substr(i+1, i+2);
                        b = transforma_em_int(s);
                    }
                    i++;
                }else{
                    c = temp[i];
                }
            }
            grafo[a].push_back({b, c});
    }

    void dfs(){
        string s; cin >> s;
        stack<int> st;
        st.push(0);
        int last = -1, transition = 0;
        if (s == "@" && finais[0]){
            cout << "ACEITA" << endl;
            return;
        }
        for(int i = 0; i < s.size(); i++){
            string t = s.substr(i);
            if(st.empty()){
                cout << "REJEITA" << endl;
                return;
            }
            int cur = st.top();
            st.pop();

            cout << "[q" << cur << "]" << t << endl;
            for(auto u : grafo[cur]){
                if(u.second == s[i]){
                    st.push(u.first);
                    last = u.first;
                    transition = 1;
                } 
            }
        }

        if(!transition){
            cout << "REJEITA" << endl;
            return;
        }
        cout << "[q" << last << "]" << endl;
        if(finais[last] == 1){
            cout << "ACEITA" << endl; 
        }
        else cout << "REJEITA" << endl;
    }
    
}; 

int main(){
    LFA lfa;

    lfa.leitura();
    lfa.imprime();
    lfa.dfs();
}
