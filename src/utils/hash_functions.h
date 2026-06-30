#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H
#define Z 31 // 31 es estandar para el algoritmo de acumulacion polinomial
#include <string>
// sumamos las primeras 32 y 
#include <cstdint>

//dividimos un long en pedazos de 8 bits y calculamos la suma
inline unsigned int componentSum(uint64_t i) {
    return (unsigned char)(i)       +
           (unsigned char)(i >> 8)  +
           (unsigned char)(i >> 16) +
           (unsigned char)(i >> 24) +
           (unsigned char)(i >> 32) +
           (unsigned char)(i >> 40) +
           (unsigned char)(i >> 48) +
           (unsigned char)(i >> 56);
}

//evaluamos el polinomio usando la regla de horner
inline unsigned int polynomialAccumulation(std::string s) {
  unsigned int h = 0;
  for (auto c : s) {
    h = c + h * Z;
  }
  return h;
}
#endif
