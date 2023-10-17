//
// Created by zhou on 2023/10/11.
//
#include "../utils/common.h"

class GraphAdjMat {
    // 顶点表，元素代表顶点值，索引代表顶点索引
    vector<int> vertices;
    // 邻接矩阵，行列索引对应顶点索引（边连接的两顶点索引）
    vector<vector<int>> adjMat;

public:
    GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges) {
        // vector<int> vertices = {1, 3, 2, 5, 4};
        for (int val : vertices) {
            addVertex(val);
        }
        for (const vector<int> &edge: edges) {
            // ?? 为什么是 0 1 索引
            // 示例：vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {2, 3}, {2, 4}, {3, 4}};
            // edges存的是顶点索引，[i][j]表示的是i到j的边
            addEdge(edge[0], edge[1]);
        }
    }

    int size() const {
        return vertices.size();
    }

    /**
     * 添加顶点
     */
    void addVertex(int val) {
        int n = size();
        // 将顶点入列表
        vertices.push_back(val);
        // 矩阵新建一行
        adjMat.emplace_back(vector<int>(n, 0));
        // 矩阵新建一列
        for (vector<int> &rows : adjMat) {
            rows.push_back(0);
        }
    }

    /**
     * 添加边
     */
    void addEdge(int i, int j) {
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
            throw out_of_range("顶点不存在");
        }
        // 无向图，关于主对角线对称
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    /**
     * 删除顶点
     */
    void removeVertex(int index) {
        if(index >= size()) throw out_of_range("顶点不存在");
        // 删除顶点
        vertices.erase(vertices.begin() + index);
        // 删除对应的行
        adjMat.erase(adjMat.begin() + index);
        // 删除对应的列
        for (vector<int> &rows: adjMat) {
            rows.erase(rows.begin() + index);
        }
    }

    void removeEdge(int i, int j) {
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
            throw out_of_range("顶点不存在");
        }
        // 无向图，关于主对角线对称
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }
};