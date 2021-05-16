#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// TODO
    ////

    delete _chatBot; 

    ////
    //// EOF TODO
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges.push_back(edge);
}

//// TODO
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF TODO

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// TODO
    ////

    return _childEdges[index];

    ////
    //// EOF TODO
}