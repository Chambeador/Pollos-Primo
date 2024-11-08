// la longitud del subarray con numeros sucesivos mas larga (sin repetir
// numeros)
int LI-SUBARRAYsinrepetir(int n, vector<int> arr) {
    int l = 0, ans = 0;
    // mapa para guardar la ultima ocurrencia de un numero
    map<int, int> mp;

    // two pointers
    for (int r = 0; r < n; r++) {
        // Si el elemento actual no esta en el mapa
        if (mp.find(arr[r]) == mp.end())
            mp.insert({ arr[r], r });
        else {
            // if el numero actual esta en el mapa y esta en la ventana
            if (mp[arr[r]] >= l) l = mp[arr[r]] + 1;
            // actualizar la ultima ocurrencia del caracter en el indice actual
            mp[arr[r]] = r;
        }
        //maximizar la respuesta
        ans = max(ans, r - l + 1);
    }
    return ans;
}