#include "node.h"

bool EmptyNode::Evaluate(const Date& d, const std::string& s)const {
	return true;
};

bool DateComparisonNode::Evaluate(const Date& d, const std::string& s)const {
	return true;
};

bool EventComparisonNode::Evaluate(const Date& d, const std::string& s)const {
	return true;
};

LogicalOperationNode::LogicalOperationNode(const LogicalOperation l, const std::shared_ptr<Node> operation, const std::shared_ptr<Node> left) {

};
bool LogicalOperationNode::Evaluate(const Date& d, const std::string& s)const {
	return true;
};