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

bool LogicalOperationNode::Evaluate(const Date&, const std::string&){
	return true;
};