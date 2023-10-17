//
// Created by zhou on 2023/10/16.
//
#include "../utils/common.h"
#include "./graph_adjacency_list.cpp"

void dfs(GraphAdjacencyList &graph, unordered_set<Vertex *> &visited, vector<Vertex *> &res, Vertex *vet) {
    // 访问当前的顶点
    res.push_back(vet);
    // 标记为已访问
    visited.emplace(vet);
    // 寻找当前顶点的邻接点
    for(Vertex *adjVet : graph.adjList[vet]) {
        // 已访问的跳过
        if (visited.count(vet)) continue;
        // 从邻接点开始递归操作，继续访问邻接顶点
        dfs(graph, visited, res, adjVet);
    }
}

vector<Vertex *> graphDfs(GraphAdjacencyList &graph, Vertex *startVet) {
    // 用于存储遍历的顶点序列
    vector<Vertex *> res;
    // 哈希表标记顶点是否已被访问
    unordered_set<Vertex *> visited;
    // 深度优先搜索
    dfs(graph, visited, res, startVet);
    return res;
}