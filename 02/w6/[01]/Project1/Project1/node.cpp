#include "node.h"

bool EmptyNode::Evaluate(const Date&, const std::string&){
	return true;
};

bool DateComparisonNode::Evaluate(const Date&, const std::string&){
	return true;
};

bool EventComparisonNode::Evaluate(const Date&, const std::string&){
	return true;
};

LogicalOperationNode::LogicalOperationNode(const LogicalOperation lo, const Node& operation, const Node& left) {

};

bool LogicalOperationNode::Evaluate(const Date&, const std::string&){
	return true;
};