function bfs(graph, startNode, endNode) {
    let visited = {}; //controla os nós que ja foram visitados
    let queue = [[startNode, [startNode]]]; //armazenar os nós a serem visitados e seus caminhos correspondentes
  
    while (queue.length > 0) {
      let [currentNode, path] = queue.shift();
      if (!visited[currentNode]) {
        visited[currentNode] = true;
  
        if (currentNode === endNode) {
          return path;
        }
  
        for (let neighbor of graph[currentNode]) {
          queue.push([neighbor, [...path, neighbor]]); 
          // Para cada vizinho, adicionamos o vizinho na fila queue 
          // caminho até esse vizinho, que é o caminho atual mais o vizinho
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
  
  console.log(bfs(graph, 'A', 'E'))

  // Função de custo = ((m^h) - 1)/ m-1 onde h é a altura da arvore, ao simplificar essa expressão temos O(m^h).