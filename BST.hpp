#ifndef BST_HPP
#define BST_HPP

#include <memory>
#include <iostream>

/*
Program Header
Function Title: Binary Search Tree
Summary: This file contains several functions: Copy constructor, add, update, remove, at, operator[],
traverse, size, copyhelp, and isthere. Each function is crucial for the Binary Search Tree to work.
Inputs: None
Outputs: None
**********************
PSEUDOCODE
Begin
	Create an enum class called Direction so we know which way down the tree we are going
	COMPLEXITY COMMENT FOR BST FUNCITON: O(1)
	Create the Bst function
	COMPLEXITY COMMENT FOR THE COPY CONSTRUCTOR: O(n)
	Create the copy constructor
	Create a function called copyhelp to help with the copy constructor
	Define the add function to increase the size, add another node, and put it in the correct place
	COMPLEXITY COMMENT FOR ADD FUNCTION: O(n)
	COMPLEXITY COMMENT FOR THE UPDATE FUNCTION: O(n)
	Provide several checks for the update to happen if it can, and if it can, do it properly
	COMPLEXITY COMMENT FOR REMOVE FUNCTION: O(n)
	For the remove function, we have to find the proper value, remove it, then decrease the size of the tree
	Create a function called isThere to help several functions find specific values
	COMPLEXITY COMMENT FOR AT FUNCTION: O(n)
	Create at function to find values where we are at
	COMPLEXITY COMMENT FOR THE OPERATOR FUNCTION: O(n)
	Create operator function
	COMPLEXITY COMMENT FOR TRAVERSE FUNCTION: O(n)
	Create traverse function to properly direct through the binary tree
	COMPLEXITY COMMENT FOR SIZE FUNCTION: O(1)
	Create size function to return the size of the tree
	Create the private section of the class to keep track of several more variables
End
*/




//Create an enum class called Direction so we know which way down the tree we are going
enum class Direction
{
	LEFT,
	RIGHT
};

