function calculaPermutacao (n) {
    let resultado = 1
    for (let x = n; x > 1; x--) {
      resultado = resultado * x
    }
    return resultado
  }

  function calculaArranjo (n, p) {
    let resultadoDeN = 1
    for (let x = n; x > 1; x--) {
      resultadoDeN = resultadoDeN * x
    }
    let denominador = n - p
    let resultadoDenominador = 1
    for (let y = denominador; y >= 1; y--) {
      resultadoDenominador = resultadoDenominador * y
    }
    let resultadoFinal = resultadoDeN / resultadoDenominador
    return resultadoFinal
  }

  function calculaCombinatoria (n, p) {
    let resultadoDeN = 1

    for (let x = n; x > 1; x--) {
      resultadoDeN = resultadoDeN * x
    }

    let resultadoDeP = 1
    for (let y = p; y > 1; y--) {
      resultadoDeP = resultadoDeP * y
    }

    let parentesisDenominador = n - p
    let resultadoParentesis = 1
    for (let w = parentesisDenominador; w >= 1; w--) {
      resultadoParentesis = resultadoParentesis * w
    }

    let resultadoFinalDenominador = resultadoDeP * resultadoParentesis
    let resultadoFinal = resultadoDeN / resultadoFinalDenominador
    return resultadoFinal
  }

  export { calculaArranjo, calculaCombinatoria, calculaPermutacao }
