/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:54:30 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/11/21 12:26:43 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

static void printConstStack(const MutantStack<int>& stack)
{
	MutantStack<int>::const_iterator it = stack.begin();
	MutantStack<int>::const_iterator ite = stack.end();

	std::cout << "Const iteration: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "=== 1. TESTE DO ENUNCIADO (MutantStack) ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n=== 2. COMPARACAO COM std::list ===" << std::endl;
	{
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << "Top (back): " << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << "Size: " << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n=== 3. COPIA, ATRIBUICAO E CONST_ITERATOR ===" << std::endl;
	{
		MutantStack<int> original;
		original.push(10);
		original.push(20);
		original.push(30);

		MutantStack<int> copy(original);
		MutantStack<int> assigned;
		assigned = original;

		// Modifica apenas a original para garantir copia independente
		original.pop();
		original.push(999);

		std::cout << "Original -> ";
		printConstStack(original);
		std::cout << "Copy     -> ";
		printConstStack(copy);
		std::cout << "Assigned -> ";
		printConstStack(assigned);
	}

	std::cout << "\n=== 4. ALGORITMOS STL (std::find) E std::string ===" << std::endl;
	{
		MutantStack<std::string> strStack;
		strStack.push("C++98");
		strStack.push("Templates");
		strStack.push("Iterators");
		strStack.push("Algorithms");

		MutantStack<std::string>::iterator found = std::find(strStack.begin(), strStack.end(), "Iterators");
		if (found != strStack.end())
			std::cout << "Encontrado na pilha: " << *found << std::endl;

	}

	return 0;
}