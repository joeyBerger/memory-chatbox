#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// TODO : Move to cpp
    ////
    ChatBot(ChatBot &&source)
    {
        std::cout << "Moving constructed instance " << &source << " to instance " << this << std::endl;
        *_image = *source._image;
//         *_currentNode = *source._currentNode;
//         *_rootNode = *source._rootNode;
//         *_chatLogic = *source._chatLogic;      
        source._image = nullptr;
    }
    
	ChatBot &operator=(ChatBot &&source)
    {
        std::cout << "Moving assigned instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;

        delete[] _image;

        _image = source._image;

        source._image = nullptr;

        return *this;
    }
    ////
    //// EOF TODO

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
