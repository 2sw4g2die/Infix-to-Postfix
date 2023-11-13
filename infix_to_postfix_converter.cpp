/*
* infix_to_postfix_converter.cpp
* Written by : Lana Cossettini (c3436542)
* Modified : 09/09/2023
*
* This class represents the infix to postfix expression converter.
* This file should be used in conjunction with Assignment 2 for SENG1120.
*/
#include "infix_to_postfix_converter.h"

infix_to_postfix_converter::infix_to_postfix_converter(std::string& input) 
{
    infix = input;
    convert_to_postfix(infix);
}

infix_to_postfix_converter::~infix_to_postfix_converter()
{
    
}

const std::string& infix_to_postfix_converter::get_infix() const
{
    return infix;
}

const std::string&  infix_to_postfix_converter::get_postfix() const 
{
    return postfix;
}

int  infix_to_postfix_converter::precedence(char op) const
{
    //determines the precedence of an opperator
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

std::string  infix_to_postfix_converter::convert_to_postfix(std::string& input)
{
    LStack<char> stack;
    LQueue<char> queue;

    int index = 0;
    int length = input.length();

    while (index < length)
    {
        char sym = input[index];
        // ignores space characters
        if (sym == ' ')
        {
            index++;
            continue;
        }
        //enqueues symbols if they are an opperand
        if (std::isalnum(sym))
        {
            queue.enqueue(sym);
        }
        //pushes left parenthesis to stack
        else if (sym == '(') 
        {
            stack.push(sym);
        }
        /* pops and enqueues all symbols after a right parenthesis
        from stack to queue until a left parenthesis is encountered */
        else if (sym == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                queue.enqueue(stack.top()); //enques top of stack
                stack.pop();
            }
            if (!stack.empty() && stack.top() == '(')
            {
                stack.pop(); // left parenthesis discarded
            }
        }
        /* Pops and enqueues all the operators from stack to queue that 
        are above the most recent left parenthesis and have precedence 
        greater than or equal to the current symbol.*/
        else if (sym == '+' || sym == '-' || sym == '*' || sym == '/')
        {
            while (!stack.empty() && stack.top() != '(' && precedence(sym) <= precedence(stack.top())) 
            {
                queue.enqueue(stack.top());
                stack.pop();
            }
            stack.push(sym);
        }
        // error for any invalid character
        else
        {
            throw std::invalid_argument("Invalid character used");
        }
        index++; // moves to the next character
    }

    //pops and enqueues anything left on stack
    while (!stack.empty())
    {
        queue.enqueue(stack.top());
        stack.pop();
    }

    //dequeues characters and builds postfix string
    std::string data;
    while (!queue.empty())
    {
        data += queue.front();
        queue.dequeue();
    }
    postfix = data;
    return postfix;
}
