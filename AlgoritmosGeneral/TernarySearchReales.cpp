#include <bits/stdc++.h>

using namespace std;

/**
.---------------------------------------------------.
| ██████╗ ██╗████████╗     ██████╗ ██╗   ██╗██████╗ |
|██╔════╝ ██║╚══██╔══╝    ██╔════╝ ██║   ██║██╔══██╗|
|██║  ███╗██║   ██║       ██║  ███╗██║   ██║██║  ██║|
|██║   ██║██║   ██║       ██║   ██║██║   ██║██║  ██║|
|╚██████╔╝██║   ██║       ╚██████╔╝╚██████╔╝██████╔╝|
| ╚═════╝ ╚═╝   ╚═╝        ╚═════╝  ╚═════╝ ╚═════╝ |
'---------------------------------------------------'
**/

double f(double x) {
    return 0;
    // escribir la funcion;
}

void ternarySearchMaximo() {
    double eps = 1e-6;
    int l = -100, r = 100, m1, m2;
    while (r - l > 2) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;

        int fm1 = ar[m1]; // resultado funcion evaluada en m1
        int fm2 = ar[m2];

        if (fm1 == fm2) {
            l = m1;
            r = m2;

        } else if (fm1 < fm2) {
            l = m1;
        } else {
            r = m2;
        }
    }
    int ans = INT_MIN;
    for (int i = l; i <= r; i++) {
        if (ar[i] > ans) {
            ans = ar[i];
        }
    }
}
i
