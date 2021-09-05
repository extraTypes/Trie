#include <map>
#include <unordered_map>
#include <string>
#include <any>
#include <optional>
#include <utility>

using namespace std;



namespace T{
typedef pair<char, any> el;
typedef unordered_map<char, any> dict;
typedef map<char, any> ord_dict;
/**
 * @brief Abstract Node class. Not meant to be instantiated/used
 *
*/
class AbstractNode{
public:
    /**
     * Default constructor of Abstract Node
     */
    AbstractNode() = default;
    /**
     * @brief Abstract Node Constructor: initiate a node given a value
     * @param value value of the node
     */
    AbstractNode(any value){
        val = value;
    }

    /**
     * @brief Set the value of this Node
     * @param newVal the value to set the Node to
     */
    void setVal(any newVal){
        val = newVal;
    }

    /**
     * @brief Get the value of this Node
     * @returns the value of this Node
     */
    any getVal(){
        return val;
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
class OrderedNode : public AbstractNode{
public:
    /**
     * Default Constructor of Ordered Node
     */
    OrderedNode() = default;
    OrderedNode(any value) : AbstractNode(value) {
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
class Node : public AbstractNode{
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
 * In this implementation keys are stored chars
 * `O(m)` lookup type for keys where `m` is the length of the key.
 *
 * Supports Find and Insert operations.
 */
class Trie{
public:
    /**
     *
     */
     Trie(){
        root = OrderedNode{5};
    }

    /**
     * Finds the value of the key in the ordered Trie
     * @param key the key to find
     * @returns Value of the key if found, otherwise `nullptr`
     */
    any find(string key){
        if(root.getChildren().empty()) return nullptr; //trie is empty and has no keys
        OrderedNode cur = root;
        ord_dict children = cur.getChildren();
        for(char k: key){
            if(children.find(k) != children.end()){
                cur = any_cast<OrderedNode>(children.find(k));
                children = cur.getChildren();
            } else{ //could not find key
                return nullptr;
            }
        }
        return cur.getVal();
    }

    /**
     * Insert a key value pair into a trie.
     *
     * If the key already exists, performs an update operation instead.
     *
     * Note that keys are strings and values are of type std::any
     * @param key the key to the element
     * @param v the value the new element should hold.
     */
    void insert(string key, any v){
        OrderedNode cur = root;
        ord_dict children = cur.getChildren();
        for(char k: key){
            if(children.find(k) == children.end()){
                children.insert(el{k,OrderedNode{nullptr}});
            }
            cur = any_cast<OrderedNode>(children.find(k));
            children = cur.getChildren();
        }
        cur.setVal(v);
    }

    void delete()


    /**
     * Checks whether the tree contains any nodes
     * @returns Whether or not the tree is empty
     */
    bool isEmpty(){
        return root.getChildren().empty();
    }
private:
    /**
     * The root node of the tree
     */
    OrderedNode root;

//private:
//    int private_val;
};



} //end Namespace T
