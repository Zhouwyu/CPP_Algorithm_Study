//
// Created by zhou on 2023/10/16.
//
#include "../utils/common.h"
#include "./graph_adjacency_list.cpp"

vector<Vertex *> bfs(GraphAdjacencyList &graph, Vertex *startVet) {
    // 队列用于辅助实现bfs
    queue<Vertex *> vertexQueue;
    // 访问哈希表，用于记录当前顶点是否已被访问
    unordered_set<Vertex *> visited = {startVet};
    // 顶点遍历序列
    vector<Vertex *> res;
    // 先把初始出发的顶点入队
    vertexQueue.push(startVet);
    // 当队列非空
    while (!vertexQueue.empty()) {
        // 先把队头顶点存储
        Vertex *topVet = vertexQueue.front();
        // 出队
        vertexQueue.pop();
        // 访问顶点
        res.push_back(topVet);
        // 寻找邻接点
        for(Vertex *adjVet : graph.adjList[topVet]) {
            // 邻接点已被访问过的，继续找其它邻接点
            if (visited.count(startVet)) continue;
            // 未被访问过的，入队
            vertexQueue.push(adjVet);
            // 标记为已访问
            visited.emplace(adjVet);
        }
    }
    return res;
}