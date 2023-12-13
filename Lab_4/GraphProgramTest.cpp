#include "pch.h"
#include"..\GraphProgram\Graph.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphProgramTest
{
	TEST_CLASS(GraphProgramTest)
	{
	public:
		
		TEST_METHOD(TestAddVertex)
		{
			Graph<int> graph;
			graph.addVertex(1);

			Assert::IsTrue(graph.containsVertex(1));
			Assert::AreEqual(size_t(1), graph.numVertices());
		}
	
        TEST_METHOD(TestAddEdge)
        {
            Graph<int> graph;
            graph.addVertex(1);
            graph.addVertex(2);
            graph.addEdge(1, 2);

            Assert::IsTrue(graph.containsEdge(1, 2));
            Assert::IsTrue(graph.containsEdge(2, 1));
            Assert::AreEqual(size_t(2), graph.numEdges());
        }

        TEST_METHOD(TestRemoveVertex)
        {
            Graph<int> graph;
            graph.addVertex(1);
            graph.addVertex(2);
            graph.addEdge(1, 2);
            graph.removeVertex(1);

            Assert::IsFalse(graph.containsVertex(1));
            Assert::AreEqual(size_t(1), graph.numVertices());
            Assert::AreEqual(size_t(0), graph.numEdges());
        }

        TEST_METHOD(TestRemoveEdge)
        {
            Graph<int> graph;
            graph.addVertex(1);
            graph.addVertex(2);
            graph.addEdge(1, 2);
            graph.removeEdge(1, 2);

            Assert::IsFalse(graph.containsEdge(1, 2));
            Assert::AreEqual(size_t(0), graph.numEdges());
        }

        TEST_METHOD(TestDegree)
        {
            Graph<int> graph;
            graph.addVertex(1);
            graph.addVertex(2);
            graph.addVertex(3);
            graph.addEdge(1, 2);
            graph.addEdge(2, 3);
            Assert::AreEqual(size_t(1), graph.degree(1));
            Assert::AreEqual(size_t(2), graph.degree(2));
        }
        TEST_METHOD(TestNumberVertex)
        {
            Graph<int> graph;
            graph.addVertex(1);
            graph.addVertex(2);
            Assert::AreEqual(size_t(2), graph.numVertices());
        }
    };
}


