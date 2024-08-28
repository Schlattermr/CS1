/**
 * Frees the given (n x k) table
 */
void freeTable(long **table, int n, int k);

/**
 * Recursive function that takes values n and k and
 * computes a binomial using Pascal's Rule:
 * (n k) = (n!)/((n - k)! * k!)
 */
long choose(int n, int k);

/**
 * Recursive memoization function that takes values n and k and
 * computes a binomial using Pascal's Rule:
 * (n) = (n - 1) + (n - 1)
 * (k)   (  k  )   (k - 1)
 */
long chooseMemoization(int n, int k, long **cache);