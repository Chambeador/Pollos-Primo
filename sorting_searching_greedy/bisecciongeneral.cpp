double bisection(double a, double b) {
  if (eval(a) * eval(b) >= 0) {
    // no establecemos bien los limites de evaluacion
    return -INF;
  }

  double c = a;
  while ((b - a) >= EPS) {
    // punto medio:
    c = (a + b) / 2;

    // si encontramos justo la solucion
    if (eval(c) == 0.0)
      break;

    // biseccion:
    else if (eval(c) * eval(a) < 0)
      b = c;
    else
      a = c;
  }
  // el valor de una raiz esta en c
  return c;
}