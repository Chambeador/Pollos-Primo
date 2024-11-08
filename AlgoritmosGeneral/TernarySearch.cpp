#include <bits/stdc++.h>
using namespace std;
/*
 *   *
 *
 *
 * */

//   ar vector que contiene a la funcion

void ternarySearchMaximo() {
    int l = 0;
    r = n - 1, m1, m2;
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
void ternarySearchMin() {
    int l = 0;
    r = n - 1, m1, m2;
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
    int ans = INT_MAX;
    for (int i = l; i <= r; i++) {
        if (ar[i] < ans) {
            ans = ar[i];
        }
    }
}

