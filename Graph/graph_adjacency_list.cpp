//
// Created by zhou on 2023/10/13.
//
#include "../utils/common.h"

class GraphAdjacencyList{
public:
    // key:是顶点，value：是对应的链表（即所有邻接节点）
    unordered_map<Vertex *, vector<Vertex *>> adjList;

    // 删除对应的顶点和边（邻接表中边其实依赖于顶点，把各自的顶点删除，就相当于把两点之间的边删除了）
    void remove(vector<Vertex *> vec, Vertex *vet) {
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] == vet) vec.erase(vec.begin() + i);
            break;
        }
    }

    // ??
    GraphAdjacencyList(const vector<vector<Vertex *>> &edges) {
        // 添加所有的顶点和边
        for(const vector<Vertex *> &edge : edges) {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }

    int size() {
        return adjList.size();
    }

    /**
     * 添加顶点
     */
    void addVertex(Vertex *vet) {
        // 已有顶点，直接结束。不能重复
        if (adjList.count(vet)) return;
        // 未有顶点，在新顶点后面新建链表
        adjList[vet] = vector<Vertex *>();
    }

    /**
     * 添加边
     */
    void addEdge(Vertex *vet1, Vertex *vet2) {
        // 没有相应的顶点或者是同一个顶点，异常处理
        if(!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2) {
            throw invalid_argument("顶点不存在");
        }
        // 添加相应的边，即在对应的链表中分别加入其节点
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    /**
     * 删除顶点
     */
    void removeVertex(Vertex *vet) {
        // 没有相应的顶点，无需删除
        if(!adjList.count(vet)) throw invalid_argument("顶点不存在");
        // 删除头节点及其边，相当于删除头节点及其后面的链表
        adjList.erase(vet);
        // second是找value，first找key;
        // 遍历剩余的顶点及后面的链表，找到与要删除的顶点，将其删除
        for (auto &item: adjList) {
            remove(item.second, vet);
        }
    }

    /**
     * 删除边
     */
    void removeEdge(Vertex *vet1, Vertex *vet2) {
        if(!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2) {
            throw invalid_argument("顶点不存在");
        }
        // 将其从对方的链表中删除，即实现了删除边
        remove(adjList[vet1], vet2);
        remove(adjList[vet2], vet1);
    }
};