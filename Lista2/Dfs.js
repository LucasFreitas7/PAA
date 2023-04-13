function dfs(graph, startNode, endNode, visited = new Set(), path = []) {
    visited.add(startNode); // adicionando ao visitados o no inicial
    path.push(startNode); // coloca no caminho o no inicial
  
    if (startNode === endNode) {
      return path;
    }
  
    for (let neighbor of graph[startNode]) {
      if (!visited.has(neighbor)) {
        let newPath = dfs(graph, neighbor, endNode, visited, path.slice()); //fazemos uma chamada recursiva à função dfs com o vizinho como novo nó inicial, 
        //o nó final, o conjunto visited atualizado e uma cópia do array path
        if (newPath) { 
          return newPath; //caso a chamada retorne algo diferente de null, retornarmos o caminho
        }
      }
    }
  
    return null;
  }

  let graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': ['E'],
    'E': ['F'],
    'F': []
  };
  
  console.log(dfs(graph, 'A', 'F'))

    // Função de custo = ((m^h) - 1)/ m-1 onde h é a altura da arvore, ao simplificar essa expressão temos O(m^h).