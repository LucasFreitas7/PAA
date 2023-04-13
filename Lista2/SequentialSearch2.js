function sequentialSearch2(arr, value) {
    for (let i = arr.length - 1; i >= 0; i--) {
      if (arr[i] === value) {
        return i;
      }
    }
    return -1;
  }

  let arr = [2, 5, 1, 3, 7, 8];
  console.log(sequentialSearch2(arr, 3));
  console.log(sequentialSearch2(arr, 6));


// Aqui poderemos adotar a comparação como trecho de codigo que mais se repatira, que estara dentro de um for.
// Com isso teremos um somatorio ∑ n 
// ao expandirmos em relação a n-1, n-2 veremos que podemos concluir que a complexidade do caso será O(n)
