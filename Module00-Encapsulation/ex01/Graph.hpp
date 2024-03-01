#pragma once

#include "Vector2.hpp"
#include <iostream>
#include <set>

class Graph
{
private:
    std::set<Vector2 *> vertices;

    Graph(const Graph& p_graph);
    Graph& operator=(const Graph& p_graph);
public:

    Graph();
    ~Graph();

    void addVertex(float x, float y);
    void clear();
    void print() const;

    class InvalidVertexException : public std::exception
    {
        public:
            const char * what(void) const throw();
    };

    class AlreadyExistingVertexException : public std::exception
    {
        public:
            const char * what(void) const throw();
    };
};

std::ostream& operator<< (std::ostream& p_os, const Graph& p_graph);