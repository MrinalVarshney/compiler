#include "backend.h"
#include <iostream>

std::set<std::string> Backend::new_scope_labels = {BLOCK, IFSTAT, LOOP};

void Backend::traverse(Node* node)
{
    if (node == NULL) {
        return;
    }

    if (introduces_new_scope(node)) {
        var_stack.push();
    }

    check_for_variables(node);
    
    traverse_children(node);

    if (introduces_new_scope(node)) {
        var_stack.pop();
    }
}

void Backend::check_for_variables(Node* node)
{
    std::vector<Token> id_tokens = node->get_identifier_tokens();

    for (auto id_token : id_tokens) {
        if (contains_variable_declarations(node)) {
            int location = var_stack.find(id_token);
            if (location == 0) {
                std::string msg = "Duplicate variable declaration";
                print_error_and_exit(msg, id_token);
            }
            var_stack.insert(id_token);
        } else {
            int location = var_stack.find(id_token);
            if (location == -1) {
                std::string msg = "Undeclared variable";
                print_error_and_exit(msg, id_token);
            }
        }
    }
}

void Backend::print_error_and_exit(std::string msg, Token token)
{
    std::cerr << msg << " " << token << std::endl;
    exit(EXIT_FAILURE);
}

void Backend::traverse_children(Node* node)
{
    std::vector<Node*> children = node->children;
    for (unsigned int i = 0; i < children.size(); i++) {
        traverse(children.at(i));
    }
}

bool Backend::introduces_new_scope(Node* node)
{
    return new_scope_labels.count(node->label) == 1;
}

bool Backend::contains_variable_declarations(Node* node)
{
    return node->label == VARS;
}