template <typename Key, typename Value>
class Bst
{
public:
//COMPLEXITY COMMENT FOR BST FUNCITON: O(1)
//Create the Bst function
	Bst()
	{
	}

//COMPLEXITY COMMENT FOR THE COPY CONSTRUCTOR: O(n)
//Create the copy constructor
	Bst(Bst const& bst)
	{
		copyhelp(bst);
		return;
	}

//Create a function called copyhelp to help with the copy constructor
	void copyhelp(Bst root)
	{
		if (root == nullptr)
		{
			return;
		}
		auto root_copy = std::make_shared<node<Key, Value>>(root->m_left, root->m_right, root->m_key, root->m_value);
		root_copy->m_left = copyhelp(root->m_left);
		root_copy->m_right = copyhelp(root->m_right);
		return;
	}

//Define the add function to increase the size, add another node, and put it in the correct place
//COMPLEXITY COMMENT FOR ADD FUNCTION: O(n)
	void add(Key const& key, Value const& value)
	{
		m_size++;
		if (m_head == nullptr)
		{
			m_head = std::make_shared<node<Key, Value>>(nullptr, nullptr, key, value);
		}
		else
		{
			auto current = m_head;
			newnode = std::make_shared<node<Key, Value>>(nullptr, nullptr, key, value);
			while (current->m_right != nullptr || current->m_left != nullptr)
			{
				if (key <= current->m_key && current->m_left != nullptr)
				{
					current = current->m_left;
				}
				else if (key > current->m_key && current->m_right != nullptr)
				{
					current = current->m_right;
				}
				else
				{
					break;
				}
			}
			if (key <= current->m_key)
			{
				current->m_left = newnode;
			}
			else
			{
				current->m_right = newnode;
			}
		}
	}

//COMPLEXITY COMMENT FOR THE UPDATE FUNCTION: O(n)
//Provide several checks for the update to happen if it can, and if it can, do it properly
	void update(Key const& key, Value const& value)
	{
		auto current = m_head;
		if (!isThere(key))
		{
			throw std::runtime_error("Error");
		}

		while (key != current->m_key)
		{
			if (key <= current->m_key)
			{
				current = current->m_left;
			}
			else if (key > current->m_key)
			{
				current = current->m_right;
			}
			else
			{
				throw std::invalid_argument("No valid argument");
			}
		}
		current->m_value = value;
		return;
	}

//COMPLEXITY COMMENT FOR REMOVE FUNCTION: O(n)
//For the remove function, we have to find the proper value, remove it, then decrease the size of the tree
	void remove(Key const& key)
	{
		auto current = m_head;
		auto saveprev = current;
		if (!isThere(key))
		{
			throw std::runtime_error("Error");
		}

		while (key != current->m_key)
		{
			if (key <= current->m_key)
			{
				saveprev = current;
				current = current->m_left;
			}
			else if (key > current->m_key)
			{
				saveprev = current;
				current = current->m_right;
			}
			else
			{
				throw std::runtime_error("Value does not exist");
			}
		}
		auto foundpointer = current;
		if (current->m_left != nullptr && current->m_right != nullptr)
		{
			current = current->m_left;
			while (current->m_right->m_right != nullptr)
			{
				current = current->m_right;
			}
			foundpointer->m_value = current->m_right->m_value;
			foundpointer->m_key = current->m_right->m_key;
			current->m_right = nullptr;
		}
		else if (current->m_left == nullptr && current->m_right != nullptr)
		{
			if (saveprev->m_left != nullptr)
			{
				if (saveprev->m_left->m_key == key)
				{
					saveprev->m_left = current->m_right;
				}
			}
			if (saveprev->m_right != nullptr)
			{
				if (saveprev->m_right->m_key == key)
				{
					saveprev->m_right = current->m_right;
				}
			}
		}
		else if (current->m_left != nullptr && current->m_right == nullptr)
		{
			if (saveprev->m_left != nullptr)
			{
				if (saveprev->m_left->m_key == key)
				{
					saveprev->m_left = current->m_left;
				}
			}
			else if (saveprev->m_right->m_key == key)
			{
				saveprev->m_right = current->m_left;
			}
		}
		else if (current->m_left == nullptr && current->m_right == nullptr)
		{
			if (saveprev->m_left->m_key == key)
			{
				saveprev->m_left = nullptr;
			}
			else
			{
				saveprev->m_right = nullptr;
			}
		}
		else
		{
			throw std::runtime_error("No value exists");
		}
		m_size--;
	}

//Create a function called isThere to help several functions find specific values
	bool isThere(Key const& key)
	{
		auto current = m_head;
		while (key != current->m_key)
		{
			if (key <= current->m_key && current->m_left != nullptr)
			{
				current = current->m_left;
			}
			else if (key > current->m_key && current->m_right != nullptr)
			{
				current = current->m_right;
			}
			else
			{
				return false;
			}
		}
		return true;
	}

//COMPLEXITY COMMENT FOR AT FUNCTION: O(n)
//Create at function to find values where we are at
	Value& at(Key const& key)
	{
		auto current = m_head;
		while (key != current->m_key)
		{
			if (key <= current->m_key && current->m_left != nullptr)
			{
				current = current->m_left;
			}
			else if (key > current->m_key && current->m_right != nullptr)
			{
				current = current->m_right;
			}
			else
			{
				throw std::runtime_error("Value cannot be found");
			}
		}
		return current->m_value;
	}

//COMPLEXITY COMMENT FOR THE OPERATOR FUNCTION: O(n)
//Create operator function
	Value& operator[](Key const& key)
	{
		auto current = m_head;
		while (key != current->m_key)
		{
			if (key <= current->m_key && current->m_left != nullptr)
			{
				current = current->m_left;
			}
			else if (key > current->m_key && current->m_right != nullptr)
			{
				current = current->m_right;
			}
			else
			{
				throw std::runtime_error("Value cannot be found");
			}
		}
		return current->m_value;
	}

//COMPLEXITY COMMENT FOR TRAVERSE FUNCTION: O(n)
//Create traverse function to properly direct through the binary tree
	Value traverse(std::vector<Direction> const& path)
	{
		auto current = m_head;
		for (int i = 0; i< int(path.size()); i++)
		{
			if (path[i] == Direction::LEFT && current->m_left != nullptr)
			{
				current = current->m_left;
			}
			else if (path[i] == Direction::RIGHT && current->m_right != nullptr)
			{
				current = current->m_right;
			}
			else
			{
				throw std::runtime_error("Invalid Path");
			}
		}
		return current->m_value;
	}

//COMPLEXITY COMMENT FOR SIZE FUNCTION: O(1)
//Create size function to return the size of the tree
	size_t size()
	{
		return m_size;
	}

//Create the private section of the class to keep track of several more variables
private:
	template <typename TKey, typename TValue>
	struct node
	{
		node<TKey, TValue>(std::shared_ptr<node<TKey, TValue>> left, std::shared_ptr<node<TKey, TValue >> right, TKey key, TValue value) :
			m_left(left), m_key(key), m_value(value), m_right(right)
		{}
		std::shared_ptr<node<TKey, TValue >> m_left;
		TKey m_key;
		TValue m_value;
		std::shared_ptr<node<TKey, TValue>> m_right;
	};

	size_t m_size = 0;
	std::shared_ptr<node<Key, Value>> m_head;
	std::shared_ptr<node<Key, Value>> newnode;
};

#endif