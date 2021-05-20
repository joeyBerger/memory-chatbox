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

//     delete _chatBot; 

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

// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// TODO
////
// void GraphNode::MoveChatbotHere(ChatBot *chatbot)
// void MoveChatbotHere(std::unique_ptr<ChatBot> chatbot)
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
//     _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF TODO

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// TODO
    ////

//     return _childEdges[index];
    return _childEdges[index].get();
  

    ////
    //// EOF TODO
}