function selectionSort(arr) {
  for (let i = 0; i < arr.length - 1; i++) {
    let minIndex = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex !== i) {
      let temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
  return arr;
}

let arr = [5, 2, 4, 6, 1, 3]
console.log(selectionSort(arr))


// Selection sort função de custo, teremos dois loops que serão executados 2 vezes e podemos adotar assim 2 somatorios alinhados de n. ∑ ∑ n 
// Expandindo a função de custo chegaremos em (n * (n + 1)) / 2.
// A complexidade do algoritmo em relação a tempo seria O (n^2)