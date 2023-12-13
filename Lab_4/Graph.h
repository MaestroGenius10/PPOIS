#include <iostream>
#include <vector>
#include <algorithm>

template <typename VertexValueType>
class Graph {
public:
    typedef VertexValueType value_type;
    typedef typename std::vector<value_type>::iterator vertex_iterator;
    typedef typename std::vector<std::pair<value_type, value_type>>::iterator edge_iterator;
    typedef typename std::vector<std::pair<value_type, value_type>>::iterator incident_edge_iterator;
    typedef typename std::vector<value_type>::iterator adjacent_vertex_iterator;

    bool containsVertex(const value_type& vertex) {
        return std::find(vertices.begin(), vertices.end(), vertex) != vertices.end();
    }

    bool containsEdge(const value_type& source, const value_type& destination) {
        return std::find(edges.begin(), edges.end(), std::make_pair(source, destination)) != edges.end();
    }

    size_t numVertices() const {
        return vertices.size();
    }

    size_t numEdges() const {
        return edges.size();
    }

    size_t degree(const value_type& vertex) const {
        return std::count_if(edges.begin(), edges.end(),
            [vertex](const std::pair<value_type, value_type>& edge) {
                return edge.first == vertex;
            });
    }

    size_t edgeDegree(const value_type& source, const value_type& destination) const {
        return std::count(edges.begin(), edges.end(), std::make_pair(source, destination));
    }

    void addVertex(const value_type& vertex) {
        vertices.push_back(vertex);
    }

    void addEdge(const value_type& source, const value_type& destination) {
        edges.push_back(std::make_pair(source, destination));
        edges.push_back(std::make_pair(destination, source));
        std::sort(edges.begin(), edges.end());
    }

    void removeVertex(const value_type& vertex) {
        vertices.erase(std::remove(vertices.begin(), vertices.end(), vertex), vertices.end());
        edges.erase(std::remove_if(edges.begin(), edges.end(),
            [vertex](const std::pair<value_type, value_type>& edge) {
                return edge.first == vertex || edge.second == vertex;
            }), edges.end());
    }

    void removeEdge(const value_type& source, const value_type& destination) {
        edges.erase(std::remove(edges.begin(), edges.end(), std::make_pair(source, destination)), edges.end());
        edges.erase(std::remove(edges.begin(), edges.end(), std::make_pair(destination, source)), edges.end());
    }

    vertex_iterator beginVertices() {
        return vertices.begin();
    }

    vertex_iterator endVertices() {
        return vertices.end();
    }

    edge_iterator beginEdges() {
        return edges.begin();
    }

    edge_iterator endEdges() {
        return edges.end();
    }

    incident_edge_iterator beginIncidentEdges(const value_type& vertex) {
        return std::lower_bound(edges.begin(), edges.end(), std::make_pair(vertex, value_type()));
    }

    incident_edge_iterator endIncidentEdges(const value_type& vertex) {
        return std::upper_bound(edges.begin(), edges.end(), std::make_pair(vertex, value_type()));
    }

    adjacent_vertex_iterator beginAdjacentVertices(const value_type& vertex) {
        return std::remove_if(vertices.begin(), vertices.end(),
            [vertex, this](const value_type& v) {
                return !containsEdge(vertex, v);
            });
    }

    adjacent_vertex_iterator endAdjacentVertices(const value_type& vertex) {
        return std::remove_if(vertices.begin(), vertices.end(),
            [vertex, this](const value_type& v) {
                return !containsEdge(vertex, v);
            });
    }

    vertex_iterator removeVertex(vertex_iterator it) {
        value_type vertex = *it;
        it = vertices.erase(it);

        edges.erase(std::remove_if(edges.begin(), edges.end(),
            [vertex](const std::pair<value_type, value_type>& edge) {
                return edge.first == vertex || edge.second == vertex;
            }), edges.end());

        return it;
    }

    edge_iterator removeEdge(edge_iterator it) {
        value_type source = it->first;
        value_type destination = it->second;
        it = edges.erase(it);
        edges.erase(std::remove(edges.begin(), edges.end(), std::make_pair(destination, source)), edges.end());

        return it;
    }

    vertex_iterator rbeginVertices() {
        return vertices.rbegin();
    }

    vertex_iterator rendVertices() {
        return vertices.rend();
    }

    edge_iterator rbeginEdges() {
        return edges.rbegin();
    }

    edge_iterator rendEdges() {
        return edges.rend();
    }

    incident_edge_iterator rbeginIncidentEdges(const value_type& vertex) {
        return std::upper_bound(edges.begin(), edges.end(), std::make_pair(vertex, value_type()));
    }

    incident_edge_iterator rendIncidentEdges(const value_type& vertex) {
        return std::lower_bound(edges.begin(), edges.end(), std::make_pair(vertex, value_type()));
    }

    adjacent_vertex_iterator rbeginAdjacentVertices(const value_type& vertex) {
        return std::remove_if(vertices.begin(), vertices.end(),
            [vertex, this](const value_type& v) {
                return !containsEdge(vertex, v);
            }).base();
    }

    adjacent_vertex_iterator rendAdjacentVertices(const value_type& vertex) {
        return std::remove_if(vertices.begin(), vertices.end(),
            [vertex, this](const value_type& v) {
                return !containsEdge(vertex, v);
            }).base();
    }

    vertex_iterator removeVertexReverse(vertex_iterator it) {
        value_type vertex = *it;
        it = vertices.erase(it);
        edges.erase(std::remove_if(edges.begin(), edges.end(),
            [vertex](const std::pair<value_type, value_type>& edge) {
                return edge.first == vertex || edge.second == vertex;
            }), edges.end());

        return it;
    }

    edge_iterator removeEdgeReverse(edge_iterator it) {
        value_type source = it->first;
        value_type destination = it->second;
        it = edges.erase(it);
        edges.erase(std::remove(edges.begin(), edges.end(), std::make_pair(destination, source)), edges.end());

        return it;
    }
private:
    std::vector<value_type> vertices;
    std::vector<std::pair<value_type, value_type>> edges;
};