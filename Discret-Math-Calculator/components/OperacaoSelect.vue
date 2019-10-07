<template>
<div>
  <label>
    Permutação
    <input value="permutacao"
      type="radio"
      name="operacao"
      v-model="model"
      @change="update(model)">
  </label>

  <label>
    Arranjo
    <input value="arranjo"
      type="radio"
      name="operacao"
      v-model="model"
      @change="update(model)">
  </label>

  <label>
    Análise Combinatória
    <input value="combinatoria"
      type="radio"
      name="operacao"
      v-model="model"
      @change="update">
  </label>
</div>
</template>

<script>
export default {
  props: ['value'],
  data () {
    return {
      model: this.value
    }
  },
  watch: {
    value (val) {
      this.model = val
    }
  },
  methods: {
    update () {
      this.$emit('input', this.model)
    }
  }
}
</script>

<style lang='scss' scoped>
  label {
    display: inline-flex;
    padding: 10px;
    margin: 20px 20px 40px;
    font-size: 18px;
    cursor: pointer;
  }
</style>
