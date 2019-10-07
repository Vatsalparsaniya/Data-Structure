<template>

  <body>
    <div class="body-app" id="app">
      <OperacaoSelect v-model="operacao" />
      <div>
        <div v-if="operacao === 'permutacao'">
          <input placeholder="Informe o valor de n" v-model="n">
          <div class="button-resultado">
          <button
            type="button"
            @click="result">
            Calcular
          </button>
          </div>
        </div>

        <div v-if="operacao === 'arranjo'">
          <input placeholder="Informe o valor de n" v-model="n">
          <input placeholder="Informe o valor de p" v-model="p">
          <div class="button-resultado">
          <button
            type="button"
            @click="result">
            Calcular
          </button>
          </div>
        </div>

        <div v-if="operacao === 'combinatoria'">
          <input placeholder="Informe o valor de n1" v-model="n">
          <input placeholder="Informe o valor de p1" v-model="p">
          <div class="button-resultado">
          <button
            type="button"
            @click="result">
            Calcular
          </button>

          </div>
        </div>
      </div>

      <span>
        <p id="resultado">
        {{ resultado }}
        </p>
      </span>

      <!-- <div class="lds-spinner" id="loader">
        <orbit-spinner
          :animation-duration="1200"
          :size="55"
          :color="'blue'"
        />
      </div> -->

    </div>
  </body>

</template>

<script>
import OperacaoSelect from './components/OperacaoSelect'
import { calculaPermutacao, calculaArranjo, calculaCombinatoria } from './utils/calc'
/* import { OrbitSpinner } from 'epic-spinners' */

export default {
  name: 'app',
  components: {
    OperacaoSelect
    /* OrbitSpinner */
  },
  data () {
    return {
      operacao: '',
      n: null,
      p: null,
      resultado: null
    }
  },
  methods: {
    result () {
      if (this.operacao === 'permutacao') {
        this.resultado = calculaPermutacao(this.n)
      } else if (this.operacao === 'arranjo') {
        this.resultado = calculaArranjo(this.n, this.p)
      } else if (this.operacao === 'combinatoria') {
        this.resultado = calculaCombinatoria(this.n, this.p)
      }
    }
  }
}
</script>

<style lang='scss' scoped>
  body {
    width: 100%;;
    display: flex;
    align-content: center;
    justify-content: center;
    text-align: center;
  }

  .body-app {
    border: solid rgb(147, 147, 236);
    margin-top: 20px;
    padding: 20px;
  }

  input {
    border: none;
    border-bottom: solid 2px rgb(147, 147, 236);
    margin: 5px ;
    min-width: 30%;
    text-align: center;
    font-size: 18px;
  }

  button {
    display: inline-block;
    background-color: rgb(147, 147, 236);
    color: white;
    border: none;
    min-width: 30%;
    margin: 50px 0;
    padding: 0.3em;
    font-size: 18px;
    cursor: pointer;
  }

  .lds-spinner {
    display: inline-block;
    position: relative;
    width: 60px;
    height: 60px;
  }

  #resultado {
    font-size: 20px;
  }
</style>
