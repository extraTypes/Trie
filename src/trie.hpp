#include <map>
#include <unordered_map>
#include <string>
#include <any>
#include <optional>
#include <utility>

using namespace std;

typedef unordered_map<string, any> dict;
typedef map<string, any> ord_dict;

namespace T{
/**
 * @brief Abstract Node class. Not meant to be instantiated/used
 *
*/
class AbstractNode{
public:
    /**
     * @brief Abstract Node Constructor: initiate a node given a value
     * @param value value of the node
     */
    explicit AbstractNode(any value){
        val = move(value);
    }
    /**
     * @brief Get the value of this Node
     * @returns the value of this Node
     */
    any getVal(){
        return val;
    }

    /**
     * @brief Set the value of this Node
     * @param newVal the value to set the Node to
     */
    void setVal(any newVal){
        val = move(newVal);
    }

protected:
    /**
     * @brief Internal value of the Node
     */
    any val;
};


/**
*
*/
class OrderedNode : private AbstractNode{
public:
    explicit OrderedNode(any value) : AbstractNode(value) {
        children = ord_dict {};
    }
    /**
     * @brief Gets the children of an OrderedNode
     * @returns the children of an OrderedNode
     */
    ord_dict getChildren(){
        return children;
    }
private:
    /**
     * Children of the Node, ordered lexicographically
     */
    ord_dict children;
};

/**
*
*/
class Node : private AbstractNode{
public:
    explicit Node(any value) : AbstractNode(value){
        children = dict{};
    }
    /**
     * @brief Gets the children of a Node
     * @returns the children of Node
     */
    dict getChildren(){
        return children;
    }
private:
    /**
     * @brief Children of the Node, stored in no particular order
     */
    dict children;
};


/**
 * @brief Type of Search tree, specialized for locating specific keys.
 *
 * In this implementation keys are stored as strings.
 * `O(m)` lookup type for keys where `m` is the length of the key.
 *
 * Supports Find and Insert operations.
 */
class Trie{
public:
    /**
     * Default constructor for Trie, does not intialize root to some Node
     */
    Trie()= default;



    /**
     * Checks whether the tree contains any nodes
     * @returns Whether or not the tree is empty
     */
    bool isEmpty(){
        return !root;
    }
private:
    /**
     * The root of the tree
     */
    optional<AbstractNode> root;

//private:
//    int private_val;
};



} //end Namespace T
