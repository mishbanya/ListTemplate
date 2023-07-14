#include <iostream>
#include <cmath>
using namespace std;
/*
����������� ������ ������, ���������� ��������� ����������, �������� � ������ ���������.
������ �������������� ���������� ����������.
����������� ������ ������ ���������.
�������� ������ �������������� ������� ��� ����������� � ����������� ��������.
*/

template <class T>
class TList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
public:
	class Iterator
	{
	public:
		typename TList<T>::Node* node;
		int index;
		Node* current;
		/*
		* ����������� �� ���������
		*/
		Iterator() {
			current = nullptr;
			node = NULL;
			index = -1;
		}
		/*
		* ����������� � �����������
		* @param node - ��������� �� ������ ������
		* @param index - ������ ����
		*/
		Iterator(typename TList<T>::Node* node, int index) {
			this->current = node;
			this->node = node;
			this->index = index;
		}
		/*
		* �������� ���������� ��������� �� 1
		*/
		Iterator operator++() {
			this->current = this->current->next;
			this->node = this->node->next;
			this->index++;
			return *this;
		}
		/*
		* �������� ���������� ��������� �� n
		*/
		Iterator operator++(int) {
			Iterator temp = *this;
			this->current = this->current->next;
			this->node = this->node->next;
			this->index++;
			return temp;
		}
		/*
		* �������� ���������� ��������� �� 1
		*/
		Iterator operator--() {
			this->current = this->current->prev;
			this->node = this->node->prev;
			this->index--;
			return *this;
		}
		/*
		* �������� ���������� ��������� �� n
		*/
		Iterator operator--(int) {
			Iterator temp = *this;
			this->current = this->current->prev;
			this->node = this->node->prev;
			this->index--;
			return temp;
		}
		/*
		* �������� ������������� ���������
		*/
		T& operator*() {
			return this->node->data;
		}
		/*
		* �������� ��������� ����������
		* @param it ������������ ��������
		*/
		bool operator==(const Iterator& it) {
			return this->node == it.node;
		}
		/*
		* �������� ����������� ����������
		* @param it ������������ ��������
		*/
		bool operator!=(const Iterator& it) {
			return this->node != it.node;
		}
	};
	int size;
	/*
	* @brief ����������� �� ���������
	*/
	TList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	/*
	* @brief ����������
	*/
	~TList() {
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	/*
	* @brief ���������� �������� � ����� ������
	* @param data - ����������� �������
	*/
	void push_back(T data) {
		if (head == NULL)
		{
			head = new Node;
			head->data = data;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
		}
		else
		{
			tail->next = new Node;
			tail->next->data = data;
			tail->next->next = NULL;
			tail->next->prev = tail;
			tail = tail->next;
		}
		size++;
	}
	/*
	* @brief ���������� �������� � ������ ������
	* @param data - ����������� �������
	*/
	void push_front(T data) {
		if (head == NULL)
		{
			head = new Node;
			head->data = data;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
		}
		else
		{
			head->prev = new Node;
			head->prev->data = data;
			head->prev->next = head;
			head->prev->prev = NULL;
			head = head->prev;
		}
		size++; {
		}
	}
	/*
	* @brief �������� �������� �� ����� ������
	*/
	void pop_back() {
		if (head == NULL)
		{
			return;
		}
		else if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			Node* current = this->head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->prev->next = NULL;
			tail = current->prev;
			delete current;
		}
		size--;
	}
	/*
	* @brief �������� �������� �� ������ ������
	*/
	void pop_front() {
		if (head == NULL)
		{
			return;
		}
		else if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
		size--; {
		}
	}
	/*
	* @brief �������� �-�� �� �������
	* @param index - ������ ���������� �-��
	*/
	void erase(Iterator it) {
		if (head == NULL)
		{
			return;
		}
		else if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			Node* current = this->head;
			while (current != it.current)
			{
				current = current->next;
			}
			if (current == head)
			{
				head = head->next;
				delete head->prev;
				head->prev = NULL;
			}
			else if (current == tail)
			{
				tail = tail->prev;
				delete tail->next;
				tail->next = NULL;
			}
			else
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
				delete current;
			}
		}
		size--; {
		}
	}
	/*
	* @brief ������� ������
	*/
	void clear() {
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		head = NULL;
		tail = NULL;
		size = 0; {
		}
	}
	/*
	* @brief ��������� ������� ������
	* @return ������ ������
	*/
	int GetSize() { return size; }
	/*
	* @brief �������� ������� � �-�� �� �������
	* @param index - ������ �-��
	* @return �-� �� �������
	*/
	T& operator[](const int index) {
		int counter = 0;
		Node* current = this->head;
		while (current != NULL)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->next;
			counter++;
		}
	}
	/*
	* @brief ����� ������ �� �����
	*/
	void print() {
		Node* current = this->head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl; {
		}
	}
	/*
	* @brief ��������� �������� �-���
	* @param begin - �������� �� ������ ��������� �-�
	* @param end - �������� �� �-�, ��������� �� ��������� ���������
	*/
	*/
	void eraseGroup(Iterator begin, Iterator end) {
		if (begin == end)
		{
			return;
		}
		else
		{
			Node* current = this->head;
			int counter = 0;
			while (current != NULL)
			{
				if (counter == begin.index)
				{
					break;
				}
				current = current->next;
				counter++;
			}
			while (current != NULL)
			{
				if (counter == end.index)
				{
					break;
				}
				Node* temp = current;
				current = current->next;
				delete temp;
				size--;
				counter++;
			}
		}
	}
	/*
	* @brief ���������� �-�� �� �������
	* @param index - ������ �-��
	* @param data - ����������� �-�
	*/
	void insert(Iterator it, T data) {
		if (it.index == 0)
		{
			push_front(data);
		}
		else
		{
			Node* current = this->head;
			int counter = 0;
			while (current != NULL)
			{
				if (counter == it.index)
				{
					Node* temp = new Node;
					temp->data = data;
					temp->next = current;
					temp->prev = current->prev;
					current->prev->next = temp;
					current->prev = temp;
					size++;
					break;
				}
				current = current->next;
				counter++;
			}
		}
	}
	/*
	* @brief ������ �-�� �� �������
	* @param index - ������ �-��
	* @param data - ����� �-�
	*/
	void replace(Iterator it, T data) {
		Node* current = this->head;
		int counter = 0;
		while (current != NULL)
		{
			if (counter == it.index)
			{
				current->data = data;
				break;
			}
			current = current->next;
			counter++;
		}
	}
	/*
	* @brief ����� �-�� �� ��������
	* @param data - ������� �-�
	* @return �������� �� �-�
	*/
	Iterator find(T data) {
		Node* current = this->head;
		int counter = 0;
		while (current != NULL)
		{
			if (current->data == data)
			{
				return Iterator(current, counter);
			}
			current = current->next;
			counter++;
		}
		return Iterator(NULL, -1);
	}
	/*
	* @brief ����������� �������
	* @param list - ������, ������� ����� ��������
	*/
	void merge(TList<T>& list) {
		if (list.head == NULL)
		{
			return;
		}
		else
		{
			if (this->head == NULL)
			{
				this->head = list.head;
				this->tail = list.tail;
				this->size = list.size;
			}
			else
			{
				this->tail->next = list.head;
				list.head->prev = this->tail;
				this->tail = list.tail;
				this->size += list.size;
			}
			list.head = NULL;
			list.tail = NULL;
			list.size = 0;
		}
	}
	/*
	* @brief ����������� �������
	* @param list - ������, � ������� ����� ��������
	*/
	void intersection(TList<T>& list) {
		if (list.head == NULL)
		{
			return;
		}
		else
		{
			Node* current = this->head;
			while (current != NULL)
			{
				if (list.find(current->data).index == -1)
				{
					Node* temp = current;
					current = current->next;
					erase(Iterator(temp, 0));
				}
				else
				{
					current = current->next;
				}
			}
		}
	}
	/*
	* @brief �������� �� ������ ������
	*/
	Iterator begin() {
		return Iterator(head, 0);
	}
	/*
	* @brief �������� �� ����� ������
	*/
	Iterator end() {
		return Iterator(tail, size - 1);
	}
	/*
	* @brief �������� ������
	* @param out - ����� ������
	* @param list - ������
	*/
	friend ostream& operator<<(ostream& out, const TList<T>& list) {
		Node* current = list.head;
		while (current != NULL)
		{
			out << current->data << " ";
			current = current->next;
		}
		return out;
	}
};