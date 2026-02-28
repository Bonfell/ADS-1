// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i <= static_cast<int>(std::sqrt(n)); i += 2) {
        if (n % i == 0) {
            return false; 
        }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) {
        return 0; 
    }
    uint64_t count = 0;       
    uint64_t candidate = 2;  
    while (count < n) {
        bool isPrime = true;
        if (candidate <= 1) {
            isPrime = false;
        } else if (candidate == 2) {
            isPrime = true;
        } else if (candidate % 2 == 0) {
            isPrime = false;
        } else {
            uint64_t limit = static_cast<uint64_t>(std::sqrt(candidate));
            for (uint64_t i = 3; i <= limit; i += 2) {
                if (candidate % i == 0) {
                    isPrime = false;  
                    break;
                }
            }
        }
        if (isPrime) {
            count++;
            if (count == n) {
                return candidate;
            }
        }

        candidate++;  
    }

    return 2; 
}

uint64_t nextPrime(uint64_t value) {
    uint64_t candidate = value + 1; 
    while (true) {
        if (candidate <= 1) {
        } else if (candidate == 2) {
            return 2; 
        } else if (candidate % 2 == 0) {
        } else {
            bool isPrime = true;
            uint64_t limit = static_cast<uint64_t>(std::sqrt(candidate));
            for (uint64_t i = 3; i <= limit; i += 2) {
                if (candidate % i == 0) {
                    isPrime = false; 
                    break;
                }
            }
            if (isPrime) {
                return candidate; 
            }
        }
        candidate++; 
    }
    return 2;
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound <= 2) {
        return 0; 
    }
    uint64_t sum = 0;
    for (uint64_t num = 2; num < hbound; ++num) {
        bool isPrime = true;
        if (num == 2) {
            isPrime = true; 
        } else if (num % 2 == 0) {
            isPrime = false; 
        } else {
            uint64_t limit = static_cast<uint64_t>(std::sqrt(num));
            for (uint64_t i = 3; i <= limit; i += 2) {
                if (num % i == 0) {
                    isPrime = false; 
                    break;
                }
            }
        }
        if (isPrime) {
            sum += num; 
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    if (hbound - lbound < 2) {
        return 0;
    }
    uint64_t count = 0;
    for (uint64_t p = lbound; p <= hbound - 3; ++p) {
        uint64_t q = p + 2;
        bool isPPrime = true;
        bool isQPrime = true;
        if (p <= 1) {
            isPPrime = false;
        } else if (p == 2) {
            isPPrime = true;
        } else if (p % 2 == 0) {
            isPPrime = false;
        } else {
            uint64_t limit = static_cast<uint64_t>(sqrt(p));  
            for (uint64_t i = 3; i <= limit; i += 2) {
                if (p % i == 0) {
                    isPPrime = false;
                    break;
                }
            }
        }
        if (q <= 1) {
            isQPrime = false;
        } else if (q == 2) {
            isQPrime = true;
        } else if (q % 2 == 0) {
            isQPrime = false;
        } else {
            uint64_t limitQ = static_cast<uint64_t>(sqrt(q));
            for (uint64_t i = 3; i <= limitQ; i += 2) {
                if (q % i == 0) {
                    isQPrime = false;
                    break;
                }
            }
        }
        if (isPPrime && isQPrime) {
            count++;
        }
    }
    return count;
}
