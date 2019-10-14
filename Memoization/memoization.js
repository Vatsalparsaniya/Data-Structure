/**
 * MEMOIZATION IN JAVASCRIPT
 * At time passes, our applications grows and start handle heavier
 * computations. To avoid this we can implement this technique called 'Memoization'
 *
 * This technique just store the results of function calls and returned
 * the cached result if this function was called before.
 *
 * PERFORMANCE RESULT:
 * You can see in action the gained performance on:
 * https://jsperf.com/scotch-memoization-test
 */

/**
 *
 * The best example to see memoization in action is the
 * famous fibonacci function that we implement as recursive
 */
function fibonacci(n) {
  if (n <= 1) return 1;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

//ES6 version
const fibonacci = n => {
  if (n <= 1) return 1;

  return fibonacci(n - 1) + fibonacci(n - 2);
};

/**
 * WITH MEMOIZATION
 *
 * The memo object is passed as argument on each function call
 * so we can access to stored values and return them when the function
 * gonna repeat the same operation that we already did previously.
 */

function fibonacci(n, memo) {
  memo = memo || {};

  if (memo[n]) return memo[n];

  if (n <= 1) return 1;

  return (memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo));
}

//ES6 version
const fibonacci = (n, memo) => {
  memo = memo || {};

  if (memo[n]) return memo[n];

  if (n <= 1) return 1;

  return (memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo));
};
