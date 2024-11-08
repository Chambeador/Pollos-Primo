//cantidad de sumas distintas de exactamente k de longitud (equivalente a cantidad de sumas ordenadas)
int dp(int n, int k, const vector<int>& arr) {
    int m = arr.size();
    
    // Crear una tabla DP para almacenar los resultados
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, 0)));
    
    // Caso base: Si x == 0 y k == 0, hay exactamente 1 forma (no seleccionar ningún número)
    for (int i = 0; i <= m; i++) {
        dp[0][0][i] = 1;  // 1 forma de hacer suma 0 con 0 elementos
    }

    // Rellenar la tabla iterativamente
    for (int x = 1; x <= n; x++) {
        for (int kk = 1; kk <= k; kk++) {
            for (int i = 0; i < m; i++) {
                // Opción 1: No tomar el número arr[i], simplemente tomamos el valor de la fila anterior
                dp[x][kk][i + 1] = dp[x][kk][i];
                
                // Opción 2: Tomar el número arr[i], restamos arr[i] de x y reducimos k
                if (x >= arr[i]) {
                    dp[x][kk][i + 1] += dp[x - arr[i]][kk - 1][i]; 
                }
            }
        }
    }
    // La respuesta final está en dp[n][k][m], que es la forma de sumar n con k números usando todos los numeros
    return dp[n][k][m];
}


//reduccion de memoria (NO COMPROBADO)
int dp(int n, int k, const vector<int>& arr) {
    int m = arr.size();
    
    // Crear una tabla 2D de DP: dp[x][k] donde x es la suma y k es el número de elementos seleccionados
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    
    // Caso base: hay exactamente 1 forma de hacer suma 0 con 0 elementos
    dp[0][0] = 1;

    // Rellenar la tabla iterativamente
    for (int i = 0; i < m; i++) {  // Iteramos sobre cada elemento en arr
        // Iteramos hacia atrás para no sobrescribir los valores de la misma iteración
        for (int x = n; x >= arr[i]; x--) {  // Solo consideramos sumas donde x >= arr[i]
            for (int kk = k; kk >= 1; kk--) {  // Solo consideramos hasta k elementos
                dp[x][kk] += dp[x - arr[i]][kk - 1];
            }
        }
    }

    // La respuesta final está en dp[n][k], que es la forma de sumar n con k elementos
    return dp[n][k];
}
